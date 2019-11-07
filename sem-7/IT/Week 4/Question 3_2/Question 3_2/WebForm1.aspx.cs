using System;
using System.Web.UI;
using System.Drawing;
using System.Web.UI.WebControls;

namespace Question_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                FontFamily[] ff = FontFamily.Families;
                foreach (FontFamily item in ff)
                {
                    fontStyleDropDownList.Items.Add(new ListItem(item.Name));
                }

                for (int i = 1; i <= 36; i++)
                {
                    fontSizeDropDownList.Items.Add(new ListItem((i * 2).ToString()));
                }
                Panel1.Visible = false;
            }


        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Color bgColor = Color.FromArgb(int.Parse(TextBox2.Text), int.Parse(TextBox3.Text), int.Parse(TextBox4.Text));
            string fontType = fontStyleDropDownList.SelectedValue;
            int fontSize = int.Parse(fontSizeDropDownList.SelectedValue);
            string inputMessage = TextBox1.Text;

            Panel1.Visible = true;
            Panel1.BackColor = bgColor;

            // Not working
            FileUpload1.PostedFile.SaveAs(Server.MapPath("~/" + FileUpload1.PostedFile.FileName));
            Panel1.BackImageUrl = Server.MapPath("~/" + FileUpload1.PostedFile.FileName);

            div2Para.InnerHtml = inputMessage;
            div2Para.Style.Add(HtmlTextWriterStyle.FontFamily, fontType);
            div2Para.Style.Add(HtmlTextWriterStyle.FontSize, fontSize.ToString() + "pt");
        }
    }
}