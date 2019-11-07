/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication2;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.sql.*;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;
import static javafxapplication2.JavaFXApplication2.*;

/**
 *
 * @author Mahe
 */
public class FXMLDocumentController implements Initializable {

    private Label label;
    @FXML
    private Button jb1;
    private TextArea jta1;
    @FXML
    private Button jb13;
    @FXML
    private Button jb14;
    @FXML
    private Button jb15;

    private void handleButtonAction(ActionEvent event) {
        System.out.println("You clicked me!");
        label.setText("Hello World!");
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    private void selection(ActionEvent event) {

        try {
            String query = "select * from student";
            Statement st = con.createStatement();
            
            ResultSet rs = st.executeQuery(query);
            
            while(rs.next())
            {
                jta1.appendText(rs.getObject(1) + ", " + rs.getObject(2) + "\n");
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    @FXML
    private void regCust(ActionEvent event) {

        System.out.println("Hello");
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("RegisterCustomer.fxml"));
            Parent root1 = (Parent) fxmlLoader.load();
            Stage stage1 = new Stage();
            stage1.setScene(new Scene(root1));
            stage1.show();
        } catch (IOException e) {
            
            System.out.println("The register application is not able to load");
            e.printStackTrace();
        }
        System.out.println("World");
    }

    @FXML
    private void cancellation(ActionEvent event)
    {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("Cancellation.fxml"));
            Parent root1 = (Parent) fxmlLoader.load();
            Stage stage1 = new Stage();
            stage1.setScene(new Scene(root1));
            stage1.show();
        } catch (IOException e) {
            
            System.out.println("The cancellation application is not able to load");
            e.printStackTrace();
        }
    }

    @FXML
    private void makePayment(ActionEvent event)
    {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("Payment.fxml"));
            Parent root1 = (Parent) fxmlLoader.load();
            Stage stage1 = new Stage();
            stage1.setScene(new Scene(root1));
            stage1.show();
        } catch (IOException e) {
            
            System.out.println("The payment application is not able to load");
            e.printStackTrace();
        }
        
        
    }

    @FXML
    private void newBooking(ActionEvent event)
    {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("MakeBooking.fxml"));
            Parent root1 = (Parent) fxmlLoader.load();
            Stage stage1 = new Stage();
            stage1.setScene(new Scene(root1));
            stage1.show();
        } catch (IOException e) {
            
            System.out.println("The booking application is not able to load");
            e.printStackTrace();
        }
    }
}
