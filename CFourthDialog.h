#pragma once


// CFourthDialog dialog

class CFourthDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFourthDialog)

public:
	CFourthDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFourthDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Fourth_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
