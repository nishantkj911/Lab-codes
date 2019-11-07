using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int n;
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString))
            {
                using (SqlCommand command = new SqlCommand("UPDATE Items SET price=@price WHERE flavour=@f", conn))
                {
                    command.Parameters.AddWithValue("@price", TextBox1.Text);
                    command.Parameters.AddWithValue("@f", DropDownList1.SelectedValue);
                    conn.Open();
                    n = command.ExecuteNonQuery();
                }
                conn.Close();
            }

            Response.Write("<script>alert('Successfully updated. " + n.ToString() + " rows affected.')</script>");
        }
    }
}