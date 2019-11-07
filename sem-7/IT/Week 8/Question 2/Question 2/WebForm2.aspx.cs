using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        public String Message;
        protected void Page_Init(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Dictionary<Int32, String> dict = new Dictionary<int, string>();
                dict.Add(1, "comedy");
                dict.Add(2, "romance");
                dict.Add(3, "animated");


                DropDownList1.DataSource = dict;
                DropDownList1.DataTextField = "value";
                
                DataBind();

                Message = "Yo";
            }
        }
    }
}