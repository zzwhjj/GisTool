#pragma once


// DlgShpReadAndWrite dialog

class DlgShpReadAndWrite : public CDialogEx
{
	DECLARE_DYNAMIC(DlgShpReadAndWrite)

public:
	DlgShpReadAndWrite(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgShpReadAndWrite();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_SHP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strShpPathName;
	afx_msg void OnBnClickedBtnInputFile();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
