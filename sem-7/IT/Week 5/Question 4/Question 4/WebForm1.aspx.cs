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
        int attempts = 0;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Session.Add("Attempts", attempts);
                for (int i = 0; i < 5; i++)
                {
                    Application.Add("user" + i.ToString(), new User(i.ToString(), i.ToString() + i.ToString()));
                }
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            attempts = (int)Session["Attempts"];
            attempts++;


        }
    }

    class User
    {
        public string Username { get; set; }
        public string Password { get; set; }
        public int Attempts { get; set; }

        public User (string u, string p)
        {
            Username = u;
            Password = p;
        }
    }
}