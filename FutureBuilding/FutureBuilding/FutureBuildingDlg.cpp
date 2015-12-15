
// FutureBuildingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FutureBuilding.h"
#include "FutureBuildingDlg.h"
#include "afxdialogex.h"
#include "MyMemDC.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFutureBuildingDlg �Ի���




CFutureBuildingDlg::CFutureBuildingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFutureBuildingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//1.������ʾԪ��
	allDisplayId.push_back(IDC_STATIC_BTN_1);
	allDisplayId.push_back(IDC_STATIC_BTN_2);
	allDisplayId.push_back(IDC_STATIC_BTN_3);
	allDisplayId.push_back(IDC_STATIC_BTN_4);
	allDisplayId.push_back(IDC_STATIC_BTN_5);
	allDisplayId.push_back(IDC_STATIC_BTN_6);
	allDisplayId.push_back(IDC_STATIC_BTN_7);
	allDisplayId.push_back(IDC_STATIC_BTN_8);
	allDisplayId.push_back(IDC_STATIC_BTN_9);
	allDisplayId.push_back(IDC_STATIC_BTN_10);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_11);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_12);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_13);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_14);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_15);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_16);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_17);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_18);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_19);
	allDisplayId.push_back(IDC_STATIC_BUILDNAME_20);
	allDisplayId.push_back(IDC_STATIC_PIC_BOX);
	allDisplayId.push_back(IDC_STATIC_INTRODUCTION);
	allDisplayId.push_back(IDC_BUTTON_BACK);

	chooseDisplayId.push_back(IDC_STATIC_BTN_1);
	chooseDisplayId.push_back(IDC_STATIC_BTN_2);
	chooseDisplayId.push_back(IDC_STATIC_BTN_3);
	chooseDisplayId.push_back(IDC_STATIC_BTN_4);
	chooseDisplayId.push_back(IDC_STATIC_BTN_5);
	chooseDisplayId.push_back(IDC_STATIC_BTN_6);
	chooseDisplayId.push_back(IDC_STATIC_BTN_7);
	chooseDisplayId.push_back(IDC_STATIC_BTN_8);
	chooseDisplayId.push_back(IDC_STATIC_BTN_9);
	chooseDisplayId.push_back(IDC_STATIC_BTN_10);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_11);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_12);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_13);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_14);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_15);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_16);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_17);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_18);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_19);
	chooseDisplayId.push_back(IDC_STATIC_BUILDNAME_20);

	introductionDisplayId.push_back(IDC_STATIC_PIC_BOX);
	introductionDisplayId.push_back(IDC_STATIC_INTRODUCTION);
	introductionDisplayId.push_back(IDC_BUTTON_BACK);
}

void CFutureBuildingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC_BOX, m_PictureBox);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_btnBack);
}

BEGIN_MESSAGE_MAP(CFutureBuildingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_11, &CFutureBuildingDlg::OnStnClickedStaticBuildname11)
	ON_STN_CLICKED(IDC_STATIC_BTN_1, &CFutureBuildingDlg::OnStnClickedStaticBtn1)
	ON_STN_CLICKED(IDC_STATIC_BTN_2, &CFutureBuildingDlg::OnStnClickedStaticBtn2)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_12, &CFutureBuildingDlg::OnStnClickedStaticBuildname12)
	ON_STN_CLICKED(IDC_STATIC_BTN_3, &CFutureBuildingDlg::OnStnClickedStaticBtn3)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_13, &CFutureBuildingDlg::OnStnClickedStaticBuildname13)
	ON_STN_CLICKED(IDC_STATIC_BTN_4, &CFutureBuildingDlg::OnStnClickedStaticBtn4)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_14, &CFutureBuildingDlg::OnStnClickedStaticBuildname14)
	ON_STN_CLICKED(IDC_STATIC_BTN_5, &CFutureBuildingDlg::OnStnClickedStaticBtn5)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_15, &CFutureBuildingDlg::OnStnClickedStaticBuildname15)
	ON_STN_CLICKED(IDC_STATIC_BTN_6, &CFutureBuildingDlg::OnStnClickedStaticBtn6)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_16, &CFutureBuildingDlg::OnStnClickedStaticBuildname16)
	ON_STN_CLICKED(IDC_STATIC_BTN_7, &CFutureBuildingDlg::OnStnClickedStaticBtn7)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_17, &CFutureBuildingDlg::OnStnClickedStaticBuildname17)
	ON_STN_CLICKED(IDC_STATIC_BTN_8, &CFutureBuildingDlg::OnStnClickedStaticBtn8)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_18, &CFutureBuildingDlg::OnStnClickedStaticBuildname18)
	ON_STN_CLICKED(IDC_STATIC_BTN_9, &CFutureBuildingDlg::OnStnClickedStaticBtn9)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_19, &CFutureBuildingDlg::OnStnClickedStaticBuildname19)
	ON_STN_CLICKED(IDC_STATIC_BTN_10, &CFutureBuildingDlg::OnStnClickedStaticBtn10)
	ON_STN_CLICKED(IDC_STATIC_BUILDNAME_20, &CFutureBuildingDlg::OnStnClickedStaticBuildname20)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CFutureBuildingDlg::OnBnClickedButton1)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CFutureBuildingDlg ��Ϣ�������

BOOL CFutureBuildingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// Initialize CImageBox
	m_PictureBox.Create();
	// ��������
	m_PictureBox.SetAnimationType(CImageBox::kAnimationCoverLeft);
	// ��������ʱ��(ms)
	m_PictureBox.SetDuration(400);
	// ÿ��ͼƬͣ��ʱ��
	m_PictureBox.SetRetention(2000);
	m_PictureBox.AddImage(TEXT("images\\1.jpg"));
	m_PictureBox.AddImage(TEXT("images\\2.jpg"));
	m_PictureBox.AddImage(TEXT("images\\3.jpg"));
	m_PictureBox.AddImage(TEXT("images\\4.jpg"));
	m_PictureBox.AddImage(TEXT("images\\5.jpg"));
	m_PictureBox.AddImage(TEXT("images\\6.jpg"));
	m_PictureBox.AddImage(TEXT("images\\7.jpg"));
	m_PictureBox.AddImage(TEXT("images\\8.jpg"));

	//��������
	m_fontIntroduction.CreatePointFont(350,_T("�����п�"));

	m_btnBack.LoadStdImage(IDB_PNG_BACK, -1, _T("PNG"));
	HBITMAP		hBitmap			= NULL;
	HINSTANCE	hInstResource	= NULL;
	hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND), RT_BITMAP);
	m_hBitmap = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND), IMAGE_BITMAP, 0, 0, 0);

	currentDisplayId = &chooseDisplayId;

	display();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFutureBuildingDlg::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	CRect rect;

	GetClientRect(&rect);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
	
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	//-------------------------------���ñ���ͼƬ
	CBitmap     bmp;

	bmp.LoadBitmap(IDB_BITMAP_BACKGROUND);

	CDC dcMemory;

	dcMemory.CreateCompatibleDC(&dc);

	dcMemory.SelectObject(&bmp);

	dc.BitBlt(rect.left,rect.top,rect.right,rect.bottom,&dcMemory,0,0,SRCCOPY);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFutureBuildingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFutureBuildingDlg::OnStnClickedStaticBuildname11()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:ʷ���ġ�����\n    ����������¥����9,500����Ԫ��Լ7.4�ڸ�Ԫ���˽���2007��6��9�ս�Ļ���ղص����ͷ�������Ʒ����Ӱ��Ʒ�Լ��ر�ݲء�����������һ���������Ͳο�ͼ��ݡ��ɰ��������ݽ������Ϊ��ʽ�ŵ��ɡ���λ�ѡΪ��ʱ�����ܿ�2007���ʮ����ѽ�����λ�ģ��ǹ����½��Ĳ���˴�¥���ݷ���1993�꿪ʼ��˼������Ŀ����Ҫ�������������55%�������ƻ���1999����ʵ������ʦ������������Ƴ�¥�׸߶Ȳ�һ���������¥���⣬��ʱ�����ܿ����ݲ���������ǹŵ��ɽ����ĺ�ΰ���ࡣ�����������ݿ���˹���ɶ�ѷ������������¥����¥�ɼ���������İ�ɫ��������ɡ�ÿ��ҹ�䣬�ƹ����ǽ�ϰ�͸����͸���Ĳ�����͸�������ƽ����������ⷢ����͵İ�ɫ��â��ʹ�����¹ŵ�������������ݸ����ִ���Ϣ����������ʱ������־��Ϊ2007������ʮ����֮�ס�"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn1()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "ʷ���ġ�����";
	//std::string ssss = "����������¥����9,500����Ԫ��Լ7.4�ڸ�Ԫ���˽���2007��6��9�ս�Ļ���ղص����ͷ�������Ʒ����Ӱ��Ʒ�Լ��ر�ݲء�����������һ���������Ͳο�ͼ��ݡ��ɰ��������ݽ������Ϊ��ʽ�ŵ��ɡ���λ�ѡΪ��ʱ�����ܿ�2007���ʮ����ѽ�����λ�ģ��ǹ����½��Ĳ���˴�¥���ݷ���1993�꿪ʼ��˼������Ŀ����Ҫ�������������55%�������ƻ���1999����ʵ������ʦ������������Ƴ�¥�׸߶Ȳ�һ���������¥���⣬��ʱ�����ܿ����ݲ���������ǹŵ��ɽ����ĺ�ΰ���ࡣ�����������ݿ���˹���ɶ�ѷ������������¥����¥�ɼ���������İ�ɫ��������ɡ�ÿ��ҹ�䣬�ƹ����ǽ�ϰ�͸����͸���Ĳ�����͸�������ƽ����������ⷢ����͵İ�ɫ��â��ʹ�����¹ŵ�������������ݸ����ִ���Ϣ����������ʱ������־��Ϊ2007������ʮ����֮�ס�";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:ʷ���ġ�����\n    ����������¥����9,500����Ԫ��Լ7.4�ڸ�Ԫ���˽���2007��6��9�ս�Ļ���ղص����ͷ�������Ʒ����Ӱ��Ʒ�Լ��ر�ݲء�����������һ���������Ͳο�ͼ��ݡ��ɰ��������ݽ������Ϊ��ʽ�ŵ��ɡ���λ�ѡΪ��ʱ�����ܿ�2007���ʮ����ѽ�����λ�ģ��ǹ����½��Ĳ���˴�¥���ݷ���1993�꿪ʼ��˼������Ŀ����Ҫ�������������55%�������ƻ���1999����ʵ������ʦ������������Ƴ�¥�׸߶Ȳ�һ���������¥���⣬��ʱ�����ܿ����ݲ���������ǹŵ��ɽ����ĺ�ΰ���ࡣ�����������ݿ���˹���ɶ�ѷ������������¥����¥�ɼ���������İ�ɫ��������ɡ�ÿ��ҹ�䣬�ƹ����ǽ�ϰ�͸����͸���Ĳ�����͸�������ƽ����������ⷢ����͵İ�ɫ��â��ʹ�����¹ŵ�������������ݸ����ִ���Ϣ����������ʱ������־��Ϊ2007������ʮ����֮�ס�"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn2()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "Ī����˹ ��ķ��÷��";
	//std::string ssss = "�ɽ�ɽ�������¥λ�����������������ݾɽ�ɽ�������ý�����18��칫¥����71�ס�����¥�㿪ʼ�������С���Ҷ���������ǽ��ƣ��������۸ְ壬��ʱ�����ܿ����ݴ�¥��Ƽ�����տ��������¥�����������ϸ��˼�ǿ���Ӿ����������������ȫȫ�Ļ����������������ͬ���ʹ�¥���ܵ�һ�롣��¥����һ��װ�д��׽����壬���Ǽ���������¥�����Ƶ�һ���֣�Ҳ��ʵ�õ����������ܹ��ڵ�סֱ�������ͬʱ��Ϊ��¥�ڵİ칫���ṩ�º͵Ĳɹ⣬��ʹ�봰����Զ����λҲ�����ܵ���Ȼ�⡣";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:Ī����˹ ��ķ��÷��\n    �ɽ�ɽ�������¥λ�����������������ݾɽ�ɽ�������ý�����18��칫¥����71�ס�����¥�㿪ʼ�������С���Ҷ���������ǽ��ƣ��������۸ְ壬��ʱ�����ܿ����ݴ�¥��Ƽ�����տ��������¥�����������ϸ��˼�ǿ���Ӿ����������������ȫȫ�Ļ����������������ͬ���ʹ�¥���ܵ�һ�롣��¥����һ��װ�д��׽����壬���Ǽ���������¥�����Ƶ�һ���֣�Ҳ��ʵ�õ����������ܹ��ڵ�סֱ�������ͬʱ��Ϊ��¥�ڵİ칫���ṩ�º͵Ĳɹ⣬��ʹ�봰����Զ����λҲ�����ܵ���Ȼ�⡣"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname12()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:Ī����˹ ��ķ��÷��\n    �ɽ�ɽ�������¥λ�����������������ݾɽ�ɽ�������ý�����18��칫¥����71�ס�����¥�㿪ʼ�������С���Ҷ���������ǽ��ƣ��������۸ְ壬��ʱ�����ܿ����ݴ�¥��Ƽ�����տ��������¥�����������ϸ��˼�ǿ���Ӿ����������������ȫȫ�Ļ����������������ͬ���ʹ�¥���ܵ�һ�롣��¥����һ��װ�д��׽����壬���Ǽ���������¥�����Ƶ�һ���֣�Ҳ��ʵ�õ����������ܹ��ڵ�סֱ�������ͬʱ��Ϊ��¥�ڵİ칫���ṩ�º͵Ĳɹ⣬��ʹ�봰����Զ����λҲ�����ܵ���Ȼ�⡣"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn3()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "Weiss/Manfredi";
	//std::string ssss = "����ͼ��������ݽ�����ܹ�԰����һ���ɹ�ҵ���ڣ�һ����æ�Ĺ�·����·��Խ��䡣���˵��ܹ�԰λ�ڱ�����·����·���м�Ŀյأ���Ϥ1970�����ǰ����԰���ڵ�Ϊʯ�͹�˾����ƣ���������ʯ�ͣ�ռ�С������Ǩ���󣬸õ�Ƥ����²����ж����ʣ����궪�ա���������ͼ�����ݽ���Ѹÿ����õظĽ��ɹ�԰���Խ������ͼ��������ȱ������õص����⡣�ù�԰�ڷŵĲ��ִ��͵����������˾����ι��߿��ڵ��������ߡ����⣬��԰��᲻ʱչ���ǳ�����ܣ���ʱ�����ܿ����ݹ�԰����Ȼ������������ۺ���������Ϊ����ͼ�ġ����ܵش���������һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:Weiss/Manfredi\n    ����ͼ��������ݽ�����ܹ�԰����һ���ɹ�ҵ���ڣ�һ����æ�Ĺ�·����·��Խ��䡣���˵��ܹ�԰λ�ڱ�����·����·���м�Ŀյأ���Ϥ1970�����ǰ����԰���ڵ�Ϊʯ�͹�˾����ƣ���������ʯ�ͣ�ռ�С������Ǩ���󣬸õ�Ƥ����²����ж����ʣ����궪�ա���������ͼ�����ݽ���Ѹÿ����õظĽ��ɹ�԰���Խ������ͼ��������ȱ������õص����⡣�ù�԰�ڷŵĲ��ִ��͵����������˾����ι��߿��ڵ��������ߡ����⣬��԰��᲻ʱչ���ǳ�����ܣ���ʱ�����ܿ����ݹ�԰����Ȼ������������ۺ���������Ϊ����ͼ�ġ����ܵش���������һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname13()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:Weiss/Manfredi\n    ����ͼ��������ݽ�����ܹ�԰����һ���ɹ�ҵ���ڣ�һ����æ�Ĺ�·����·��Խ��䡣���˵��ܹ�԰λ�ڱ�����·����·���м�Ŀյأ���Ϥ1970�����ǰ����԰���ڵ�Ϊʯ�͹�˾����ƣ���������ʯ�ͣ�ռ�С������Ǩ���󣬸õ�Ƥ����²����ж����ʣ����궪�ա���������ͼ�����ݽ���Ѹÿ����õظĽ��ɹ�԰���Խ������ͼ��������ȱ������õص����⡣�ù�԰�ڷŵĲ��ִ��͵����������˾����ι��߿��ڵ��������ߡ����⣬��԰��᲻ʱչ���ǳ�����ܣ���ʱ�����ܿ����ݹ�԰����Ȼ������������ۺ���������Ϊ����ͼ�ġ����ܵش���������һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn4()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "�����ˡ�����";
	//std::string ssss = "������������ͷIAC��˾��2006��ѡַŦԼ�������������˽����ܲ���¥��IAC��˾�칫��¥��Frank Gehry�������ٵĵ�һ����������¥����ǽΪ��ɫ�����ʦ����Ĳã���ÿһ�����Χ����Ƶ���һ����ò�ͬ��һ�������ǽ��ƽ�ģ���������¥����ǽȴ���������״���ʴӽ��⿴������¥�ʲ����͡����а��������ڲ�������ⲿ���ʵ������ͳһ��������¥������������ĸ��˷�񣬵ײ��м���Ť������¥��䳲һ�������һ���ڴ�֮�ϣ�����һ��ֱ����Խ�С����¥��������¥����ȥ������ӭ��Ĵ�����";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�����ˡ�����\n    ������������ͷIAC��˾��2006��ѡַŦԼ�������������˽����ܲ���¥��IAC��˾�칫��¥��Frank Gehry�������ٵĵ�һ����������¥����ǽΪ��ɫ�����ʦ����Ĳã���ÿһ�����Χ����Ƶ���һ����ò�ͬ��һ�������ǽ��ƽ�ģ���������¥����ǽȴ���������״���ʴӽ��⿴������¥�ʲ����͡����а��������ڲ�������ⲿ���ʵ������ͳһ��������¥������������ĸ��˷�񣬵ײ��м���Ť������¥��䳲һ�������һ���ڴ�֮�ϣ�����һ��ֱ����Խ�С����¥��������¥����ȥ������ӭ��Ĵ�����"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname14()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�����ˡ�����\n    ������������ͷIAC��˾��2006��ѡַŦԼ�������������˽����ܲ���¥��IAC��˾�칫��¥��Frank Gehry�������ٵĵ�һ����������¥����ǽΪ��ɫ�����ʦ����Ĳã���ÿһ�����Χ����Ƶ���һ����ò�ͬ��һ�������ǽ��ƽ�ģ���������¥����ǽȴ���������״���ʴӽ��⿴������¥�ʲ����͡����а��������ڲ�������ⲿ���ʵ������ͳһ��������¥������������ĸ��˷�񣬵ײ��м���Ť������¥��䳲һ�������һ���ڴ�֮�ϣ�����һ��ֱ����Խ�С����¥��������¥����ȥ������ӭ��Ĵ�����"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn5()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "�õ����� ��������";
	//std::string ssss = "�����������ǲ��Գƽ���������ӵĶѻ��壬��������ʱ�У����Ű�ɫ�����¡��µ���������λ��ŦԼ���������������������в���ʿ��ס��������ƽ�����棬���������µ��������ݵ�׺����Ȼ�������������������ձ�����ʦ�õ�����������������ơ��������λ���������ȥ�Ļ�ľһ�����ʲ�������״����������ǽ����䳲������ܣ��������ʱ����ӱ�������������⡣��������1977�������ר���ղص���������Ʒ�����ڵ������ṩ��ý��������չ�ң�ר��չ�������������ù�ÿ�����6����Ҫ�ĵ�������չ����������������װ�����������⣩���Լ�5����Ҫý������չ��ŦԼ�µ��������������2007��12��1�տ��ţ���ף�����30���ꡣ����������6�����κ��ӽṹ���ӵ���ʽ��ÿһ�����Ӷ��в�ͬ��¥��������컨��߶ȣ�����Ϊ��Ӫ�첻ͬ�߶Ⱥ����յĿ��š�����չ���ռ䡣������������������������������ϼ������ѿ���������������Ƶ�������������Ư����չ������Ժ�����������̵ꡢ���ȹ��Լ��ݶ�����ȡ�";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�õ����� ��������\n    �����������ǲ��Գƽ���������ӵĶѻ��壬��������ʱ�У����Ű�ɫ�����¡��µ���������λ��ŦԼ���������������������в���ʿ��ס��������ƽ�����棬���������µ��������ݵ�׺����Ȼ�������������������ձ�����ʦ�õ�����������������ơ��������λ���������ȥ�Ļ�ľһ�����ʲ�������״����������ǽ����䳲������ܣ��������ʱ����ӱ�������������⡣��������1977�������ר���ղص���������Ʒ�����ڵ������ṩ��ý��������չ�ң�ר��չ�������������ù�ÿ�����6����Ҫ�ĵ�������չ����������������װ�����������⣩���Լ�5����Ҫý������չ��ŦԼ�µ��������������2007��12��1�տ��ţ���ף�����30���ꡣ����������6�����κ��ӽṹ���ӵ���ʽ��ÿһ�����Ӷ��в�ͬ��¥��������컨��߶ȣ�����Ϊ��Ӫ�첻ͬ�߶Ⱥ����յĿ��š�����չ���ռ䡣������������������������������ϼ������ѿ���������������Ƶ�������������Ư����չ������Ժ�����������̵ꡢ���ȹ��Լ��ݶ�����ȡ�"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname15()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�õ����� ��������\n    �����������ǲ��Գƽ���������ӵĶѻ��壬��������ʱ�У����Ű�ɫ�����¡��µ���������λ��ŦԼ���������������������в���ʿ��ס��������ƽ�����棬���������µ��������ݵ�׺����Ȼ�������������������ձ�����ʦ�õ�����������������ơ��������λ���������ȥ�Ļ�ľһ�����ʲ�������״����������ǽ����䳲������ܣ��������ʱ����ӱ�������������⡣��������1977�������ר���ղص���������Ʒ�����ڵ������ṩ��ý��������չ�ң�ר��չ�������������ù�ÿ�����6����Ҫ�ĵ�������չ����������������װ�����������⣩���Լ�5����Ҫý������չ��ŦԼ�µ��������������2007��12��1�տ��ţ���ף�����30���ꡣ����������6�����κ��ӽṹ���ӵ���ʽ��ÿһ�����Ӷ��в�ͬ��¥��������컨��߶ȣ�����Ϊ��Ӫ�첻ͬ�߶Ⱥ����յĿ��š�����չ���ռ䡣������������������������������ϼ������ѿ���������������Ƶ�������������Ư����չ������Ժ�����������̵ꡢ���ȹ��Լ��ݶ�����ȡ�"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn6()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "�ſˡ��ն����� ��÷¡ ��δδ ���˸� ��";
	//std::string ssss ="�������������񳲣�λ�ڱ�������ƥ�˹�԰�������ϲ���Ϊ2008�걱�����˻������������������ռ�����21���꣬���ڹ�����ϯԼΪ91000���������˰��˻ᡢ�а»Ὺ��Ļʽ���ﾶ����������������������˻���Ϊ�����������������������������ֵĴ���רҵ����������Ϊ�ر��Ե����������Ͱ����Ų�������������̬��ͬ���������ġ�������ҡ���������������δ����ϣ����������Ƕ��������û�����κζ���Ĵ����ѽṹ��¶���⣬�����Ȼ�γ��˽�������ۡ����������������ڰ���ƥ�˹�԰����Ⱥ������λ�ã�������΢¡�𡣡��񳲡��롰ˮ������˫��赡��񳲡��롰ˮ������˫�������ͬ�޴���������ߵ�����Ĳ����Ļ������������������������Ҹ�����Ϸ�绯�Ļ�����ۡ���۳�����״--����ͬһ������֦��֯�ɵ��񳲡���������˻����������еĹ��ܺͼ���Ҫ���ͬʱ������ϲ�û�б���Щ��ͬ�Ĺ���ǿ�������������Ĵ��Ƚṹ��������Ļ�����ס��������Ŀռ�Ч����ӱ���������ּ����ӣ��Ӷ�Ϊ2008����˻ᴴ���˶�һ�޶�����ʷ��ǰ���ĵر��Խ�����";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�ſˡ��ն����� ��÷¡ ��δδ ���˸� ��\n    �������������񳲣�λ�ڱ�������ƥ�˹�԰�������ϲ���Ϊ2008�걱�����˻������������������ռ�����21���꣬���ڹ�����ϯԼΪ91000���������˰��˻ᡢ�а»Ὺ��Ļʽ���ﾶ����������������������˻���Ϊ�����������������������������ֵĴ���רҵ����������Ϊ�ر��Ե����������Ͱ����Ų�������������̬��ͬ���������ġ�������ҡ���������������δ����ϣ����������Ƕ��������û�����κζ���Ĵ����ѽṹ��¶���⣬�����Ȼ�γ��˽�������ۡ����������������ڰ���ƥ�˹�԰����Ⱥ������λ�ã�������΢¡�𡣡��񳲡��롰ˮ������˫��赡��񳲡��롰ˮ������˫�������ͬ�޴���������ߵ�����Ĳ����Ļ������������������������Ҹ�����Ϸ�绯�Ļ�����ۡ���۳�����״--����ͬһ������֦��֯�ɵ��񳲡���������˻����������еĹ��ܺͼ���Ҫ���ͬʱ������ϲ�û�б���Щ��ͬ�Ĺ���ǿ�������������Ĵ��Ƚṹ��������Ļ�����ס��������Ŀռ�Ч����ӱ���������ּ����ӣ��Ӷ�Ϊ2008����˻ᴴ���˶�һ�޶�����ʷ��ǰ���ĵر��Խ�����"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname16()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:�ſˡ��ն����� ��÷¡ ��δδ ���˸� ��\n    �������������񳲣�λ�ڱ�������ƥ�˹�԰�������ϲ���Ϊ2008�걱�����˻������������������ռ�����21���꣬���ڹ�����ϯԼΪ91000���������˰��˻ᡢ�а»Ὺ��Ļʽ���ﾶ����������������������˻���Ϊ�����������������������������ֵĴ���רҵ����������Ϊ�ر��Ե����������Ͱ����Ų�������������̬��ͬ���������ġ�������ҡ���������������δ����ϣ����������Ƕ��������û�����κζ���Ĵ����ѽṹ��¶���⣬�����Ȼ�γ��˽�������ۡ����������������ڰ���ƥ�˹�԰����Ⱥ������λ�ã�������΢¡�𡣡��񳲡��롰ˮ������˫��赡��񳲡��롰ˮ������˫�������ͬ�޴���������ߵ�����Ĳ����Ļ������������������������Ҹ�����Ϸ�绯�Ļ�����ۡ���۳�����״--����ͬһ������֦��֯�ɵ��񳲡���������˻����������еĹ��ܺͼ���Ҫ���ͬʱ������ϲ�û�б���Щ��ͬ�Ĺ���ǿ�������������Ĵ��Ƚṹ��������Ļ�����ס��������Ŀռ�Ч����ӱ���������ּ����ӣ��Ӷ�Ϊ2008����˻ᴴ���˶�һ�޶�����ʷ��ǰ���ĵر��Խ�����"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn7()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "��ķ�����˹";
	//std::string xxx = "�������̨��ַ̨λ�ڱ����г�������������·(ԭ������Ħ��ַ��)�����ٶ������������´�¥�ش�CBD��������ռ�� 197000ƽ���ס��ܽ������Լ55��ƽ���ף���߽���234�ף����̽�����Ͷ��Լ50��Ԫ����ҡ�����������Ҫ��������¥(CCTV)�������Ļ����ģ�TVCC��������¥��ý�幫԰����Ŀ���ɺ��������̨���߱�200����ĿƵ���Ĳ����������������̨��ַ̨�н������Ǽ��Ƶ꣬CCTV��¥��Ҫ�������ֹ�����ɣ������Ǽ��Ƶ�͵����Ļ����ġ��Ƶ�������CCTV��¥�����ڡ���¥�����������Ƶ���ü��������̵ꡢ��Ӿ�صȹ���������������ϲ��ϱ�����Ϊ300��ͷ���Χ�ɵ���ͥ����¥����Ϊ�Ƶ�ķ�ζ�������������̨�ܲ���¥��¥��������¥˫������б6�ȣ���163�������ɡ�L�������۽ṹ��Ϊһ�壬���������Ĳ���Ļǽ��ǿ�ҵĲ����򼸺�ͼ����ɣ����Ͷ��ء��ṹ��ӱ�����¼����������ڹ�����������ߡ��ѡ������⡱���ش�����Ŀ��";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:��ķ�����˹\n    �������̨��ַ̨λ�ڱ����г�������������·(ԭ������Ħ��ַ��)�����ٶ������������´�¥�ش�CBD��������ռ�� 197000ƽ���ס��ܽ������Լ55��ƽ���ף���߽���234�ף����̽�����Ͷ��Լ50��Ԫ����ҡ�����������Ҫ��������¥(CCTV)�������Ļ����ģ�TVCC��������¥��ý�幫԰����Ŀ���ɺ��������̨���߱�200����ĿƵ���Ĳ����������������̨��ַ̨�н������Ǽ��Ƶ꣬CCTV��¥��Ҫ�������ֹ�����ɣ������Ǽ��Ƶ�͵����Ļ����ġ��Ƶ�������CCTV��¥�����ڡ���¥�����������Ƶ���ü��������̵ꡢ��Ӿ�صȹ���������������ϲ��ϱ�����Ϊ300��ͷ���Χ�ɵ���ͥ����¥����Ϊ�Ƶ�ķ�ζ�������������̨�ܲ���¥��¥��������¥˫������б6�ȣ���163�������ɡ�L�������۽ṹ��Ϊһ�壬���������Ĳ���Ļǽ��ǿ�ҵĲ����򼸺�ͼ����ɣ����Ͷ��ء��ṹ��ӱ�����¼����������ڹ�����������ߡ��ѡ������⡱���ش�����Ŀ��"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname17()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:��ķ�����˹\n    �������̨��ַ̨λ�ڱ����г�������������·(ԭ������Ħ��ַ��)�����ٶ������������´�¥�ش�CBD��������ռ�� 197000ƽ���ס��ܽ������Լ55��ƽ���ף���߽���234�ף����̽�����Ͷ��Լ50��Ԫ����ҡ�����������Ҫ��������¥(CCTV)�������Ļ����ģ�TVCC��������¥��ý�幫԰����Ŀ���ɺ��������̨���߱�200����ĿƵ���Ĳ����������������̨��ַ̨�н������Ǽ��Ƶ꣬CCTV��¥��Ҫ�������ֹ�����ɣ������Ǽ��Ƶ�͵����Ļ����ġ��Ƶ�������CCTV��¥�����ڡ���¥�����������Ƶ���ü��������̵ꡢ��Ӿ�صȹ���������������ϲ��ϱ�����Ϊ300��ͷ���Χ�ɵ���ͥ����¥����Ϊ�Ƶ�ķ�ζ�������������̨�ܲ���¥��¥��������¥˫������б6�ȣ���163�������ɡ�L�������۽ṹ��Ϊһ�壬���������Ĳ���Ļǽ��ǿ�ҵĲ����򼸺�ͼ����ɣ����Ͷ��ء��ṹ��ӱ�����¼����������ڹ�����������ߡ��ѡ������⡱���ش�����Ŀ��"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn8()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer  = "ʷ���ġ�����";
	//std::string ssss = "�������������MOMA(׼ȷ��˵��Ӧ���ǵ��������MOMA���ڣ�������MOMA)��������֮һ����������/�칫�������ɿ�������������10����¥������4��¥�ǰ��ϻ��ӰԺ��6��¥�ǿ��þƵ꣩����������MOMA���ǵ��������MOMA����(��������ɫ����¥���й���10��¥��ͨ�������������ӡ�������ռ��Լ6��ƽ���ף��ܽ������Լ22��ƽ���ף�����סլΪ13.5��ƽ���ף�������ҵ�����8.5��ƽ���ף�������������ӰԺ�����ȡ�ͼ��ݵ��Ļ�չ����ʩ����������Ʒ�Ƶ꣬�����׶�԰�������������������ֲ�����������Ӿ�ء�����ݵ�������ʩ��������ʩ�����������������MOMA������18��סլ¥��1�����Ǽ��Ƶ꣨�����㹫Ԣ����2��������1����ӰԺ������������ʩ�����������MOMA�ɹ������λ������ƴ�ʦ���ֹ滮��ƹ����������ձ���ɽ����԰�־�����ƣ����������˵�������Ƚ��Ľ������������������񣬾���ʱ����ɫ��";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:ʷ���ġ�����\n    �������������MOMA(׼ȷ��˵��Ӧ���ǵ��������MOMA���ڣ�������MOMA)��������֮һ����������/�칫�������ɿ�������������10����¥������4��¥�ǰ��ϻ��ӰԺ��6��¥�ǿ��þƵ꣩����������MOMA���ǵ��������MOMA����(��������ɫ����¥���й���10��¥��ͨ�������������ӡ�������ռ��Լ6��ƽ���ף��ܽ������Լ22��ƽ���ף�����סլΪ13.5��ƽ���ף�������ҵ�����8.5��ƽ���ף�������������ӰԺ�����ȡ�ͼ��ݵ��Ļ�չ����ʩ����������Ʒ�Ƶ꣬�����׶�԰�������������������ֲ�����������Ӿ�ء�����ݵ�������ʩ��������ʩ�����������������MOMA������18��סլ¥��1�����Ǽ��Ƶ꣨�����㹫Ԣ����2��������1����ӰԺ������������ʩ�����������MOMA�ɹ������λ������ƴ�ʦ���ֹ滮��ƹ����������ձ���ɽ����԰�־�����ƣ����������˵�������Ƚ��Ľ������������������񣬾���ʱ����ɫ��"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname18()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:ʷ���ġ�����\n    �������������MOMA(׼ȷ��˵��Ӧ���ǵ��������MOMA���ڣ�������MOMA)��������֮һ����������/�칫�������ɿ�������������10����¥������4��¥�ǰ��ϻ��ӰԺ��6��¥�ǿ��þƵ꣩����������MOMA���ǵ��������MOMA����(��������ɫ����¥���й���10��¥��ͨ�������������ӡ�������ռ��Լ6��ƽ���ף��ܽ������Լ22��ƽ���ף�����סլΪ13.5��ƽ���ף�������ҵ�����8.5��ƽ���ף�������������ӰԺ�����ȡ�ͼ��ݵ��Ļ�չ����ʩ����������Ʒ�Ƶ꣬�����׶�԰�������������������ֲ�����������Ӿ�ء�����ݵ�������ʩ��������ʩ�����������������MOMA������18��סլ¥��1�����Ǽ��Ƶ꣨�����㹫Ԣ����2��������1����ӰԺ������������ʩ�����������MOMA�ɹ������λ������ƴ�ʦ���ֹ滮��ƹ����������ձ���ɽ����԰�־�����ƣ����������˵�������Ƚ��Ľ������������������񣬾���ʱ����ɫ��"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn9()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer  = "���¡��޽�˹";
	//std::string xxxx = "�׶�ϣ˼�޻�����ź������2008��3��27�ս��ɡ��޴�Ĺ���֮�£�û��һ�����ӡ���5���õ�ǰ���˽���ɣ�����2008��3��27�յ���ʱ���賿4ʱ���ţ���ɺ�ϣ˹�޻����Ӵ��ĳ˿���Ŀ������9,000��Ϊ��Ӧ���ÿͣ���������ǳ��Ӵ�5��¥��ÿ������50�����򳡴󣬵��ݶ��105������������ĺ��������һ�������޹��£�2008�꽨�ɺ�������Ϊŷ�����ĵ����ｨ������ź�������������ɴ����ĳ˿ͺͻ����̻�������������˴ӻ�����ڵ��ǻ��ڵľ��롣����һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:���¡��޽�˹\n    �׶�ϣ˼�޻�����ź������2008��3��27�ս��ɡ��޴�Ĺ���֮�£�û��һ�����ӡ���5���õ�ǰ���˽���ɣ�����2008��3��27�յ���ʱ���賿4ʱ���ţ���ɺ�ϣ˹�޻����Ӵ��ĳ˿���Ŀ������9,000��Ϊ��Ӧ���ÿͣ���������ǳ��Ӵ�5��¥��ÿ������50�����򳡴󣬵��ݶ��105������������ĺ��������һ�������޹��£�2008�꽨�ɺ�������Ϊŷ�����ĵ����ｨ������ź�������������ɴ����ĳ˿ͺͻ����̻�������������˴ӻ�����ڵ��ǻ��ڵľ��롣����һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname19()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("���ʦ:���¡��޽�˹\n    �׶�ϣ˼�޻�����ź������2008��3��27�ս��ɡ��޴�Ĺ���֮�£�û��һ�����ӡ���5���õ�ǰ���˽���ɣ�����2008��3��27�յ���ʱ���賿4ʱ���ţ���ɺ�ϣ˹�޻����Ӵ��ĳ˿���Ŀ������9,000��Ϊ��Ӧ���ÿͣ���������ǳ��Ӵ�5��¥��ÿ������50�����򳡴󣬵��ݶ��105������������ĺ��������һ�������޹��£�2008�꽨�ɺ�������Ϊŷ�����ĵ����ｨ������ź�������������ɴ����ĳ˿ͺͻ����̻�������������˴ӻ�����ڵ��ǻ��ڵľ��롣����һ������ҵ�����ҵ˫�ط��ٵ���������ŵ������ִ������÷�æ�Ĺ�·�ӹ�԰�д��С���ѻ�ľһ���ġ��ѻ�����һ����¥�����ָ����Ľ���������"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn10()
{
	currentDisplayId = &introductionDisplayId;
	display();
	CString cstr=_T("���ʦ:ŵ������˹��\n");
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(cstr+_T("    ��������д�¥λ���������׶������ֳ��������������������������ﴢ�����У�CajaMadira�������ܲ�������2008�꽨�ɣ��Ѿ���Ϊ��������ߵĽ�����ý�������Ϊ��������߽���������45��¥�����ɺ�ʯ����Ȼ����˾Ҳ����פ����Ȥ���ǣ���������Դ��˾���ܲ���¥����Դ������񣬵���������¥ȴ�����ݶ��ϵķ������������Լ�����Դ���⡣��Ҳ��������ʱ������־��Ϊ2007������ʮ����֮һ������������������ִ�������Ƽ���չ�Ĳ�����Ĵ��ڴ����Ž�����Ҳ����δ����ĳһ�죬��Ҳ���ɴ����������е�һ����־�Խ�����������������һ�����ص������ƣ����ⲿ�Ľ����ṹ��λ����������а칫�ҵĵذ��Χ��������������ⲿ�Ľṹ��Ҫ֧��������������������һ�ֺ���ʽ�������ʽ����ʹ�ô�¥�����ϸ�Ϊ���ܣ���������Ҳ�ﵽ��ߡ���Ϊ���������������ܹ��и������İ칫�ռ䣬���ʦ�������ۻ�����еĽ�����ʽ�����������Ľ������ɣ�������ϵش����1200ƽ���׵�¥�塣���һ������¥�Ŀռ�㱻��������������ʯ�ͺ���Ȼ����˾����פ��ʹ���ⲿ��¥Ҳ��Ϊһ����Դ���ܲ�����������Դ�����ḻ��������¥����Դʹ��ȴ��ʮ�ֵĻ������Լ�������������Ķ�������з���ת���豸������Ϊ��¥�ṩ�൱������ĵ�����Ӧ������ݶ��ϵķ����������ȫ�����������¥����Դ���⡣"));
	m_PictureBox.Play();
	
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname20()
{
	//std::string xxxx = "��������д�¥λ���������׶������ֳ��������������������������ﴢ�����У�CajaMadira�������ܲ�������2008�꽨�ɣ��Ѿ���Ϊ��������ߵĽ�����ý�������Ϊ��������߽���������45��¥�����ɺ�ʯ����Ȼ����˾Ҳ����פ����Ȥ���ǣ���������Դ��˾���ܲ���¥����Դ������񣬵���������¥ȴ�����ݶ��ϵķ������������Լ�����Դ���⡣��Ҳ��������ʱ������־��Ϊ2007������ʮ����֮һ������������������ִ�������Ƽ���չ�Ĳ�����Ĵ��ڴ����Ž�����Ҳ����δ����ĳһ�죬��Ҳ���ɴ����������е�һ����־�Խ�����������������һ�����ص������ƣ����ⲿ�Ľ����ṹ��λ����������а칫�ҵĵذ��Χ��������������ⲿ�Ľṹ��Ҫ֧��������������������һ�ֺ���ʽ�������ʽ����ʹ�ô�¥�����ϸ�Ϊ���ܣ���������Ҳ�ﵽ��ߡ���Ϊ���������������ܹ��и������İ칫�ռ䣬���ʦ�������ۻ�����еĽ�����ʽ�����������Ľ������ɣ�������ϵش����1200ƽ���׵�¥�塣���һ������¥�Ŀռ�㱻��������������ʯ�ͺ���Ȼ����˾����פ��ʹ���ⲿ��¥Ҳ��Ϊһ����Դ���ܲ�����������Դ�����ḻ��������¥����Դʹ��ȴ��ʮ�ֵĻ������Լ�������������Ķ�������з���ת���豸������Ϊ��¥�ṩ�൱������ĵ�����Ӧ������ݶ��ϵķ����������ȫ�����������¥����Դ���⡣";
	currentDisplayId = &introductionDisplayId;
	display();
	CString cstr=_T("���ʦ:ŵ������˹��\n");
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(cstr+_T("    ��������д�¥λ���������׶������ֳ��������������������������ﴢ�����У�CajaMadira�������ܲ�������2008�꽨�ɣ��Ѿ���Ϊ��������ߵĽ�����ý�������Ϊ��������߽���������45��¥�����ɺ�ʯ����Ȼ����˾Ҳ����פ����Ȥ���ǣ���������Դ��˾���ܲ���¥����Դ������񣬵���������¥ȴ�����ݶ��ϵķ������������Լ�����Դ���⡣��Ҳ��������ʱ������־��Ϊ2007������ʮ����֮һ������������������ִ�������Ƽ���չ�Ĳ�����Ĵ��ڴ����Ž�����Ҳ����δ����ĳһ�죬��Ҳ���ɴ����������е�һ����־�Խ�����������������һ�����ص������ƣ����ⲿ�Ľ����ṹ��λ����������а칫�ҵĵذ��Χ��������������ⲿ�Ľṹ��Ҫ֧��������������������һ�ֺ���ʽ�������ʽ����ʹ�ô�¥�����ϸ�Ϊ���ܣ���������Ҳ�ﵽ��ߡ���Ϊ���������������ܹ��и������İ칫�ռ䣬���ʦ�������ۻ�����еĽ�����ʽ�����������Ľ������ɣ�������ϵش����1200ƽ���׵�¥�塣���һ������¥�Ŀռ�㱻��������������ʯ�ͺ���Ȼ����˾����פ��ʹ���ⲿ��¥Ҳ��Ϊһ����Դ���ܲ�����������Դ�����ḻ��������¥����Դʹ��ȴ��ʮ�ֵĻ������Լ�������������Ķ�������з���ת���豸������Ϊ��¥�ṩ�൱������ĵ�����Ӧ������ݶ��ϵķ����������ȫ�����������¥����Դ���⡣"));
	m_PictureBox.Play();
	
}



void CFutureBuildingDlg::OnClose()
{
	m_PictureBox.Stop();
	m_PictureBox.Destroy();
	CDialogEx::OnClose();
}


HBRUSH CFutureBuildingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if(pWnd->GetDlgCtrlID() == IDC_STATIC_INTRODUCTION)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&m_fontIntroduction);
		pDC->SetTextColor(RGB(255,0,0));
		hbr=(HBRUSH)GetStockObject(NULL_BRUSH);   
	}
	return hbr;
}

void CFutureBuildingDlg::display()
{
	vector<int>::iterator iterAll;
	vector<int>::iterator iterCurrent;
	bool shouldShow;
	for(iterAll = allDisplayId.begin();iterAll!=allDisplayId.end();++iterAll)
	{
		shouldShow = false;
		if(currentDisplayId!=NULL){
			for(iterCurrent = currentDisplayId->begin();iterCurrent!=currentDisplayId->end();++iterCurrent)
			{
				if(*iterAll==*iterCurrent)
				{
					shouldShow = true;
					break;
				}
			}
		}
		if(shouldShow)
		{
			GetDlgItem(*iterAll)->ShowWindow(SW_SHOW);
		}else
		{
			GetDlgItem(*iterAll)->ShowWindow(SW_HIDE);
		}
	}

}

void CFutureBuildingDlg::OnBnClickedButton1()
{
	//MessageBox(_T("OK"));
	m_PictureBox.Stop();
	currentDisplayId = &chooseDisplayId;
	display();
}


BOOL CFutureBuildingDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	CMyMemDC pDevC(pDC, rect);
	if (m_hBitmap)
	{
		pDevC->SelectObject(m_hBitmap);
	}
	SetButtonBackGrounds(pDevC);


	return CDialogEx::OnEraseBkgnd(pDC);
}

void CFutureBuildingDlg::SetButtonBackGrounds(CDC *pDC){
	m_btnBack.SetBkGnd(pDC);
}
