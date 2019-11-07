using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Mini_Project
{
    public partial class StudentProfile : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["MiniProjectConnectionString"].ConnectionString))
                {
                    using (SqlCommand comm = new SqlCommand("SELECT * FROM AcademicInfo WHERE Regno=@regno", conn))
                    {
                        comm.Parameters.AddWithValue("@regno", (int)Session["Regno"]);
                        conn.Open();
                        SqlDataReader dr = comm.ExecuteReader();
                        if (!dr.HasRows)
                        {
                            Session["UpdateAcademicInfo"] = true;
                            Response.Redirect("Academics.aspx");
                        }
                        else
                        {
                            dr.Read();
                            para.InnerHtml += "Welcome " + dr["Regno"];
                        }
                        conn.Close();
                    }
                }
            }
        }
    }
}