using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_3
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Request.Cookies["ShoppingCart"] == null)
            {
                HttpCookie nameCookie = new HttpCookie("NameOfCustomer", Request.Form["NameHiddenField"]);
                HttpCookie cartCookie = new HttpCookie("ShoppingCart", "Something");
                Response.Cookies.Add(nameCookie);
                Response.Cookies.Add(cartCookie);
                FirstPara.InnerHtml += "Hello, " + Request.Form["NameHiddenField"] + "! Coming for the first time, eh!";
            }
            else
            {
                //HttpCookie cookie = Request.Cookies["ShoppingCart"];
                HttpCookie nameCookie = Request.Cookies["NameOfCustomer"];
                FirstPara.InnerHtml += "Hello, " + nameCookie.Value + "! Welcome back!";
            }

        }
    }
}