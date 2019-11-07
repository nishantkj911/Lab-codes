using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Assessment2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
            SqlCommand command = new SqlCommand("INSERT into employees (Name, Phone, Place) VALUES (@n, @p, @pl)", conn);
            command.Parameters.AddWithValue("@n", TextBox1.Text);
            command.Parameters.AddWithValue("@p", TextBox2.Text);
            command.Parameters.AddWithValue("@pl", TextBox3.Text);
            conn.Open();
            SqlDataReader dr = command.ExecuteReader();
            conn.Close();

            para.InnerHtml = "Updated!!";
            Response.Redirect("Webform2.aspx?Name=" + Server.UrlEncode(TextBox1.Text));
        }
    }
}