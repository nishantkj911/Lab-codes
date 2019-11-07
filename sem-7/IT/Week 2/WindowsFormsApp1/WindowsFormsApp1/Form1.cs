using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            double n1;
            double.TryParse(textBox1.Text, out n1);
            textBox2.Text = (n1 * 2).ToString();

            MessageBox.Show(comboBox1.SelectedItem.ToString(), "FUCK SAKE", MessageBoxButtons.OK, MessageBoxIcon.Information);

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox2.Text = "";
        }
    }
}
