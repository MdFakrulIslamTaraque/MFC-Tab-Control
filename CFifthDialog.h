#pragma once


// CFifthDialog dialog

class CFifthDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFifthDialog)

public:
	CFifthDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFifthDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Fifth_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
