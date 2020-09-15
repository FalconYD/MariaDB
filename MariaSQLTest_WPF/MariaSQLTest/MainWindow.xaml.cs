using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MySql.Data.MySqlClient;

namespace MariaSQLTest
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        private static string mysql_conn_str = "Server=localhost; Port=3306; Database=testdb; Uid=root; Password=1234;";
        public MainWindow()
        {
            InitializeComponent();
        }

        private void bn_DBOpen_Click(object sender, RoutedEventArgs e)
        {
            if(!db_init())
            {
                // 에러 처리.
                MessageBox.Show("DB Init Error.");
            }
        }

        /// <summary>
        /// DataGrid에 데이터 바인딩
        /// </summary>
        /// <returns></returns>
        public bool db_init()
        {
            bool bret = true;
            using (var conn = new MySqlConnection(mysql_conn_str))
            {
                try
                {
                    conn.Open();
                    MySqlCommand cmd = new MySqlCommand("SELECT * FROM testtable", conn);
                    MySqlDataAdapter adp = new MySqlDataAdapter(cmd);
                    DataSet ds = new DataSet();

                    // 윈도우 폼의 LoadDataBinding에 데이터 넣기
                    adp.Fill(ds, "LoadDataBinding");

                    // DataGrid에 데이터 셋
                    dg_Test.DataContext = ds;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 베이스 오픈 실패: " + ex.Message, "Database Error[MYSQL]");
                    bret = false;
                }
                finally
                {
                    conn.Close();
                }
            }
            return bret;
        }

        private void bn_Query_Click(object sender, RoutedEventArgs e)
        {
            m_fn_ExecuteQuery();
            db_init();
        }

        /// <summary>
        /// Text box에 있는 쿼리 실행.
        /// </summary>
        public void m_fn_ExecuteQuery()
        {
            using (var conn = new MySqlConnection(mysql_conn_str))
            {
                try
                {
                    conn.Open();
                    MySqlCommand cmd = new MySqlCommand(tb_Query.Text, conn);
                    cmd.ExecuteScalar();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 베이스 오픈 실패: " + ex.Message, "Database Error[MYSQL]");

                }
                finally
                {
                    conn.Close();
                }
            }
        }

        #region Preset
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            tb_Query.Text = "INSERT INTO testtable(FieldName1, FieldName2, FieldName3, ...) VALUES(val1, val2, val3, ...)";
        }

        private void bn_Preset_Delete_Click(object sender, RoutedEventArgs e)
        {
            tb_Query.Text = "DELETE FROM testtable WHERE FieldName = val";
        }

        private void bn_Preset_Update_Click(object sender, RoutedEventArgs e)
        {
            tb_Query.Text = "UPDATE testtable SET FieldName1 = val1, FieldName2 = val2, ... WHERE FieldName = val";
        }

        private void bn_Preset_Select_Click(object sender, RoutedEventArgs e)
        {
            tb_Query.Text = "SELECT FieldName FROM testtable WHERE FieldName = val";
        }
        #endregion

        /// <summary>
        /// Text box에서 엔터치면 쿼리 실행.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tb_Query_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                bn_Query_Click(null, null);
            }
        }
    }
}
