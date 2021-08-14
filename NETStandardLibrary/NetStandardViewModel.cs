using GalaSoft.MvvmLight;

namespace NETStandardLibrary
{
    public class NetStandardViewModel : ObservableObject
    {
        private int _MyProperty;
        public int MyProperty { get { return _MyProperty; } set { _MyProperty = value; RaisePropertyChanged(); } }
    }
}
