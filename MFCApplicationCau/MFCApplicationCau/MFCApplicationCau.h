
// MFCApplicationCau.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCApplicationCauApp: 
// �аѾ\��@�����O�� MFCApplicationCau.cpp
//

class CMFCApplicationCauApp : public CWinApp
{
public:
	CMFCApplicationCauApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationCauApp theApp;