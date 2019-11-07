using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_PreInit(object sender, EventArgs e)
        {
            if (!IsPostBack)
                ExampleClass.WriteXMLDocument();
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Xml1.DocumentSource = "XMLFile2.xml";
            Xml1.DataBind();

            XmlDataSource1.DataFile = "XmlFile2.xml";
            XmlDataSource1.DataBind();
        }
    }
}