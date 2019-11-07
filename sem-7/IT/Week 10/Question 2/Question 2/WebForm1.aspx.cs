using System;
using System.Collections;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void GridView1_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            try
            {
                //SqlDataSource1.UpdateCommand = "update authors set last_name=@ln where id=@id";
                SqlDataSource1.UpdateCommand = "UPDATE Authors SET Last_Name=@ln, Copies_Sold=@Copies_Sold WHERE Id=@Id";
                SqlDataSource1.UpdateParameters.Add("ln", (GridView1.Rows[e.RowIndex].FindControl("TextBox1") as TextBox).Text);
                SqlDataSource1.UpdateParameters.Add(new Parameter("Id"));
                SqlDataSource1.UpdateParameters.Add(new Parameter("Copies_Sold"));
                //SqlDataSource1.Update();
            }
            catch (Exception exc)
            {
                Label3.Text += exc.Message;
                Label3.Text += exc.StackTrace;
            }
        }
    }
}