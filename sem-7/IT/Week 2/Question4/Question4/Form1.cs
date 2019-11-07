using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Question4
{
    public partial class Form1 : Form
    {
        long[] carPrices;
        long finalCarPrice, baseCarPrice;
        int previousSelectedIndex;
        public Form1()
        {
            InitializeComponent();
            carPrices = new long[6]{ 300000, 500000, 800000, 700000, 1000000, 1500000};
            baseCarPrice = 0;
            finalCarPrice = 0;
            previousSelectedIndex = -1;
        }

        private void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (previousSelectedIndex != listBox1.SelectedIndex)
            {
                switch(listBox1.SelectedIndex)
                {
                    case 0:
                        finalCarPrice = baseCarPrice;
                        break;
                    case 1:
                        finalCarPrice = (long)(baseCarPrice * 0.9);
                        break;
                    case 2:
                        finalCarPrice += (long)(baseCarPrice * 0.5);
                        break;
                    default:
                        Console.WriteLine("No option selected");
                        break;
                }

                textBox1.Text = finalCarPrice.ToString();
                previousSelectedIndex = listBox1.SelectedIndex;
            }
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("Thank You for purchasing", "Purchase Complete", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dr == DialogResult.Cancel)
            {
                comboBox1.SelectedIndex = comboBox2.SelectedIndex = -1;
                listBox1.SelectedIndex = -1;
                textBox1.Text = "";
            }
            else
            {
                Application.Exit();
            }
        }

        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == -1)
                baseCarPrice = 0;
            else
                baseCarPrice = carPrices[comboBox1.SelectedIndex];
        }
    }
}
