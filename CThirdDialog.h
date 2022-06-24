#pragma once


// CThirdDialog dialog

class CThirdDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdDialog)

public:
	CThirdDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CThirdDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Third_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
