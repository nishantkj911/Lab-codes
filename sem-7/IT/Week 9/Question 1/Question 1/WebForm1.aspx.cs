using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Question_1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        List<String> fruits, iceCreamFlavours;
        protected void Page_PreLoad(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                fruits = new List<string>
                {
                    "Apple",
                    "Banana",
                    "Kiwi",
                    "Guava",
                    "Litchee",
                    "Mango",
                    "Strawberry"
                };

                iceCreamFlavours = new List<string>
                {
                    "Milk Chocolate",
                    "Dark Chocolate",
                    "Strawberry",
                    "Blueberry",
                    "Vanilla",
                    "Butterscotch",
                    "Kulfi"
                };

                CheckBoxList1.DataSource = fruits;
                RadioButtonList1.DataSource = iceCreamFlavours;
                DataBind(); 
            }
        }

        protected void Page_PreInit(object sender, EventArgs e)
        {
            
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string fruitStr = "";
            foreach (ListItem item in CheckBoxList1.Items)
            {
                if (item.Selected)
                {
                    fruitStr += item.Text + " ";
                }
            }
            Label1.Text = "You've selected a " + fruitStr + RadioButtonList1.SelectedValue + " milkshake";
        }
    }
}