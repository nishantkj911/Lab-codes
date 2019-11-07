/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication2;

import java.net.URL;
import java.sql.*;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import static javafxapplication2.JavaFXApplication2.con;
import javax.swing.JOptionPane;

/**
 * FXML Controller class
 *
 * @author Mahe
 */
public class RegisterCustomerController implements Initializable
{

    @FXML
    private TextField jtf1;
    @FXML
    private TextField jtf2;
    @FXML
    private TextField jtf3;
    @FXML
    private TextArea jtf4;
    @FXML
    private Button jb1;
    @FXML
    private TextField jtf5;
    @FXML
    private TextField jtf6;
    private long phno = 1000000000;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb)
    {
        // TODO
    }

    @FXML
    private void initInsert(ActionEvent event)
    {

        String insSt = "insert into customer values (?, ?, ?, ?, ?, ?)";
        String custID = jtf1.getText();

        if ("".equals(custID))
        {
            String sel = "select * from customer order by custID desc";
            Statement st;
            try
            {
                st = con.createStatement();
                ResultSet rs = st.executeQuery(sel);

                rs.next();
                custID = rs.getObject(1).toString();
                custID = Integer.toString(Integer.parseInt(custID) + 1);

            } catch (SQLException ex)
            {
                Logger.getLogger(RegisterCustomerController.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else
        {
            String sel = "select * from customer where custID = ?";

            try
            {
                PreparedStatement ps = con.prepareStatement(sel);
                ps.setString(1, custID);
                ResultSet rs = ps.executeQuery();
                if (rs.next())
                {
                    int conf = JOptionPane.showConfirmDialog(null, "Customer ID conflict", "Your desired customer "
                            + "ID has already been taken. We shall auto-generate one for you. "
                            + "Shall we proceed?", JOptionPane.YES_NO_CANCEL_OPTION);
                    if (JOptionPane.NO_OPTION == conf)
                    {
                        JOptionPane.showMessageDialog(null, "Please re-do the registration again with another customer id");
                        Stage s = (Stage) jb1.getScene().getWindow();
                        s.close();
                        return;
                    }
                }
            } catch (SQLException ex)
            {
                Logger.getLogger(RegisterCustomerController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        try
        {
            PreparedStatement pst = con.prepareStatement(insSt);
            pst.setString(1, custID);
            if (jtf2.getText() == "")
            {
                JOptionPane.showMessageDialog(null, "Please enter a first name", "Insufficient Data", JOptionPane.ERROR_MESSAGE);
                return;
            }
            else 
            {
                pst.setString(2, jtf2.getText());
            }
            pst.setString(3, jtf3.getText());
            pst.setString(4, jtf4.getText());
            pst.setString(5, jtf5.getText());
            if (jtf6.getText().length() <= 10)
            {
                pst.setLong(6, Long.parseLong(jtf6.getText()));
            }
            else 
            {
                JOptionPane.showMessageDialog(null, "Please enter a proper ph# no.", "Insufficient/Improper Data", JOptionPane.ERROR_MESSAGE);
                return;
            }
            

            pst.executeUpdate();
        } catch (SQLException ex)
        {
            ex.printStackTrace();
        }

        JOptionPane.showMessageDialog(null, "Insert Complete", "Insertion Log", JOptionPane.INFORMATION_MESSAGE);
        Stage st = (Stage) jb1.getScene().getWindow();
        st.close();

    }

}
