using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Mini_Project
{
    public partial class Academics : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                if ((bool) Session["UpdateAcademicInfo"])
                {
                }
                else
                {
                    GridView1.ShowFooter = false;
                    headerText.InnerHtml = Session["Regno"].ToString();
                }
            }
            catch (NullReferenceException)
            {
                Response.Write("<script>alert('Please Sign in and then use menu!')</script>");
                Response.Redirect("LoginPage.aspx");
            }
        }

        protected void RegNoLinkButton_Click(object sender, EventArgs e)
        {
            SqlDataSource1.InsertParameters.Add("Semester1GPA", (GridView1.FooterRow.FindControl("InsertSem1TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester2GPA", (GridView1.FooterRow.FindControl("InsertSem2TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester3GPA", (GridView1.FooterRow.FindControl("InsertSem3TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester4GPA", (GridView1.FooterRow.FindControl("InsertSem4TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester5GPA", (GridView1.FooterRow.FindControl("InsertSem5TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester6GPA", (GridView1.FooterRow.FindControl("InsertSem6TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester7GPA", (GridView1.FooterRow.FindControl("InsertSem7TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("Semester8GPA", (GridView1.FooterRow.FindControl("InsertSem8TB") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("CGPA", (GridView1.FooterRow.FindControl("InsertCGPATB") as TextBox).Text);
            SqlDataSource1.Insert();

            //SqlDataSource1.SelectCommand = "SELECT* FROM[AcademicInfo] WHERE([Regno] = @Regno)";
            Session["UpdateAcademicInfo"] = false;
            Response.Redirect("StudentProfile.aspx");
        }
    }
}