
// MFCApplicationCauDlg.h : ���Y��
//

#pragma once
#include "afxwin.h"


// CMFCApplicationCauDlg ��ܤ��
class CMFCApplicationCauDlg : public CDialogEx
{
// �غc
public:
	CMFCApplicationCauDlg(CWnd* pParent = NULL);	// �зǫغc�禡
	void print(CString txt);
	void TempCauCal();

// ��ܤ�����
	enum { IDD = IDD_MFCAPPLICATIONCAU_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton btn1;
	CButton btn2;
	CButton btn3;
	CButton btn4;
	CButton btn5;
	CButton btn6;
	CButton btn7;
	CButton btn8;
	CButton btn9;
	CButton btn0;
	CString result_txt;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedBtnAdd();
private:
	CButton add;
	CButton minus;
	CButton mult;
	CButton divi;
	CButton equal;
public:
	afx_msg void OnBnClickedBtnminus();
	afx_msg void OnBnClickedBtnmult();
	afx_msg void OnBnClickedBtndivi();
	afx_msg void OnBnClickedBtnequal();
private:
	CButton cancel;
public:
	afx_msg void OnBnClickedBtncancel();
};
