/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication2;

import java.net.URL;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;
import static javafxapplication2.JavaFXApplication2.con;
import javax.swing.JOptionPane;

/**
 * FXML Controller class
 *
 * @author Nishant
 */
public class CancellationController implements Initializable
{

    @FXML
    private ChoiceBox<Integer> cb1;
    @FXML
    private TextArea jta1;

    /**
     * Initializes the controller class.
     *
     * @param url
     * @param rb
     */
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        String query = "select BookingID from Booking";
        try
        {
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery(query);

            if (!rs.next())
            {
                JOptionPane.showMessageDialog(null, st, query, 0);
            } else
            {
                do
                {
                    cb1.getItems().add(rs.getInt(1));
                } while (rs.next());
            }
        } catch (SQLException ex)
        {
            Logger.getLogger(PaymentController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @FXML
    private void cancel(ActionEvent event) throws SQLException
    {
        Integer bookingID = cb1.getValue();
        if (bookingID == null)
        {
            JOptionPane.showMessageDialog(null, "Please select a booking id from the list",
                    "No BookingID selected", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String query = "select * from  customer natural join booking natural join room where bookingID = ?";
        String fname = "", rType = "";
        Integer roomNo = 0;
        try
        {
            PreparedStatement ps = con.prepareStatement(query);
            ps.setInt(1, bookingID);
            ResultSet rs = ps.executeQuery();
            rs.next();

            fname = rs.getString("fname");
            rType = rs.getString("roomType");
            roomNo = rs.getInt("roomNo");

        } catch (SQLException ex)
        {
            ex.printStackTrace();
        }

        jta1.setText("Hey, Mr. " + fname + ". Your booking for " + rType + " room, "
                + "is about to be cancelled.");

        int conf = JOptionPane.showConfirmDialog(null, "Are you sure you want to proceed to cancel",
                "Really?", JOptionPane.YES_NO_CANCEL_OPTION);

        
        if (conf == JOptionPane.YES_OPTION)
        {
            checkPaymentEntry(bookingID);
            con.createStatement().executeUpdate("delete from booking where bookingid = " + bookingID);
        }
        else 
        {
            JOptionPane.showMessageDialog(null, "Okay, Your booking is not cancelled");
        }
        JOptionPane.showMessageDialog(null, "Your booking has been cancelled!!", "It is Done!!", JOptionPane.INFORMATION_MESSAGE);
        Stage st = (Stage) cb1.getScene().getWindow();
        st.close();
    }

    private void checkPaymentEntry(int bookingID)
    {
        String payCheck = "select * from booking where bookingId = " + bookingID;

        try
        {
            ResultSet rs = con.createStatement().executeQuery(payCheck);

            if (rs.next())
            {

                int roomNo = rs.getInt("roomno");
                con.createStatement().executeUpdate("update room set availability = 'Yes' where roomno = " + roomNo);

            }
        } catch (SQLException ex)
        {
            Logger.getLogger(CancellationController.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
