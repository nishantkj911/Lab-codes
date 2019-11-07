/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication2;

import java.net.URL;
import java.sql.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import static javafxapplication2.JavaFXApplication2.con;
import javax.swing.JOptionPane;

/**
 * FXML Controller class
 *
 * @author Nishant
 */
public class MakeBookingController implements Initializable
{

    @FXML
    private ChoiceBox<String> cb1;
    @FXML
    private Button jb1;
    @FXML
    private TextField jtf1;
    @FXML
    private TextField jtf2;
    @FXML
    private TextField jtf21;
    @FXML
    private TextField jtf22;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        cb1.getItems().addAll("Deluxe", "Suite", "Honeymoon Suite");
    }

    @FXML
    private void startBooking(ActionEvent event) throws SQLException
    {
        String custIDquery = "select * from customer where custID = ?";
        PreparedStatement pst2 = con.prepareStatement(custIDquery);
        String custID = jtf2.getText();
        pst2.setString(1, custID);

        ResultSet rs = pst2.executeQuery();

        if (rs.next() == false)
        {
            JOptionPane.showMessageDialog(null, "The user doesn't exist in our database. "
                    + "Please register or try another user.", "Invalid Value Entry", JOptionPane.ERROR_MESSAGE);
            return;
        } else
        {
            String lname = rs.getString(3);
        }

        String query = "select * from room where roomtype = ? and availability = 'Yes' ";
        String roomType = cb1.getValue();
        if ("".equals(roomType))
        {
            JOptionPane.showMessageDialog(null,"Please select a room type", "Invalid Value Entry", JOptionPane.ERROR_MESSAGE);
            return;
        }

        PreparedStatement st = con.prepareStatement(query);
        st.setString(1, roomType);
        String str = jtf1.getText();

        if (!("".equals(str)))
        {
            try
            {
                int noOfPeople = Integer.parseInt(str);
            } catch (NumberFormatException ex)
            {
                JOptionPane.showMessageDialog(null, "Please Enter a number", "Invalid Value Entry", JOptionPane.ERROR_MESSAGE);
                return;
            }

            query = query + " and maxperson >= ?";
            st = con.prepareStatement(query);
            st.setString(1, roomType);
            st.setString(2, str);
        }
        ResultSet rs2 = st.executeQuery();

        if (rs2.next() == false)
        {
            JOptionPane.showMessageDialog(null, "There is no room available with the following specifications."
                    + "Please change some parameters and try again.", "Room availability problem", JOptionPane.ERROR_MESSAGE);
        } else
        {
            int roomNo = rs2.getInt(1);
            int conf = JOptionPane.showConfirmDialog(null,"You will be booking room no. " + roomNo 
                    + "\nAre you sure you want to proceed", "Room Confirmation", JOptionPane.YES_NO_CANCEL_OPTION);

            if (JOptionPane.YES_OPTION == conf)
            {
                try
                {
                    runInsertQuery(roomNo, custID);
                } catch (ParseException ex)
                {
                    JOptionPane.showMessageDialog(null,"Please make sure the"
                            + " date format is 'DD/MM/YYYY' ", "Invalid Date Format",JOptionPane.ERROR_MESSAGE);
                    return;
                }
                Stage s = (Stage) jb1.getScene().getWindow();
                s.close();
            }
            else
            {
                 JOptionPane.showMessageDialog(null, "Okay, the booking process has been terminated");
            }
        }
    }

    private void runInsertQuery(int roomNo, String custID) throws ParseException
    {
        int bookingID = (Integer.parseInt(custID) / 10) + (Integer.parseInt(custID) % 10 * 1000) + roomNo;
        String inDate = jtf21.getText();
        String outDate = jtf22.getText();
        SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");

        java.util.Date today = new java.util.Date();
        java.sql.Date nowSqlDate = new java.sql.Date(today.getTime());

        if ("".equals(inDate) && "".equals(outDate))
        {
            System.out.println("Minimal Booking");
            String query = "insert into booking (bookingid, roomno, custid, booktime) "
                    + "values (?, ?, ?, ?)";
            PreparedStatement p;

            try
            {
                p = con.prepareStatement(query);
                p.setInt(1, bookingID);
                p.setInt(2, roomNo);
                p.setString(3, custID);
                p.setDate(4, nowSqlDate);

                System.out.println(roomNo);
                int a = p.executeUpdate();
                
                return;
            } catch (SQLIntegrityConstraintViolationException ex)
            {
                JOptionPane.showMessageDialog(null,"You have already made a booking of the same sort", "How many times?", JOptionPane.ERROR_MESSAGE);
                return;
            } catch (SQLException e)
            {
                e.printStackTrace();
            }

        }
        String insQuery = "insert into booking values(?, ?, ?, ?, ?, ?)";

        try
        {
            java.util.Date inD = format.parse(inDate);
            java.sql.Date inSqlDate = new java.sql.Date(inD.getTime());

            java.util.Date outD = format.parse(outDate);
            java.sql.Date outSqlDate = new java.sql.Date(outD.getTime());

            PreparedStatement pst = con.prepareStatement(insQuery);
            pst.setInt(1, bookingID);
            pst.setDate(2, inSqlDate);
            pst.setDate(3, outSqlDate);
            pst.setInt(4, roomNo);
            pst.setString(5, custID);
            pst.setDate(6, nowSqlDate);

            pst.executeUpdate();
        } catch (SQLException ex)
        {
            Logger.getLogger(MakeBookingController.class.getName()).log(Level.SEVERE, null, ex);
        }

        Statement st;
        try
        {
            String upd = "update room set availability = 'No' where roomNo = " + roomNo;
            st = con.createStatement();

            st.execute(upd);

            JOptionPane.showMessageDialog(null, "Your booking has been confirmed");
        } catch (SQLException ex)
        {
            Logger.getLogger(MakeBookingController.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
