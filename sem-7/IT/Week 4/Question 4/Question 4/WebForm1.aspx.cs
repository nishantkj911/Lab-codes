using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        int count = 0;
        string[] arr = new string[] { "W93BX", "JA3V8", "RBSKW", "HJ9PV", "TSMS9", "459CT", "R84CH" };
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                int num = new Random().Next(1, 8);
                Image1.ImageUrl = num.ToString() + ".png";
                Image1.Visible = true;

                HiddenField2.Value = num.ToString();
                HiddenField1.Value = count.ToString();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            count = int.Parse(HiddenField1.Value);
            count++;

            string captchaEntry = TextBox1.Text;
            if (captchaEntry.Equals(arr[int.Parse(HiddenField2.Value) - 1]))
            {
                para.InnerHtml = "Correct";
            }
            else
            {
                if (count > 3)
                {
                    TextBox1.Enabled = false;
                }
                para.InnerHtml = "Incorrect!!" + count.ToString();
            }

            HiddenField1.Value = count.ToString();
        }
    }
}