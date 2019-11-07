using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                for (int i = 1; i <= 20; i++)
                {
                    DropDownList1.Items.Add(i.ToString());
                }

                if (Request.Cookies["Name"] != null)
                {
                    TextBox1.Text = Request.Cookies["Name"].Value;
                    TextBox2.Text = Request.Cookies["ProductName"].Value;
                    DropDownList1.SelectedIndex = int.Parse(Request.Cookies["Quantity"].Value);

                    para.InnerHtml = "Welcome Back, " + Request.Cookies["Name"].Value + "! Your Shopping cart has been restored.";
                }
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            HttpCookie nameCookie = new HttpCookie("Name", TextBox1.Text);
            nameCookie.Expires = DateTime.Now.AddHours(2);
            Response.Cookies.Add(nameCookie);

            HttpCookie productNameCookie = new HttpCookie("ProductName", TextBox2.Text);
            productNameCookie.Expires = DateTime.Now.AddHours(2);
            Response.Cookies.Add(productNameCookie);

            HttpCookie quantityCookie = new HttpCookie("Quantity", DropDownList1.SelectedIndex.ToString());
            quantityCookie.Expires = DateTime.Now.AddHours(2);
            Response.Cookies.Add(quantityCookie);

            para.InnerHtml = "Cookie Updated!!";
        }

    }
}