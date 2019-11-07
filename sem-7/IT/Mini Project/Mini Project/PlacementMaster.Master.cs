using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Mini_Project
{
    public partial class PlacementMaster : System.Web.UI.MasterPage
    {
        List<string> phNos;
        protected void Page_Init(object sender, EventArgs e)
        {
            
            if(!IsPostBack)
            {
                phNos = new List<string>
                {
                    "+91-9089090234",
                    "+91-9089090235",
                    "+91-9089090236",
                    "+91-9089090237",
                    "+91-9089090238"
                };

                ContactsLabel.Text = phNos[0];
                for (int i=1; i<phNos.Count; i++)
                {
                    ContactsLabel.Text += ", " + phNos[i];
                }
            }
        }

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void AcademicInfo_Click(object sender, EventArgs e)
        {
            Response.Redirect("Academics.aspx");
        }

        protected void ResumeLB_Click(object sender, EventArgs e)
        {
            Response.Redirect("Resume.aspx");
        }

        protected void CompaniesLB_Click(object sender, EventArgs e)
        {
            Response.Redirect("EventSchedule.aspx");
        }
        protected void StudentProfile_Click(object sender, EventArgs e)
        {
            Response.Redirect("StudentProfile.aspx");
        }
    }
}