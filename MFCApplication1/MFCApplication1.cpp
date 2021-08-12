
// MFCApplication1.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication1.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App

BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMFCApplication1App::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)	
	ON_COMMAND(ID_HELP_SERVERBUSYDIALOG, &CMFCApplication1App::OnHelpServerbusy)
	ON_COMMAND(ID_HELP_NOTRESPONDING, &CMFCApplication1App::OnHelpNotResponding)
END_MESSAGE_MAP()


// CMFCApplication1App construction

CMFCApplication1App::CMFCApplication1App() noexcept
{
	m_bHiColorIcons = TRUE;


	m_nAppLook = 0;
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	//System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApplication1.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CMFCApplication1App object

CMFCApplication1App theApp;
// This identifier was generated to be statistically unique for your app
// You may change it if you prefer to choose a specific identifier

// {bb9887f8-123c-4901-a2b3-44f86840c671}
static const CLSID clsid =
{0xbb9887f8,0x123c,0x4901,{0xa2,0xb3,0x44,0xf8,0x68,0x40,0xc6,0x71}};

const GUID CDECL _tlid = {0x96593665,0xc9ea,0x4b6e,{0xa5,0xfd,0x94,0x6d,0x8c,0xc2,0x05,0xee}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CMFCApplication1App initialization

BOOL CMFCApplication1App::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();
	InitShellManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MFCApplication1TYPE,
		RUNTIME_CLASS(CMFCApplication1Doc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CMFCApplication1View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// Connect the COleTemplateServer to the document template
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers by using information
	//  specified in the document template
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	// Register all OLE server factories as running.  This enables the
	//  OLE libraries to create objects from other applications
	COleTemplateServer::RegisterAll();
		// Note: MDI applications register all server objects without regard
		//  to the /Embedding or /Automation on the command line

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// App was launched with /Embedding or /Automation switch.
	// Run app as automation server.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Don't show the main window
		return TRUE;
	}
	// App was launched with /Unregserver or /Unregister switch.  Unregister
	// typelibrary.  Other unregistration occurs in ProcessShellCommand().
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT, nullptr, nullptr, FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
	}
	// App was launched standalone or with other switches (e.g. /Register
	// or /Regserver).  Update registry entries, including typelibrary.
	else
	{
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
	}

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CMFCApplication1App::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CMFCApplication1App message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

#include <string>
#include <corecrt_wstring.h>
#include <thread>
#include <chrono>
#include "LegacyApplicationInterop.cpp"
#include <FakeBusinessLayerInterop.h>
//#include "../WinUI3RuntimeComponent/WinUI3Window.xaml.h"
using namespace std;

//comment these out for faster builds
#using "SomeBusinessLayer.dll"
using namespace SomeBusinessLayer;

#using "System.dll"
using namespace System;
using namespace System::Diagnostics;

#include "esig.h"
#include "efile.h"

// App command to run the dialog
void CMFCApplication1App::OnAppAbout()
{
	Efile efile;
	efile.Submit();
	auto ack = efile.GetAcks();
	wstring acz(to_wstring(ack));
	AfxMessageBox(acz.c_str());



	// regular dll
	Esig esig;
	auto bal = esig.GetESigBalance();

	wstring balance(to_wstring(bal));
	AfxMessageBox(balance.c_str());



	//winrt::WinUI3RuntimeComponent::implementation::WinUI3Window window;
	LegacyApplicationInterop^ app = gcnew LegacyApplicationInterop();
	//FakeBusinessLayerInterop biz(app);
	//biz.DoStuffRequiringAuth();
	FakeBusinessLayer^ biz = gcnew FakeBusinessLayer(app);
	biz->DoStuffRequiringAuthAsync();

	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCApplication1App customization load/save methods

void CMFCApplication1App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CMFCApplication1App::LoadCustomState()
{
}

void CMFCApplication1App::SaveCustomState()
{
}

void CMFCApplication1App::OnHelpServerbusy()
{
	MessageBox(nullptr, L"In about 8s, the server busy dialog will come up", L"", MB_OK);
	auto process = System::Diagnostics::Process::Start(gcnew String("cmd"), gcnew String("/c ping 127.0.0.1 -n 10 > nul"));
	process->WaitForExit();
}


void CMFCApplication1App::OnHelpNotResponding()
{
	MessageBox(nullptr, L"In about 5s, click around on the app and it will become Not Responding for about 5s", L"", MB_OK);
	this_thread::sleep_for(10s);
}

