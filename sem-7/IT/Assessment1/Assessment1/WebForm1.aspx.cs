using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Drawing;

namespace Assessment1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                DropDownList1.Items.Add(new ListItem("Dotted"));
                DropDownList1.Items.Add(new ListItem("Dashed"));
                DropDownList1.Items.Add(new ListItem("Solid"));
                DropDownList1.Items.Add(new ListItem("Double"));
                DropDownList1.Items.Add(new ListItem("Groove"));
                DropDownList1.Items.Add(new ListItem("Inset"));
                DropDownList1.Items.Add(new ListItem("Outset"));
                DropDownList1.Items.Add(new ListItem("Ridge"));
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int age = int.Parse(TextBox1.Text);
            if (age < 1 || age > 150)
            {
                TextBox1.BackColor = Color.Red;
                Button1.BackColor = Color.Gray;
                DropDownList1.BackColor = Color.White;
                formDiv.Style.Remove(HtmlTextWriterStyle.BorderStyle);
            }
            else
            {
                TextBox1.BackColor = DropDownList1.BackColor = Button1.BackColor = Color.Cyan;

                switch (DropDownList1.SelectedValue) {
                    case "Dotted":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Dotted.ToString());
                        break;
                    case "Dashed":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Dashed.ToString());
                        break;
                    case "Solid":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Solid.ToString());
                        break;
                    case "Groove":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Groove.ToString());
                        break;
                    case "Inset":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Inset.ToString());
                        break;
                    case "Outset":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Outset.ToString());
                        break;
                    case "Ridge":
                        formDiv.Style.Add(HtmlTextWriterStyle.BorderStyle, BorderStyle.Ridge.ToString());
                        break;
                }
            }
        }
    }
}