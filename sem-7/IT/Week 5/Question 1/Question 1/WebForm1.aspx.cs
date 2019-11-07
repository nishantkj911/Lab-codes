using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string url = "WebForm2.aspx?" + "carm=" + Server.UrlEncode(carManufacturer.SelectedValue) + "&" +
                                            "model=" + Server.UrlEncode(modelNameTB.Text);
            Response.Redirect(url);
        }
    }
}