using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
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

                for (int i = 1; i < 36; i++)
                {
                    fontSizeDropDownList.Items.Add(new ListItem((i * 2).ToString()));
                }
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {

        }
    }
}