using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DishAssignment
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            for (int i = 1; i <= 10; i++)
            {
                comboBox1.Items.Add(new Exception("Fuck off"));
            }
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            int attendance;
            int.TryParse(textBox2.Text, out attendance);
            if (attendance < 75)
            {
                if (Convert.ToInt32(comboBox1.SelectedItem) == 0)
                    textBox1.BackColor = Color.Yellow;
                else
                {
                    textBox1.BackColor = Color.Red;
                }

                comboBox1.SelectedItem = Convert.ToInt32(comboBox1.SelectedItem) + 1;
                messageLabel.Text = comboBox1.SelectedText;
                //messageLabel.Text = "Low attendance for roll number " + (comboBox1.SelectedIndex + 1);
            }


        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {
            messageLabel.Text = comboBox1.SelectedValue.ToString();
        }

        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox1.BackColor = Color.White;
            messageLabel.Text = "";

        }
    }
}

