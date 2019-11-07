using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SessionMgmnt
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //Response.Write(Request.Form["HiddenField1"]);
            para.InnerHtml = "The button in the previous page has been pressed ";
            para.InnerHtml += Request.Form["HiddenField1"] + " times.";
            //para.InnerHtml += ViewState["TextBox1"];
            //if (PreviousPage != null)
            //{
            //    para.InnerHtml += PreviousPage.Title;
            //}
            //else
            //{
            //    para.InnerHtml += "NOPE!";
            //}
        }
    }
}