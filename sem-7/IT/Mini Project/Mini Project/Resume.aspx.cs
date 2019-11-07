using System;
using System.Collections.Generic;
using System.Linq;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;

namespace Mini_Project
{
    public partial class Resume : System.Web.UI.Page
    {
        string oldSkill = null;
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {
            SqlDataSource1.InsertCommand = "INSERT INTO Skills ([Regno], [Skill]) VALUES (@Regno, @Skill)";
            SqlDataSource1.InsertParameters.Add("Skill", (SkillsGridView.FooterRow.FindControl("TextBox2") as TextBox).Text);
            SqlDataSource1.InsertParameters.Add("RegNo", Session["Regno"].ToString());
            SqlDataSource1.Insert();
        }
        protected void InsertCC_Click(object sender, EventArgs e)
        {
            SqlDataSource2.InsertParameters.Add("Author", (CourseCertificationGridView.FooterRow.FindControl("InsertCCAuthorTB") as TextBox).Text);
            SqlDataSource2.InsertParameters.Add("Title", (CourseCertificationGridView.FooterRow.FindControl("InsertCCTitleTB") as TextBox).Text);
            SqlDataSource2.InsertParameters.Add("RegNo", Session["Regno"].ToString());
            SqlDataSource2.Insert();
        }

        protected void SkillsGridView_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            SqlDataSource1.UpdateParameters.Add("OldSkill", oldSkill);
        }

        protected void SkillsGridView_RowEditing(object sender, GridViewEditEventArgs e)
        {
            oldSkill = (SkillsGridView.Rows[e.NewEditIndex].FindControl("Label1") as Label).Text;
        }

        protected void SkillsGridView_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            SqlDataSource1.DeleteCommand = "DELETE FROM Skills WHERE ([Regno] = @Regno AND [Skill] = @s)";
            SqlDataSource1.DeleteParameters.Add("Regno", Session["Regno"].ToString());
            Label lbl1 = (SkillsGridView.Rows[e.RowIndex].FindControl("Label1") as Label);
            SqlDataSource1.DeleteParameters.Add("s", DbType.String, lbl1.Text);

        }

        protected void CourseCertificationGridView_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
        }

        protected void ProfessionalExperienceGridView_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            SqlDataSource3.DeleteParameters.Add("Regno", TypeCode.Int32, Session["Regno"].ToString());
        }

        protected void InsertPELB_Click(object sender, EventArgs e)
        {
            SqlDataSource3.InsertParameters.Add("JobTitle", (ProfessionalExperienceGridView.FooterRow.FindControl("InsertPEJTTB") as TextBox).Text);
            SqlDataSource3.InsertParameters.Add("Job_Description", (ProfessionalExperienceGridView.FooterRow.FindControl("InsertPEJDTB") as TextBox).Text);
            SqlDataSource3.InsertParameters.Add("RegNo", Session["Regno"].ToString());
            SqlDataSource3.Insert();
        }

        protected void InsertRecLB_Click(object sender, EventArgs e)
        {

            SqlDataSource4.InsertParameters.Add("TeacherName", (RecommendationsGridView.FooterRow.FindControl("InsertRecTNTB") as TextBox).Text);
            SqlDataSource4.InsertParameters.Add("RegNo", Session["Regno"].ToString());
            SqlDataSource4.InsertParameters.Add("Remarks", (RecommendationsGridView.FooterRow.FindControl("InsertRecRemTB") as TextBox).Text);
            SqlDataSource4.Insert();
        }
    }
}