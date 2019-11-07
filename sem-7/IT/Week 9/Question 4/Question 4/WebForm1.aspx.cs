using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        List<String> genres;
        protected void Page_Load(object sender, EventArgs e)
        {
            genres = new List<string>
            {
                "comedy",
                "romance",
                "animated"
            };

            DropDownList1.DataSource = genres;
            DataBind();
        }
    }
}