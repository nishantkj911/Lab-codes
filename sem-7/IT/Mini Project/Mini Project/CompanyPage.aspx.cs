using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Configuration;

namespace Mini_Project
{
    public partial class CompanyPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
            }
        }

        protected void RegisterButton_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["MiniProjectConnectionString"].ConnectionString);
            SqlCommand comm = new SqlCommand("INSERT INTO [RegisteredCompanies] (Regno, Company) VALUES (@Regno, @company)", conn);

            comm.Parameters.AddWithValue("@Regno", Session["Regno"]);
            comm.Parameters.AddWithValue("@company", DetailsView1.Rows[0].Cells[1].Text);

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();

            Response.Write("<script>alert('Registered Successfully')</script>");
        }
    }
}