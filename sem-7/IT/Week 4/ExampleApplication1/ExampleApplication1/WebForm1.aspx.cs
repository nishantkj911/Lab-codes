using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ExampleApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                DropDownList1.Items.Add(new ListItem("a", "0.02"));
                if (this.Request == null)
                    myPara.InnerHtml += "Yes, it is";
                else
                {
                    myPara.InnerHtml += Request.QueryString;
                }

            }

            someDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Dashed.ToString());
            someDiv.Style.Remove(HtmlTextWriterStyle.BorderStyle);

        }

        protected void Submit_Click(object sender, EventArgs e)
        {
            myPara.InnerHtml = "Submitted!!";
            myPara.InnerHtml += DropDownList1.SelectedItem.Value + " " + DropDownList1.SelectedItem.Text;
        }

        protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}