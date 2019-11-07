using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Question3
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
            long salary, bonus = 0, total;
            long.TryParse(textBox1.Text, out salary);
            int level = comboBox1.SelectedIndex;

            if (level == 0)
                bonus = (long) (0.1 * salary);
            else if (level >= 1 && level <= 3)
            {
                bonus = (long)(0.09 * salary);
            }
            else if (level >= 4 && level <= 6)
            {
                bonus = (long)(0.07 * salary);
            }
            else if (level >= 7 && level <= 9)
            {
                bonus = (long)(0.05 * salary);
            }
            else
            {
                Console.WriteLine("Selected Option: " + level);
                MessageBox.Show("Please choose a level of performance", "Invalid Option", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            total = salary + bonus;
            textBox2.Text = bonus.ToString();
            textBox3.Text = total.ToString();
        }
    }
}
