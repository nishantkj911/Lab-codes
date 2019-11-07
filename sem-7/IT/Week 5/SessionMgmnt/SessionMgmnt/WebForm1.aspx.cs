using System;

namespace SessionMgmnt
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        int count = 0;
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                HiddenField1.Value = "0";
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            count = int.Parse(HiddenField1.Value);

            count += 1;
            HiddenField1.Value = count.ToString();
            para.InnerHtml = "This button has been clicked " + count.ToString() + " " + (count == 1 ? "time" : "times") + ".";
        }

        protected void Button2_Click(object sender, EventArgs e)
        {

        }
    }
}