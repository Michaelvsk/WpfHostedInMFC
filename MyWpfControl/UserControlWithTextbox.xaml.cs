using System.Windows;
using System.Windows.Controls;
using System.Windows.Interop;

namespace MyWpfControl
{
    /// <summary>
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    public partial class UserControlWithTextbox : UserControl
    {
        public UserControlWithTextbox()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            HwndSource parentWindow = (HwndSource)PresentationSource.FromVisual(this);


            var modalDialog = new ModalDialog();
            modalDialog.Owner = parentWindow.RootVisual as System.Windows.Window;
            modalDialog.Show();
        }
    }
}
