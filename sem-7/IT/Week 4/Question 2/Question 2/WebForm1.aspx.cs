using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs ev)
        {
            Image1.Visible = false;
        }

        protected void Button1_Click(object sender, EventArgs ev)
        {
            Image1.Visible = true;
            Image1.ImageUrl = (DropDownList1.SelectedIndex + 1).ToString() + ".jpg";
        }

        protected void eligibilityCheckButton_Click(object sender, EventArgs ev)
        {
            string dojString = DateOfJoiningTB.Text;
            DateTime doj;
            try
            {
                doj = DateTime.Parse(dojString);
            }
            catch (FormatException e)
            {
                Label1.Style.Add(HtmlTextWriterStyle.BackgroundColor, "red");
                Label1.Text = "Please Enter Properly formatted date";
                return;
            }

            if ((DateTime.Now.Subtract(doj).Days / 365.25) >= 5)
            {
                Label1.Text = "YES!!";
            }
            else
            {
                Label1.Text = "NO!";
            }
        }
    }
}