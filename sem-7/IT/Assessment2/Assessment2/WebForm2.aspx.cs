using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Assessment2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Label1.Text = Request.QueryString["Name"] + " is successfully updated";
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Server.Transfer("~/WebForm1.aspx");
        }
    }
}