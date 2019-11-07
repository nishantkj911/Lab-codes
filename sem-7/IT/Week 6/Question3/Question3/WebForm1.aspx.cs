using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question3
{
    public partial class WebForm1 : System.Web.UI.Page
    {

        protected void Page_PreInit(object sender, EventArgs e)
        {
            switch (Request.QueryString["t"])
            {
                case "SkinA":
                    Theme = "SkinA";
                    break;
                case "SkinB":
                    Theme = "SkinB";
                    break;
                default:
                    Theme = null;
                    break;
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Server.Transfer(Request.FilePath + "?t=" + Server.UrlEncode(DropDownList1.SelectedValue));
        }
    }
}