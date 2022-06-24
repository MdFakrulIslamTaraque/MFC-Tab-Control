#pragma once


// COneDialog dialog

class COneDialog : public CDialogEx
{
	DECLARE_DYNAMIC(COneDialog)

public:
	COneDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~COneDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_One_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
