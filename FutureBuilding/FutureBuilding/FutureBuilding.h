
// FutureBuilding.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFutureBuildingApp:
// �йش����ʵ�֣������ FutureBuilding.cpp
//

class CFutureBuildingApp : public CWinApp
{
public:
	CFutureBuildingApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFutureBuildingApp theApp;