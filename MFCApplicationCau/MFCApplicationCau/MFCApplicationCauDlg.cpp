
// MFCApplicationCauDlg.cpp : ��@��
//

#include "stdafx.h"
#include "MFCApplicationCau.h"
#include "MFCApplicationCauDlg.h"
#include "afxdialogex.h"
#include <sstream>
#include <string>
#include<queue>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString str, tmp;
int sum = 0, tmp1, tmp2, tmp3,  frist = -1;
bool is = false;
std::queue<int> s;
std::queue<char> oper;
// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationCauDlg ��ܤ��



CMFCApplicationCauDlg::CMFCApplicationCauDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplicationCauDlg::IDD, pParent)
	, result_txt(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationCauDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, btn1);
	DDX_Control(pDX, IDC_BUTTON2, btn2);
	DDX_Control(pDX, IDC_BUTTON3, btn3);
	DDX_Control(pDX, IDC_BUTTON4, btn4);
	DDX_Control(pDX, IDC_BUTTON5, btn5);
	DDX_Control(pDX, IDC_BUTTON6, btn6);
	DDX_Control(pDX, IDC_BUTTON7, btn7);
	DDX_Control(pDX, IDC_BUTTON8, btn8);
	DDX_Control(pDX, IDC_BUTTON9, btn9);
	DDX_Control(pDX, IDC_BUTTON0, btn0);
	DDX_Text(pDX, IDC_RESULT, result_txt);
	DDX_Control(pDX, IDC_BTN_ADD, add);
	DDX_Control(pDX, IDC_BTNMINUS, minus);
	DDX_Control(pDX, IDC_BTNMULT, mult);
	DDX_Control(pDX, IDC_BTNDIVI, divi);
	DDX_Control(pDX, IDC_BTNEQUAL, equal);
	DDX_Control(pDX, IDC_BTNCANCEL, cancel);
}

BEGIN_MESSAGE_MAP(CMFCApplicationCauDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationCauDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationCauDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationCauDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplicationCauDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplicationCauDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplicationCauDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplicationCauDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplicationCauDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplicationCauDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplicationCauDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCApplicationCauDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTNMINUS, &CMFCApplicationCauDlg::OnBnClickedBtnminus)
	ON_BN_CLICKED(IDC_BTNMULT, &CMFCApplicationCauDlg::OnBnClickedBtnmult)
	ON_BN_CLICKED(IDC_BTNDIVI, &CMFCApplicationCauDlg::OnBnClickedBtndivi)
	ON_BN_CLICKED(IDC_BTNEQUAL, &CMFCApplicationCauDlg::OnBnClickedBtnequal)
	ON_BN_CLICKED(IDC_BTNCANCEL, &CMFCApplicationCauDlg::OnBnClickedBtncancel)
END_MESSAGE_MAP()


// CMFCApplicationCauDlg �T���B�z�`��

BOOL CMFCApplicationCauDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// �N [����...] �\���[�J�t�Υ\���C

	// IDM_ABOUTBOX �����b�t�ΩR�O�d�򤧤��C
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

void CMFCApplicationCauDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CMFCApplicationCauDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CMFCApplicationCauDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/* use queue store values 
1.put sum into queue  before press any operate button 
/2.put sum into  queue after press any operate button  
3.dequeue it into tmp1 and tmp2
4. If second operates use tmp3
*/

void CMFCApplicationCauDlg::OnBnClickedButton1()
{
	btn1.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 1;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton2()
{
	btn2.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 2;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton3()
{
	btn3.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 3;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton4()
{
	btn4.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 4;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton5()
{
	btn5.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 5;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton6()
{
	btn6.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 6;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}



void CMFCApplicationCauDlg::OnBnClickedButton7()
{
	btn7.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 7;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton8()
{
	btn8.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 8;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton9()
{
	btn9.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	sum += 9;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}


void CMFCApplicationCauDlg::OnBnClickedButton0()
{
	btn0.GetWindowTextW(tmp);
	str += tmp;
	sum *= 10;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}

void CMFCApplicationCauDlg::OnBnClickedBtnAdd()
{
	str += '+';
	if (sum>0)
		s.push(sum);
	oper.push('+');
	sum = 0;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}
void CMFCApplicationCauDlg::OnBnClickedBtnminus()
{
	
	str += '-';
	if (sum>0)
		s.push(sum);
	oper.push('-');
	sum = 0;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}
void CMFCApplicationCauDlg::OnBnClickedBtnmult()
{
	str += '*';
	if (sum>0)
		s.push(sum);
	oper.push('*');
	sum = 0;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}
void CMFCApplicationCauDlg::OnBnClickedBtndivi()
{
	str += '/';
	if (sum>0)
		s.push(sum);
	oper.push('/');
	sum = 0;
	print(str);
	// TODO:  �b���[�J����i���B�z�`���{���X
}
void CMFCApplicationCauDlg::OnBnClickedBtnequal()
{
	s.push(sum);
	sum = 0;
	TempCauCal();
	// TODO:  �b���[�J����i���B�z�`���{���X
}
void CMFCApplicationCauDlg::OnBnClickedBtncancel()
{
	str = " ";
	print(str);
	tmp1 = tmp2=sum = 0;
	is = false;
	while (!s.empty() && !oper.empty())
	{
		s.pop();
		oper.pop();
	}
	// TODO:  �b���[�J����i���B�z�`���{���X
}

void CMFCApplicationCauDlg::print(CString txt)
{
	result_txt = txt;
	UpdateData(false);
}
void CMFCApplicationCauDlg::TempCauCal()
{
	char op;

	while (!s.empty())
	{
		tmp1 = s.front();
		s.pop();
		if (!is)
		{
			tmp2 = s.front();
			s.pop();
		}
		else
			tmp2 = tmp3;
		op = oper.front();
		oper.pop();

		switch (op)
		{
		case '+':
			tmp.Format(TEXT("%d"), (tmp1 + tmp2));
			str = tmp;
			tmp3 = tmp1 + tmp2;
			print(str);
			break;
		case '-':
			tmp3 = tmp1 - tmp2;
			tmp3 < 0 ? tmp3 *= -1 : tmp3 *= 1;
			tmp.Format(TEXT("%d"), (tmp3));
			str = tmp;
			print(str);
			break;
		case '*':
			tmp.Format(TEXT("%d"), (tmp1 *tmp2));
			tmp3 = tmp1 *tmp2;
		    str = tmp;
			print(str);
			break;
		case '/':
			tmp.Format(TEXT("%d"), (tmp2 / tmp1));
			tmp3 = tmp1 / tmp2;
			str = tmp;
			print(str);
			break;

		}
		is = true;
	}
}
