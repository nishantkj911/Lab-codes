using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using System.Web.UI.WebControls;

namespace DataBindingExample
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected string ExampleString = "";
        Dictionary<Int32, int> dict = new Dictionary<int, int>();
        List<String> list = new List<String>();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                dict.Add(10, 1);
                dict.Add(20, 2);
                dict.Add(30, 3);
                dict.Add(40, 4);
                dict.Add(60, 5);
                dict.Add(70, 6);
                dict.Add(80, 7);
                dict.Add(90, 9);

                
                
                CheckBoxList1.DataSource = list;
                DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            ExampleString = "This is secondary text";
            DataBind();
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["conn"].ConnectionString);
            SqlCommand command = new SqlCommand("Select * from staff", conn);
            SqlDataAdapter adapter = new SqlDataAdapter(command);
            DataSet ds = new DataSet();
            adapter.Fill(ds, "staff");



            GridView1.DataSource = ds;
            GridView1.DataBind();
        }
    }
}