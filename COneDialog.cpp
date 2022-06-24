// COneDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCTabControl.h"
#include "COneDialog.h"
#include "afxdialogex.h"


// COneDialog dialog

IMPLEMENT_DYNAMIC(COneDialog, CDialogEx)

COneDialog::COneDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_One_Dialog, pParent)
{

}

COneDialog::~COneDialog()
{
}

void COneDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COneDialog, CDialogEx)
END_MESSAGE_MAP()


// COneDialog message handlers
