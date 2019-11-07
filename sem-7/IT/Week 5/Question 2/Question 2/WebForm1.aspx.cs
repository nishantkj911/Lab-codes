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
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Session.Add("name", nameTB.Text);
            Session.Add("rollno", rollNoTB.Text);
            Session.Add("subject", DropDownList1.SelectedValue);
            Response.Redirect("WebForm2.aspx");
        }
    }
}