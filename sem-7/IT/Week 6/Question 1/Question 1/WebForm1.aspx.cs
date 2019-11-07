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
            if(!IsPostBack)
            {
                for (int i = 0; i < 10; i++)
                {
                    DropDownList1.Items.Add("Name " + (i + 1).ToString());
                }
            }

            para.InnerHtml = "";
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            if (CustomValidator1.IsValid)
                para.InnerHtml = "Successfully Submitted!!";
        }

        protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
        {
            if (args.Value.Length != 10)
            {
                args.IsValid = false;
            }
            else
            {
                args.IsValid = true;
            }
        }
    }
}