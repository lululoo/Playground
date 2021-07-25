using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
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

        private void button1_Click(object sender, EventArgs e)
        {
            var processSleepDuration = 10;
            var sleepProcess = Process.Start("cmd", $"/c ping 127.0.0.1 -n {processSleepDuration} > nul");
            sleepProcess.WaitForExit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Not responding
            Thread.Sleep(10000);
        }
    }
}
