using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        List<String> directories;
        List<String> folders;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                directories = new List<String>(Directory.GetLogicalDrives());
                DropDownList1.DataSource = directories;
                DataBind();

                ListBox1.DataSource = folders;
            }
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                folders = new List<string>(Directory.GetDirectories(DropDownList1.SelectedValue));
            }
            catch (System.IO.IOException exc)
            {
                Response.Write(HtmlTextWriterTag.Script + "alert(" + exc.Message + ")" + HtmlTextWriterTag.Script);
            }
            ListBox1.DataSource = folders;
            ListBox1.DataBind();
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Directory.Delete(ListBox1.SelectedValue);
            try
            {
                folders = new List<string>(Directory.GetDirectories(DropDownList1.SelectedValue));
            }
            catch (System.IO.IOException exc)
            {
                Response.Write(HtmlTextWriterTag.Script + "alert(" + exc.Message + ")" + HtmlTextWriterTag.Script);
            }
            ListBox1.DataSource = folders;
            ListBox1.DataBind();
        }
    }
}