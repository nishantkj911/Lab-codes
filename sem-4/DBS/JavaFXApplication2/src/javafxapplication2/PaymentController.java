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
import java.sql.SQLIntegrityConstraintViolationException;
import java.sql.Statement;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
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
public class PaymentController implements Initializable
{

    @FXML
    private ChoiceBox<Integer> cb1;
    @FXML
    private TextArea jta1;
    @FXML
    private ChoiceBox<String> cb2;

    /**
     * Initializes the controller class.
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

        cb2.getItems().addAll("Net Banking", "Demand Draft", "Cash", "Debit/Credit Card");
    }

    @FXML
    private void pay(ActionEvent event)
    {
        Integer bookingID = cb1.getValue();
        if (bookingID == null)
        {
            JOptionPane.showMessageDialog(null, "Please select a booking id from the list",
                    "No BookingID selected", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String mode = cb2.getValue();
        if ("".equals(mode))
        {
            JOptionPane.showMessageDialog(null, "Please select a mode of payment from the list",
                    "No Mode-of-payment selected", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String query = "select * from  customer natural join booking natural join room where bookingID = ?";
        java.util.Date today = new java.util.Date();
        java.sql.Date arr = new java.sql.Date(today.getTime());
        java.sql.Date chk = new java.sql.Date(today.getTime());
        int roomNo = 0, ppn = 0;
        String fname = "", rType = "", custID = "";

        try
        {
            PreparedStatement ps = con.prepareStatement(query);
            ps.setInt(1, bookingID);
            ResultSet rs = ps.executeQuery();
            rs.next();

            arr = rs.getDate("arrival");
            chk = rs.getDate("checkout");
            roomNo = rs.getInt("roomNo");
            fname = rs.getString("fname");
            rType = rs.getString("roomtype");
            ppn = rs.getInt("pricepernight");
            custID = rs.getString("custID");
            

        } catch (SQLException ex)
        {
            Logger.getLogger(PaymentController.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }

        jta1.setText("Hey, Mr. " + fname + ".\nWe have initiated payment procedure "
                + "\nfor you booking of room " + roomNo + " \nfrom " + arr.toString()
                + " to " + chk.toString() + "."
                        + "\nIt is a " + rType);
        jta1.setEditable(false);
        
        long a = chk.getTime() - arr.getTime();
        long days = a / (60 * 60 * 1000 * 24);

        long amt = days * ppn;
        JOptionPane.showConfirmDialog(null, "Your booking will cost you Rs. "
                + amt + "\nDo you wanna proceed with the payment procedure?",
                "Confirmation", JOptionPane.YES_NO_CANCEL_OPTION);
        
        if(JOptionPane.YES_OPTION == 0)
        {
            try
            {
                PreparedStatement ps = con.prepareStatement("insert into payments values (?, ?, ?, ?)");
                ps.setInt(1, bookingID);
                ps.setString(2, custID);
                ps.setDate(3, new java.sql.Date(today.getTime()));
                ps.setString(4, mode);
                
                ps.executeQuery();
            }catch (SQLIntegrityConstraintViolationException exc)
            {
                JOptionPane.showMessageDialog(null, "Payment has already been done for this booking", "Re-Payment??", JOptionPane.ERROR_MESSAGE);
                return;
            }catch (SQLException ex)
            {
                Logger.getLogger(PaymentController.class.getName()).log(Level.SEVERE, null, ex);
            } 
            
            JOptionPane.showMessageDialog(null, "Your payment has been processed", "Done!!", JOptionPane.INFORMATION_MESSAGE);
            Stage st = (Stage) cb1.getScene().getWindow();
            st.close();
        }
    }

}
