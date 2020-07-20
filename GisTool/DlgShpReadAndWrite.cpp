// DlgShpReadAndWrite.cpp : implementation file
//

#include "pch.h"
#include "GisTool.h"
#include "DlgShpReadAndWrite.h"
#include "afxdialogex.h"
#include ".\ShapeFile\ShapeFileRead.h"

// DlgShpReadAndWrite dialog

IMPLEMENT_DYNAMIC(DlgShpReadAndWrite, CDialogEx)

DlgShpReadAndWrite::DlgShpReadAndWrite(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SHP, pParent)
	, m_strShpPathName(_T(""))
{

}

DlgShpReadAndWrite::~DlgShpReadAndWrite()
{
}

void DlgShpReadAndWrite::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHP_PATH, m_strShpPathName);
}


BEGIN_MESSAGE_MAP(DlgShpReadAndWrite, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_INPUT_FILE, &DlgShpReadAndWrite::OnBnClickedBtnInputFile)
	ON_BN_CLICKED(IDOK, &DlgShpReadAndWrite::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgShpReadAndWrite message handlers

//Ñ¡ÔñshpÎÄ¼þ
void DlgShpReadAndWrite::OnBnClickedBtnInputFile()
{
	CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.shp)|*.shp|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		m_strShpPathName = dlgFile.GetPathName();
	}

	UpdateData(FALSE);
}

void DlgShpReadAndWrite::OnBnClickedOk()
{
	ShapeFileRead read;
	read.ReadShp(m_strShpPathName.GetBuffer());

	CDialogEx::OnOK();
}
