
// MFCTabControlDlg.h : header file
//

#pragma once
#include "COneDialog.h"
#include "CSecondDialog.h"
#include "CThirdDialog.h"
#include "CFourthDialog.h"
#include "CFifthDialog.h"

// CMFCTabControlDlg dialog
class CMFCTabControlDlg : public CDialogEx
{
// Construction
public:
	CMFCTabControlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTABCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	COneDialog m_one;
	CSecondDialog m_second;
	CThirdDialog m_third;
	CFourthDialog m_fourth; 
	CFifthDialog m_fifth;

	CWnd* m_pwndShow;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
