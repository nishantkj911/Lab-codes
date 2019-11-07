using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace W8_Q4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void company_TextChanged(object sender, EventArgs e)
        {


        }

        protected void Give_Click(object sender, EventArgs e)
        {
            string str = ConfigurationManager.ConnectionStrings["conStr"].ConnectionString;
           
            SqlConnection con = new SqlConnection(str);
            SqlCommand comm = new SqlCommand("select city, person_name from lives, works  where company-name = @company and person-name=person_name", con);
            comm.Parameters.AddWithValue("@company", TextBox1.Text);

            try
            {
                con.Open();
                SqlDataReader re = comm.ExecuteReader();
                while (re.Read())
                    Label1.Text = "Name:" + re["Person_Name"] + " City:" + re["City"] + "<br/>";
            }
            catch (Exception ex) { }
            finally { con.Close(); }
        }

        protected void Insert_Click(object sender, EventArgs e)
        {
            string str = ConfigurationManager.ConnectionStrings["conStr"].ConnectionString;
            SqlConnection con = new SqlConnection(str);
            SqlCommand comm = new SqlCommand("insert into works(Person-name,company-name,salary) values(@p,@c,@s)", con);
            comm.Parameters.AddWithValue("@p", name.Text);
            comm.Parameters.AddWithValue("@c", company.Text);
            comm.Parameters.AddWithValue("@s", salary.Text);
            try
            {
                con.Open();

                comm.ExecuteNonQuery();
                Label1.Text = "inserted successfully";
            }



            catch (Exception ex) { Console.WriteLine("error:" + ex.Message); }


            finally { con.Close(); }



        }
    }
}