using System;
using System.Collections.Generic;
using System.Linq;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;

namespace Question_1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Label1.Visible = false;
            if (!IsPostBack)
            {
                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
                SqlCommand command = new SqlCommand("Select StaffID from Staff", conn);
                SqlDataAdapter da = new SqlDataAdapter(command);

                // either of these can be used. Use of DataSet is redundant for one table
                //DataSet ds = new DataSet();
                //da.Fill(ds, "Staff");
                //DataTable dt = ds.Tables["Staff"];

                DataTable dt = new DataTable();
                da.Fill(dt);
                foreach (DataRow row in dt.Select())
                {
                    DropDownList1.Items.Add(row.Field<Int32>("StaffID").ToString());
                }
            }
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
            SqlCommand comm = new SqlCommand("Select * from Staff where StaffID=@stId", conn);
            comm.Parameters.AddWithValue("@stId", DropDownList1.SelectedValue);
            SqlDataAdapter da = new SqlDataAdapter(comm);
            DataTable dt = new DataTable();
            da.Fill(dt);

            Label1.Text = "Hello! " + dt.Rows[0].Field<String>("FirstName") + " " + dt.Rows[0].Field<String>("LastName") + "    City: " + 
                dt.Rows[0].Field<String>("City");
            Label1.Visible = true;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
            SqlCommand comm = new SqlCommand("Select * from Staff where StaffID=@stId", conn);
            comm.Parameters.AddWithValue("@stId", DropDownList1.SelectedValue);
            SqlDataAdapter da = new SqlDataAdapter(comm);
            SqlCommandBuilder commandBuilder = new SqlCommandBuilder(da);

            
            DataTable dt = new DataTable();
            da.Fill(dt);

            foreach (DataRow row in dt.Rows)
            {
                row["City"] = ListBox1.SelectedValue;
            }

            da.UpdateCommand = commandBuilder.GetUpdateCommand();
            da.Update(dt);

            Response.Write("<script>alert('Updated Successfully!!')</script>");
        }
    }
}