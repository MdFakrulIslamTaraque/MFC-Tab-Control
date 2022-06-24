
// MFCTabControlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCTabControl.h"
#include "MFCTabControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTabControlDlg dialog



CMFCTabControlDlg::CMFCTabControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTABCONTROL_DIALOG, pParent),
	m_pwndShow(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTabControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCTabControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCTabControlDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMFCTabControlDlg message handlers

BOOL CMFCTabControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	/*CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMP6);
	static CImageList imgList;
	imgList.Create(16, 16, ILC_COLOR24 | ILC_MASK, 5, 0);
	imgList.Add(&bmp, RGB(192, 192, 192));
	m_tab.SetImageList(&imgList);*/


	CString strTabH = _T("");
	for (int i = 0; i < 5; i++)
	{
		strTabH.Format(_T("Tab-%d"), i + 1);
		m_tab.InsertItem(i, strTabH, i);
	}

	CRect rect;
	m_tab.GetClientRect(&rect);
	m_one.Create(IDD_One_Dialog, &m_tab);
	m_one.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW | SWP_NOZORDER);
	m_pwndShow = &m_one;

	m_second.Create(IDD_Second_Dialog, &m_tab);
	m_second.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW | SWP_NOZORDER);

	m_third.Create(IDD_Third_DIALOG, &m_tab);
	m_third.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW | SWP_NOZORDER);

	m_fourth.Create(IDD_Fourth_Dialog, &m_tab);
	m_fourth.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW | SWP_NOZORDER);

	m_fifth.Create(IDD_Fifth_Dialog, &m_tab);
	m_fifth.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW | SWP_NOZORDER);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCTabControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCTabControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCTabControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTabControlDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	if (m_pwndShow != NULL)
	{
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}
	int mIndex = m_tab.GetCurSel();
	switch (mIndex)
	{
	case 0:
		m_one.ShowWindow(SW_SHOW);
		m_pwndShow = &m_one;
		break;
	case 1:
		m_second.ShowWindow(SW_SHOW);
		m_pwndShow = &m_second;
		break;
	case 2:
		m_third.ShowWindow(SW_SHOW);
		m_pwndShow = &m_third;
		break;
	case 3:
		m_fourth.ShowWindow(SW_SHOW);
		m_pwndShow = &m_fourth;
		break;
	case 4:
		m_fifth.ShowWindow(SW_SHOW);
		m_pwndShow = &m_fifth;
		break; 
	}
	*pResult = 0;
}
