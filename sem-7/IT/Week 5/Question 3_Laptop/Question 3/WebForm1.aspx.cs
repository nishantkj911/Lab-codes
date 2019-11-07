using System;

namespace Question_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                NameHiddenField.Value = "hbhfkjlnkajk";
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            NameHiddenField.Value = TextBox1.Text;
            Response.Redirect("WebForm2.aspx");
        }
    }
}