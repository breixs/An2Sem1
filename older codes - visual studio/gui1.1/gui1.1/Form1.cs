using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace gui1._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void btnClickThis_Click(object sender, EventArgs e)
        {
            lblHelloWorld.Text = "Mihut E Gras";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void bingChilling_SelectedIndexChanged(object sender, EventArgs e)
        {
            bingChilling.Text = "i really like ice cum";
        }

        private void submit_Click(object sender, EventArgs e)
        {
            submit.Text = "Giarmata";
        }
    }
}
