using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_1
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string manu = Request.QueryString["carM"];
            string model = Request.QueryString["model"];

            para.InnerHtml += "The " + manu + " has a great saver price in " + model + " model.";
        }
    }
}