using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Response.Write("Student with name " + Session["name"] + ", roll no: " + Session["rollno"] 
                + " has selected the subject " + Session["subject"]);
        }
    }
}