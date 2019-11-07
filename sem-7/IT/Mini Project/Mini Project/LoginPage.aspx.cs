using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;
using System.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Mini_Project
{
    public partial class LoginPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void LoginButton_Click(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["MiniProjectConnectionString"].ConnectionString))
            {
                using (SqlCommand comm = new SqlCommand("SELECT Regno, loginPassword FROM Students WHERE Regno=@regno AND loginPassword=@pass", conn))
                {
                    comm.Parameters.AddWithValue("@regno", (RegNoTB).Text);
                    comm.Parameters.AddWithValue("@pass", (PasswordTB).Text);

                    conn.Open();
                    SqlDataReader dr = comm.ExecuteReader();
                    if (dr.HasRows)
                    {
                        dr.Read();
                        Session["Regno"] = (Int32) dr["Regno"];
                        conn.Close();
                        Session["UpdateAcademicInfo"] = false;
                        Response.Redirect("StudentProfile.aspx");
                    }
                    else
                    {
                        Response.Write("<script>alert('Invalid username or password')</script>");
                    }
                }
            }
        }

        protected void RegisterButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("RegisterPage.aspx");
        }
    }
}