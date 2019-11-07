using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;

namespace Question_3
{
    public partial class HomePage : System.Web.UI.Page
    {
        Dictionary<String, String> dict;
        
        protected void Page_Load(object sender, EventArgs e) // can also be used  with Page_PreInit
        {
            if (!IsPostBack)
            {
                dict = new Dictionary<string, string>
                {
                    { "West Bengal", "WB" },
                    { "Maharashtra", "MAH" },
                    { "Karnataka", "KTK" },
                    { "Andhra Pradesh", "AP" },
                    { "Delhi", "DEL" }
                };

                DropDownList1.DataSource = dict;
                DropDownList1.DataTextField = "key";
                DropDownList1.DataValueField = "value";
                DataBind(); 
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            //SqlDataSource1.SelectCommand = "Select CityName from City where StateID = @id";
            //SqlDataSource1.SelectParameters.Add("id", DropDownList1.SelectedValue);
        }
    }
}