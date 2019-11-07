using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Mini_Project
{
    public partial class RegisterPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void RegisterButton_Click(object sender, EventArgs e)
        {
            SqlDataSource1.InsertParameters.Add("Regno",System.Data.DbType.Int32, RegNoTB.Text);
            SqlDataSource1.InsertParameters.Add("FirstName", FirstNameTB.Text);
            SqlDataSource1.InsertParameters.Add("LastName", LastNameTB.Text);
            SqlDataSource1.InsertParameters.Add("MiddleName", MiddleNameTB.Text);
            SqlDataSource1.InsertParameters.Add("loginPassword", Password1TB.Text);
            SqlDataSource1.InsertParameters.Add("Branch", BranchDDL.SelectedValue);
            SqlDataSource1.InsertParameters.Add("DOB", System.Data.DbType.Date, DOBTB.Text);
            SqlDataSource1.Insert();

            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["MiniProjectConnectionString"].ConnectionString);
            SqlCommand comm = new SqlCommand("INSERT INTO AcademicInfo (Regno, CGPA) VALUES (@Regno, 0)", conn);
            comm.Parameters.AddWithValue("@Regno", RegNoTB.Text);

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();

            AddSkillsInfo();

            Response.Redirect("LoginPage.aspx");
        }

        private void AddSkillsInfo()
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["MiniProjectConnectionString"].ConnectionString);
            SqlCommand comm = new SqlCommand("INSERT INTO Skills (Regno, Skill) VALUES (@Regno, @s)", conn);
            comm.Parameters.AddWithValue("@Regno", RegNoTB.Text);
            comm.Parameters.AddWithValue("@s", " ");

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();

            comm = new SqlCommand("INSERT INTO CourseCertifications (Regno, Title) VALUES (@Regno, @t)", conn);
            comm.Parameters.AddWithValue("@Regno", RegNoTB.Text);
            comm.Parameters.AddWithValue("@t", " ");

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();

            comm = new SqlCommand("INSERT INTO ProfessionalExperience (Regno, JobTitle) VALUES (@Regno, @t)", conn);
            comm.Parameters.AddWithValue("@Regno", RegNoTB.Text);
            comm.Parameters.AddWithValue("@t", " ");

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();

            comm = new SqlCommand("INSERT INTO Recommendations (Regno, TeacherName) VALUES (@Regno, @t)", conn);
            comm.Parameters.AddWithValue("@Regno", RegNoTB.Text);
            comm.Parameters.AddWithValue("@t", " ");

            conn.Open();
            comm.ExecuteNonQuery();
            conn.Close();
        }
    }
}