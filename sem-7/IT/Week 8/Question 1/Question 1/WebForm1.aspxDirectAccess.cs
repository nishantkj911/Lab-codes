using System;
using System.Collections.Generic;
using System.Linq;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace Question_1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            para.InnerHtml = "";
            if (!IsPostBack)
            {
                try
                {
                    string connStr = ConfigurationManager.ConnectionStrings["conn"].ToString();
                    SqlConnection conn = new SqlConnection(connStr);
                    SqlCommand command = new SqlCommand("SELECT * from Staff", conn);
                    conn.Open();
                    SqlDataReader dataReader = command.ExecuteReader();
                    while (dataReader.Read())
                    {
                        DropDownList1.Items.Add(dataReader["StaffID"].ToString());
                    }
                    conn.Close();
                }
                catch (Exception ex)
                {
                    // Some exception throwing
                    Response.Write("<script>alert('Some Connection error');</script>");
                }
            }
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string connStr = ConfigurationManager.ConnectionStrings["conn"].ToString();
                SqlConnection conn = new SqlConnection(connStr);
                SqlCommand command = new SqlCommand("SELECT * from Staff where StaffID=@stID", conn);
                command.Parameters.AddWithValue("@stID", DropDownList1.SelectedValue);
                conn.Open();
                SqlDataReader dataReader = command.ExecuteReader();
                if (dataReader.Read())
                {
                    Label1.Text = "Name: " + dataReader["FirstName"] + " " + dataReader["LastName"] + "<br />" +
                        "Address: " + dataReader["DNo"] + " " + dataReader["Street"] + ", "+ dataReader["City"] + ", " + dataReader["State"] + "-" + dataReader["ZipCode"];
                }
                conn.Close();
            }
            catch (Exception ex)
            {
                // Some exception throwing
                Response.Write("<script>alert('Some Connection error');</script>");
            }
            Label1.Visible = true;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
            SqlCommand command = new SqlCommand("UPDATE Staff SET city=@newCity where StaffID=@stID", conn);
            command.Parameters.AddWithValue("@newCity", ListBox1.SelectedValue);
            command.Parameters.AddWithValue("@stID", DropDownList1.SelectedValue);
            conn.Open();
            command.ExecuteNonQuery();
            conn.Close();

            para.InnerHtml = "Successfully Updated!!";
        }
    }
}