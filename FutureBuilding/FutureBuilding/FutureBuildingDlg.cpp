
// FutureBuildingDlg.cpp : 实现文件
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


// CFutureBuildingDlg 对话框




CFutureBuildingDlg::CFutureBuildingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFutureBuildingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//1.所有显示元素
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


// CFutureBuildingDlg 消息处理程序

BOOL CFutureBuildingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// Initialize CImageBox
	m_PictureBox.Create();
	// 动画类型
	m_PictureBox.SetAnimationType(CImageBox::kAnimationCoverLeft);
	// 动画过渡时间(ms)
	m_PictureBox.SetDuration(400);
	// 每张图片停留时间
	m_PictureBox.SetRetention(2000);
	m_PictureBox.AddImage(TEXT("images\\1.jpg"));
	m_PictureBox.AddImage(TEXT("images\\2.jpg"));
	m_PictureBox.AddImage(TEXT("images\\3.jpg"));
	m_PictureBox.AddImage(TEXT("images\\4.jpg"));
	m_PictureBox.AddImage(TEXT("images\\5.jpg"));
	m_PictureBox.AddImage(TEXT("images\\6.jpg"));
	m_PictureBox.AddImage(TEXT("images\\7.jpg"));
	m_PictureBox.AddImage(TEXT("images\\8.jpg"));

	//设置字体
	m_fontIntroduction.CreatePointFont(350,_T("华文行楷"));

	m_btnBack.LoadStdImage(IDB_PNG_BACK, -1, _T("PNG"));
	HBITMAP		hBitmap			= NULL;
	HINSTANCE	hInstResource	= NULL;
	hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND), RT_BITMAP);
	m_hBitmap = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND), IMAGE_BITMAP, 0, 0, 0);

	currentDisplayId = &chooseDisplayId;

	display();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFutureBuildingDlg::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	CRect rect;

	GetClientRect(&rect);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
	
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	//-------------------------------设置背景图片
	CBitmap     bmp;

	bmp.LoadBitmap(IDB_BITMAP_BACKGROUND);

	CDC dcMemory;

	dcMemory.CreateCompatibleDC(&dc);

	dcMemory.SelectObject(&bmp);

	dc.BitBlt(rect.left,rect.top,rect.right,rect.bottom,&dcMemory,0,0,SRCCOPY);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFutureBuildingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFutureBuildingDlg::OnStnClickedStaticBuildname11()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:史蒂文·霍尔\n    布洛克新翼大楼耗资9,500万美元（约7.4亿港元）兴建，2007年6月9日揭幕，收藏当代和非洲艺术品、摄影作品以及特别馆藏。新翼还包括了一座咖啡厅和参考图书馆。纳阿氏艺术馆建筑风格为新式古典派。这次获选为《时代》周刊2007年度十大最佳建筑首位的，是馆内新建的布洛克大楼。馆方于1993年开始构思扩建，目标是要增加艺术馆面积55%。扩建计划于1999年落实，建筑师霍尔把新翼设计成楼底高度不一，并且令大楼发光，《时代》周刊形容布洛克新翼是古典派建筑的宏伟新猷。美国密苏里州堪萨斯城纳尔逊艺术馆扩建配楼。大楼由几个不规则的白色立方体组成。每到夜间，灯光从外墙上半透明和透明的玻璃中透出，好似建筑由内至外发出柔和的白色光芒，使这座新古典主义艺术博物馆更具现代气息。被美国《时代》杂志评为2007年世界十大建筑之首。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn1()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "史蒂文·霍尔";
	//std::string ssss = "布洛克新翼大楼耗资9,500万美元（约7.4亿港元）兴建，2007年6月9日揭幕，收藏当代和非洲艺术品、摄影作品以及特别馆藏。新翼还包括了一座咖啡厅和参考图书馆。纳阿氏艺术馆建筑风格为新式古典派。这次获选为《时代》周刊2007年度十大最佳建筑首位的，是馆内新建的布洛克大楼。馆方于1993年开始构思扩建，目标是要增加艺术馆面积55%。扩建计划于1999年落实，建筑师霍尔把新翼设计成楼底高度不一，并且令大楼发光，《时代》周刊形容布洛克新翼是古典派建筑的宏伟新猷。美国密苏里州堪萨斯城纳尔逊艺术馆扩建配楼。大楼由几个不规则的白色立方体组成。每到夜间，灯光从外墙上半透明和透明的玻璃中透出，好似建筑由内至外发出柔和的白色光芒，使这座新古典主义艺术博物馆更具现代气息。被美国《时代》杂志评为2007年世界十大建筑之首。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:史蒂文·霍尔\n    布洛克新翼大楼耗资9,500万美元（约7.4亿港元）兴建，2007年6月9日揭幕，收藏当代和非洲艺术品、摄影作品以及特别馆藏。新翼还包括了一座咖啡厅和参考图书馆。纳阿氏艺术馆建筑风格为新式古典派。这次获选为《时代》周刊2007年度十大最佳建筑首位的，是馆内新建的布洛克大楼。馆方于1993年开始构思扩建，目标是要增加艺术馆面积55%。扩建计划于1999年落实，建筑师霍尔把新翼设计成楼底高度不一，并且令大楼发光，《时代》周刊形容布洛克新翼是古典派建筑的宏伟新猷。美国密苏里州堪萨斯城纳尔逊艺术馆扩建配楼。大楼由几个不规则的白色立方体组成。每到夜间，灯光从外墙上半透明和透明的玻璃中透出，好似建筑由内至外发出柔和的白色光芒，使这座新古典主义艺术博物馆更具现代气息。被美国《时代》杂志评为2007年世界十大建筑之首。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn2()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "莫菲西斯 汤姆·梅恩";
	//std::string ssss = "旧金山新联邦大楼位于美国加利福利亚州旧金山市区，该建筑有18层办公楼，高71米。大堂楼层开始往上设有「百叶帘」般的外墙设计，配以网眼钢板，《时代》周刊形容大楼设计技术精湛。这座大楼不仅在外形上给人极强的视觉冲击，还是座完完全全的环保建筑，其耗能是同类型大楼耗能的一半。大楼朝南一面装有穿孔金属板，它们既是整栋大楼外观设计的一部分，也是实用的遮阳屏，能够在挡住直射阳光的同时，为大楼内的办公室提供温和的采光，即使离窗户最远的座位也能享受到自然光。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:莫菲西斯 汤姆·梅恩\n    旧金山新联邦大楼位于美国加利福利亚州旧金山市区，该建筑有18层办公楼，高71米。大堂楼层开始往上设有「百叶帘」般的外墙设计，配以网眼钢板，《时代》周刊形容大楼设计技术精湛。这座大楼不仅在外形上给人极强的视觉冲击，还是座完完全全的环保建筑，其耗能是同类型大楼耗能的一半。大楼朝南一面装有穿孔金属板，它们既是整栋大楼外观设计的一部分，也是实用的遮阳屏，能够在挡住直射阳光的同时，为大楼内的办公室提供温和的采光，即使离窗户最远的座位也能享受到自然光。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname12()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:莫菲西斯 汤姆·梅恩\n    旧金山新联邦大楼位于美国加利福利亚州旧金山市区，该建筑有18层办公楼，高71米。大堂楼层开始往上设有「百叶帘」般的外墙设计，配以网眼钢板，《时代》周刊形容大楼设计技术精湛。这座大楼不仅在外形上给人极强的视觉冲击，还是座完完全全的环保建筑，其耗能是同类型大楼耗能的一半。大楼朝南一面装有穿孔金属板，它们既是整栋大楼外观设计的一部分，也是实用的遮阳屏，能够在挡住直射阳光的同时，为大楼内的办公室提供温和的采光，即使离窗户最远的座位也能享受到自然光。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn3()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "Weiss/Manfredi";
	//std::string ssss = "西雅图艺术博物馆将其雕塑公园建于一个旧工业区内，一条繁忙的公路和铁路穿越其间。奥运雕塑公园位于滨海公路和铁路线中间的空地，据悉1970年代以前，公园所在地为石油公司优尼科（加州联合石油）占有。优尼科迁出后，该地皮因地下藏有有毒物质，长年丢空。后来西雅图艺术馆建议把该空置用地改建成公园，以解决西雅图闹市区中缺乏休憩用地的问题。该公园摆放的部分大型雕塑设有行人径，参观者可于雕塑上行走。此外，公园亦会不时展出非常设雕塑，《时代》周刊形容公园将自然和艺术与城市糅合起来，成为西雅图的「动能地带」。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:Weiss/Manfredi\n    西雅图艺术博物馆将其雕塑公园建于一个旧工业区内，一条繁忙的公路和铁路穿越其间。奥运雕塑公园位于滨海公路和铁路线中间的空地，据悉1970年代以前，公园所在地为石油公司优尼科（加州联合石油）占有。优尼科迁出后，该地皮因地下藏有有毒物质，长年丢空。后来西雅图艺术馆建议把该空置用地改建成公园，以解决西雅图闹市区中缺乏休憩用地的问题。该公园摆放的部分大型雕塑设有行人径，参观者可于雕塑上行走。此外，公园亦会不时展出非常设雕塑，《时代》周刊形容公园将自然和艺术与城市糅合起来，成为西雅图的「动能地带」。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname13()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:Weiss/Manfredi\n    西雅图艺术博物馆将其雕塑公园建于一个旧工业区内，一条繁忙的公路和铁路穿越其间。奥运雕塑公园位于滨海公路和铁路线中间的空地，据悉1970年代以前，公园所在地为石油公司优尼科（加州联合石油）占有。优尼科迁出后，该地皮因地下藏有有毒物质，长年丢空。后来西雅图艺术馆建议把该空置用地改建成公园，以解决西雅图闹市区中缺乏休憩用地的问题。该公园摆放的部分大型雕塑设有行人径，参观者可于雕塑上行走。此外，公园亦会不时展出非常设雕塑，《时代》周刊形容公园将自然和艺术与城市糅合起来，成为西雅图的「动能地带」。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn4()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "弗兰克·盖里";
	//std::string ssss = "美国因特网巨头IAC公司于2006年选址纽约曼哈顿西区，兴建其总部大楼。IAC公司办公大楼是Frank Gehry在曼哈顿的第一个建筑，大楼的外墙为白色，设计师别出心裁，把每一层的外围都设计得与一般大厦不同。一般大厦外墙是平的，但这座大楼的外墙却呈延绵起伏状，故从街外看整座大楼呈波浪型。蛇行般线条让内部设计与外部设计实现完美统一。这座大楼彰显了许多盖里的个人风格，底部有几个扭曲的塔楼像蜂巢一样结合在一起，在此之上，是另一组直径相对较小的塔楼。整座大楼看上去就像是迎风的船帆。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:弗兰克·盖里\n    美国因特网巨头IAC公司于2006年选址纽约曼哈顿西区，兴建其总部大楼。IAC公司办公大楼是Frank Gehry在曼哈顿的第一个建筑，大楼的外墙为白色，设计师别出心裁，把每一层的外围都设计得与一般大厦不同。一般大厦外墙是平的，但这座大楼的外墙却呈延绵起伏状，故从街外看整座大楼呈波浪型。蛇行般线条让内部设计与外部设计实现完美统一。这座大楼彰显了许多盖里的个人风格，底部有几个扭曲的塔楼像蜂巢一样结合在一起，在此之上，是另一组直径相对较小的塔楼。整座大楼看上去就像是迎风的船帆。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname14()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:弗兰克·盖里\n    美国因特网巨头IAC公司于2006年选址纽约曼哈顿西区，兴建其总部大楼。IAC公司办公大楼是Frank Gehry在曼哈顿的第一个建筑，大楼的外墙为白色，设计师别出心裁，把每一层的外围都设计得与一般大厦不同。一般大厦外墙是平的，但这座大楼的外墙却呈延绵起伏状，故从街外看整座大楼呈波浪型。蛇行般线条让内部设计与外部设计实现完美统一。这座大楼彰显了许多盖里的个人风格，底部有几个扭曲的塔楼像蜂巢一样结合在一起，在此之上，是另一组直径相对较小的塔楼。整座大楼看上去就像是迎风的船帆。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn5()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "妹岛和世 西泽立卫";
	//std::string ssss = "这座建筑像是不对称金属网格盒子的堆积体，造型新奇时尚，裹着白色的外衣。新当代艺术馆位于纽约曼哈顿下区，该区多由中产人士居住，看起来平凡无奇，但经这座新当代艺术馆点缀，顿然活泼起来。艺术馆由日本建筑师妹岛和世及西泽立卫设计。大厦外形活像随便叠上去的积木一样，呈不规则形状。艺术馆外墙有如蜂巢般的铝架，形容设计时髦新颖，而且闪闪生光。艺术馆于1977年成立，专门收藏当代艺术作品，并在地下室提供了媒体艺术特展室，专门展出数码艺术。该馆每年会有6个主要的当代艺术展（包括抽象艺术、装置艺术等主题），以及5个主要媒体艺术展。纽约新当代艺术博物馆在2007年12月1日开放，庆祝其成立30周年。建筑采用了6座矩形盒子结构叠加的形式，每一座盒子都有不同的楼层面积和天花板高度，这是为了营造不同高度和气氛的开放、灵活的展览空间。建筑外面用铝质网格包裹，从立面上几乎很难看到窗户。他们设计的这座建筑有着漂亮的展厅、剧院、教育区、商店、咖啡馆以及屋顶活动区等。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:妹岛和世 西泽立卫\n    这座建筑像是不对称金属网格盒子的堆积体，造型新奇时尚，裹着白色的外衣。新当代艺术馆位于纽约曼哈顿下区，该区多由中产人士居住，看起来平凡无奇，但经这座新当代艺术馆点缀，顿然活泼起来。艺术馆由日本建筑师妹岛和世及西泽立卫设计。大厦外形活像随便叠上去的积木一样，呈不规则形状。艺术馆外墙有如蜂巢般的铝架，形容设计时髦新颖，而且闪闪生光。艺术馆于1977年成立，专门收藏当代艺术作品，并在地下室提供了媒体艺术特展室，专门展出数码艺术。该馆每年会有6个主要的当代艺术展（包括抽象艺术、装置艺术等主题），以及5个主要媒体艺术展。纽约新当代艺术博物馆在2007年12月1日开放，庆祝其成立30周年。建筑采用了6座矩形盒子结构叠加的形式，每一座盒子都有不同的楼层面积和天花板高度，这是为了营造不同高度和气氛的开放、灵活的展览空间。建筑外面用铝质网格包裹，从立面上几乎很难看到窗户。他们设计的这座建筑有着漂亮的展厅、剧院、教育区、商店、咖啡馆以及屋顶活动区等。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname15()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:妹岛和世 西泽立卫\n    这座建筑像是不对称金属网格盒子的堆积体，造型新奇时尚，裹着白色的外衣。新当代艺术馆位于纽约曼哈顿下区，该区多由中产人士居住，看起来平凡无奇，但经这座新当代艺术馆点缀，顿然活泼起来。艺术馆由日本建筑师妹岛和世及西泽立卫设计。大厦外形活像随便叠上去的积木一样，呈不规则形状。艺术馆外墙有如蜂巢般的铝架，形容设计时髦新颖，而且闪闪生光。艺术馆于1977年成立，专门收藏当代艺术作品，并在地下室提供了媒体艺术特展室，专门展出数码艺术。该馆每年会有6个主要的当代艺术展（包括抽象艺术、装置艺术等主题），以及5个主要媒体艺术展。纽约新当代艺术博物馆在2007年12月1日开放，庆祝其成立30周年。建筑采用了6座矩形盒子结构叠加的形式，每一座盒子都有不同的楼层面积和天花板高度，这是为了营造不同高度和气氛的开放、灵活的展览空间。建筑外面用铝质网格包裹，从立面上几乎很难看到窗户。他们设计的这座建筑有着漂亮的展厅、剧院、教育区、商店、咖啡馆以及屋顶活动区等。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn6()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer =  "雅克·赫尔佐格 德梅隆 艾未未 李兴刚 等";
	//std::string ssss ="国家体育场（鸟巢）位于北京奥林匹克公园中心区南部，为2008年北京奥运会的主体育场。工程总占地面积21公顷，场内观众坐席约为91000个。举行了奥运会、残奥会开闭幕式、田径比赛及足球比赛决赛。奥运会后成为北京市民参与体育活动及享受体育娱乐的大型专业场所，并成为地标性的体育建筑和奥运遗产。体育场的形态如同孕育生命的“巢”和摇篮，寄托着人类对未来的希望。设计者们对这个场馆没有做任何多余的处理，把结构暴露在外，因而自然形成了建筑的外观。国家体育场坐落于奥林匹克公园建筑群的中央位置，地势略微隆起。“鸟巢”与“水立方”双连璧“鸟巢”与“水立方”双连璧它如同巨大的容器。高低起伏的波动的基座缓和了容器的体量，而且给了它戏剧化的弧形外观。汇聚成网格状--就如同一个由树枝编织成的鸟巢。在满足奥运会体育场所有的功能和技术要求的同时，设计上并没有被那些类同的过于强调建筑技术化的大跨度结构和数码屏幕所主宰。体育场的空间效果新颖激进，但又简洁古朴，从而为2008年奥运会创造了独一无二而又史无前例的地标性建筑。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:雅克·赫尔佐格 德梅隆 艾未未 李兴刚 等\n    国家体育场（鸟巢）位于北京奥林匹克公园中心区南部，为2008年北京奥运会的主体育场。工程总占地面积21公顷，场内观众坐席约为91000个。举行了奥运会、残奥会开闭幕式、田径比赛及足球比赛决赛。奥运会后成为北京市民参与体育活动及享受体育娱乐的大型专业场所，并成为地标性的体育建筑和奥运遗产。体育场的形态如同孕育生命的“巢”和摇篮，寄托着人类对未来的希望。设计者们对这个场馆没有做任何多余的处理，把结构暴露在外，因而自然形成了建筑的外观。国家体育场坐落于奥林匹克公园建筑群的中央位置，地势略微隆起。“鸟巢”与“水立方”双连璧“鸟巢”与“水立方”双连璧它如同巨大的容器。高低起伏的波动的基座缓和了容器的体量，而且给了它戏剧化的弧形外观。汇聚成网格状--就如同一个由树枝编织成的鸟巢。在满足奥运会体育场所有的功能和技术要求的同时，设计上并没有被那些类同的过于强调建筑技术化的大跨度结构和数码屏幕所主宰。体育场的空间效果新颖激进，但又简洁古朴，从而为2008年奥运会创造了独一无二而又史无前例的地标性建筑。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname16()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:雅克·赫尔佐格 德梅隆 艾未未 李兴刚 等\n    国家体育场（鸟巢）位于北京奥林匹克公园中心区南部，为2008年北京奥运会的主体育场。工程总占地面积21公顷，场内观众坐席约为91000个。举行了奥运会、残奥会开闭幕式、田径比赛及足球比赛决赛。奥运会后成为北京市民参与体育活动及享受体育娱乐的大型专业场所，并成为地标性的体育建筑和奥运遗产。体育场的形态如同孕育生命的“巢”和摇篮，寄托着人类对未来的希望。设计者们对这个场馆没有做任何多余的处理，把结构暴露在外，因而自然形成了建筑的外观。国家体育场坐落于奥林匹克公园建筑群的中央位置，地势略微隆起。“鸟巢”与“水立方”双连璧“鸟巢”与“水立方”双连璧它如同巨大的容器。高低起伏的波动的基座缓和了容器的体量，而且给了它戏剧化的弧形外观。汇聚成网格状--就如同一个由树枝编织成的鸟巢。在满足奥运会体育场所有的功能和技术要求的同时，设计上并没有被那些类同的过于强调建筑技术化的大跨度结构和数码屏幕所主宰。体育场的空间效果新颖激进，但又简洁古朴，从而为2008年奥运会创造了独一无二而又史无前例的地标性建筑。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn7()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer = "雷姆·库哈斯";
	//std::string xxx = "中央电视台新台址位于北京市朝阳区东三环中路(原“北汽摩厂址”)，紧临东三环，央视新大楼地处CBD核心区，占地 197000平方米。总建筑面积约55万平方米，最高建筑234米，工程建安总投资约50亿元人民币。建设内容主要包括：主楼(CCTV)、电视文化中心（TVCC）、服务楼及媒体公园。项目建成后，中央电视台将具备200个节目频道的播出能力。中央电视台新台址中将建五星级酒店，CCTV大楼主要由两部分功能组成，即五星级酒店和电视文化中心。酒店设置在CCTV大楼主体内。大楼的四五层内设酒店大堂及餐厅、商店、游泳池等公共活动场所。大堂上部南北两侧为300间客房合围成的中庭，主楼顶部为酒店的风味餐厅。中央电视台总部大楼主楼的两座塔楼双向内倾斜6度，在163米以上由“L”形悬臂结构连为一体，建筑外表面的玻璃幕墙由强烈的不规则几何图案组成，造型独特、结构新颖、高新技术含量大，在国内外均属“高、难、精、尖”的特大型项目。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:雷姆·库哈斯\n    中央电视台新台址位于北京市朝阳区东三环中路(原“北汽摩厂址”)，紧临东三环，央视新大楼地处CBD核心区，占地 197000平方米。总建筑面积约55万平方米，最高建筑234米，工程建安总投资约50亿元人民币。建设内容主要包括：主楼(CCTV)、电视文化中心（TVCC）、服务楼及媒体公园。项目建成后，中央电视台将具备200个节目频道的播出能力。中央电视台新台址中将建五星级酒店，CCTV大楼主要由两部分功能组成，即五星级酒店和电视文化中心。酒店设置在CCTV大楼主体内。大楼的四五层内设酒店大堂及餐厅、商店、游泳池等公共活动场所。大堂上部南北两侧为300间客房合围成的中庭，主楼顶部为酒店的风味餐厅。中央电视台总部大楼主楼的两座塔楼双向内倾斜6度，在163米以上由“L”形悬臂结构连为一体，建筑外表面的玻璃幕墙由强烈的不规则几何图案组成，造型独特、结构新颖、高新技术含量大，在国内外均属“高、难、精、尖”的特大型项目。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname17()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:雷姆·库哈斯\n    中央电视台新台址位于北京市朝阳区东三环中路(原“北汽摩厂址”)，紧临东三环，央视新大楼地处CBD核心区，占地 197000平方米。总建筑面积约55万平方米，最高建筑234米，工程建安总投资约50亿元人民币。建设内容主要包括：主楼(CCTV)、电视文化中心（TVCC）、服务楼及媒体公园。项目建成后，中央电视台将具备200个节目频道的播出能力。中央电视台新台址中将建五星级酒店，CCTV大楼主要由两部分功能组成，即五星级酒店和电视文化中心。酒店设置在CCTV大楼主体内。大楼的四五层内设酒店大堂及餐厅、商店、游泳池等公共活动场所。大堂上部南北两侧为300间客房合围成的中庭，主楼顶部为酒店的风味餐厅。中央电视台总部大楼主楼的两座塔楼双向内倾斜6度，在163米以上由“L”形悬臂结构连为一体，建筑外表面的玻璃幕墙由强烈的不规则几何图案组成，造型独特、结构新颖、高新技术含量大，在国内外均属“高、难、精、尖”的特大型项目。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn8()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer  = "史蒂文·霍尔";
	//std::string ssss = "北京当代万国城MOMA(准确的说，应该是当代万国城MOMA四期，即当代MOMA)就是其中之一。这座零售/办公建筑将由空中连廊连接其10座塔楼（其中4号楼是百老汇电影院，6号楼是凯悦酒店）。北京当代MOMA，是当代万国城MOMA四期(即北区白色联体楼）有共计10栋楼，通过空中连廊连接。建筑总占地约6万平方米，总建筑面积约22万平方米（其中住宅为13.5万平方米，配套商业面积达8.5万平方米，包括多厅艺术影院、画廊、图书馆等文化展览设施，还包括精品酒店，国际幼儿园，顶级餐饮，顶级俱乐部及健身房、游泳池、玩球馆等生活设施与休闲设施）。北京当代万国城MOMA，共有18栋住宅楼、1栋五星级酒店（含顶层公寓）、2个会所、1个电影院及其他配套设施。当代万国城MOMA由国内外多位著名设计大师主持规划设计工作，并由日本秋山宽负责园林景观设计，建筑吸收了当今国际先进的建筑艺术，体现民族风格，具有时代特色。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:史蒂文·霍尔\n    北京当代万国城MOMA(准确的说，应该是当代万国城MOMA四期，即当代MOMA)就是其中之一。这座零售/办公建筑将由空中连廊连接其10座塔楼（其中4号楼是百老汇电影院，6号楼是凯悦酒店）。北京当代MOMA，是当代万国城MOMA四期(即北区白色联体楼）有共计10栋楼，通过空中连廊连接。建筑总占地约6万平方米，总建筑面积约22万平方米（其中住宅为13.5万平方米，配套商业面积达8.5万平方米，包括多厅艺术影院、画廊、图书馆等文化展览设施，还包括精品酒店，国际幼儿园，顶级餐饮，顶级俱乐部及健身房、游泳池、玩球馆等生活设施与休闲设施）。北京当代万国城MOMA，共有18栋住宅楼、1栋五星级酒店（含顶层公寓）、2个会所、1个电影院及其他配套设施。当代万国城MOMA由国内外多位著名设计大师主持规划设计工作，并由日本秋山宽负责园林景观设计，建筑吸收了当今国际先进的建筑艺术，体现民族风格，具有时代特色。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname18()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:史蒂文·霍尔\n    北京当代万国城MOMA(准确的说，应该是当代万国城MOMA四期，即当代MOMA)就是其中之一。这座零售/办公建筑将由空中连廊连接其10座塔楼（其中4号楼是百老汇电影院，6号楼是凯悦酒店）。北京当代MOMA，是当代万国城MOMA四期(即北区白色联体楼）有共计10栋楼，通过空中连廊连接。建筑总占地约6万平方米，总建筑面积约22万平方米（其中住宅为13.5万平方米，配套商业面积达8.5万平方米，包括多厅艺术影院、画廊、图书馆等文化展览设施，还包括精品酒店，国际幼儿园，顶级餐饮，顶级俱乐部及健身房、游泳池、玩球馆等生活设施与休闲设施）。北京当代万国城MOMA，共有18栋住宅楼、1栋五星级酒店（含顶层公寓）、2个会所、1个电影院及其他配套设施。当代万国城MOMA由国内外多位著名设计大师主持规划设计工作，并由日本秋山宽负责园林景观设计，建筑吸收了当今国际先进的建筑艺术，体现民族风格，具有时代特色。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn9()
{
	currentDisplayId = &introductionDisplayId;
	display();
	//std::string designer  = "理查德·罗杰斯";
	//std::string xxxx = "伦敦希思罗机场五号候机厅，2008年3月27日建成。巨大的拱顶之下，没有一根柱子。第5航厦当前已兴建完成，且于2008年3月27日当地时间凌晨4时开放，落成后希斯罗机场接待的乘客数目提升至9,000万。为了应付旅客，航厦面积非常庞大，5层楼，每层足有50个足球场大，电梯多达105部。这个新增的候机厅建在一个无柱巨拱下，2008年建成后，它将成为欧洲最大的单顶棚建筑。五号候机厅不仅能容纳大量的乘客和机场商户，还大大缩短了从机场入口到登机口的距离。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。";
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:理查德·罗杰斯\n    伦敦希思罗机场五号候机厅，2008年3月27日建成。巨大的拱顶之下，没有一根柱子。第5航厦当前已兴建完成，且于2008年3月27日当地时间凌晨4时开放，落成后希斯罗机场接待的乘客数目提升至9,000万。为了应付旅客，航厦面积非常庞大，5层楼，每层足有50个足球场大，电梯多达105部。这个新增的候机厅建在一个无柱巨拱下，2008年建成后，它将成为欧洲最大的单顶棚建筑。五号候机厅不仅能容纳大量的乘客和机场商户，还大大缩短了从机场入口到登机口的距离。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname19()
{
	currentDisplayId = &introductionDisplayId;
	display();
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(_T("设计师:理查德·罗杰斯\n    伦敦希思罗机场五号候机厅，2008年3月27日建成。巨大的拱顶之下，没有一根柱子。第5航厦当前已兴建完成，且于2008年3月27日当地时间凌晨4时开放，落成后希斯罗机场接待的乘客数目提升至9,000万。为了应付旅客，航厦面积非常庞大，5层楼，每层足有50个足球场大，电梯多达105部。这个新增的候机厅建在一个无柱巨拱下，2008年建成后，它将成为欧洲最大的单顶棚建筑。五号候机厅不仅能容纳大量的乘客和机场商户，还大大缩短了从机场入口到登机口的距离。这是一个建筑业和设计业双重繁荣的年代，将古典主义现代化、让繁忙的公路从公园中穿行、像堆积木一样的“堆积”成一个大楼，各种各样的建筑层出不穷。"));
	m_PictureBox.Play();
}


void CFutureBuildingDlg::OnStnClickedStaticBtn10()
{
	currentDisplayId = &introductionDisplayId;
	display();
	CString cstr=_T("设计师:诺曼·福斯特\n");
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(cstr+_T("    马德里银行大楼位于西班牙首都马德里，又称马德里银行塔，是西班牙马德里储蓄银行（CajaMadira）的新总部。它于2008年建成，已经成为西班牙最高的建筑物。该建筑将成为西班牙最高建筑。它有45层楼，建成后石油天然气公司也将入驻。有趣的是，尽管是能源公司的总部大楼，能源储备丰厚，但是这座大楼却是用屋顶上的风力发电机解决自己的能源问题。它也被美国《时代》杂志评为2007年世界十大建筑之一。马德里银行塔，是现代文明与科技发展的产物，它的存在代表着进步。也许，在未来的某一天，它也会变成代表这座城市的一个标志性建筑。这座银行塔有一个独特的外观设计，它外部的建筑结构将位于中央的所有办公室的地板包围起来，而且这个外部的结构还要支撑整个塔的重量。这是一种合作式的设计形式，这使得大楼整体结合更为紧密，负重能力也达到最高。而为了让这座银行塔能够有更加灵活的办公空间，设计师借鉴了香港汇丰银行的建筑样式，采用了它的建筑技巧，即不间断地创造出1200平方米的楼板。如此一来，大楼的空间便被灵活地利用起来。石油和天然气公司的入驻，使得这部大楼也成为一个能源的总部。但尽管能源储备丰富，这座大楼的能源使用却是十分的环保与节约。在这所建筑的顶部设计有风力转化设备，可以为大楼提供相当大比例的电力供应，这个屋顶上的风力发电机完全有能力解决大楼的能源问题。"));
	m_PictureBox.Play();
	
}


void CFutureBuildingDlg::OnStnClickedStaticBuildname20()
{
	//std::string xxxx = "马德里银行大楼位于西班牙首都马德里，又称马德里银行塔，是西班牙马德里储蓄银行（CajaMadira）的新总部。它于2008年建成，已经成为西班牙最高的建筑物。该建筑将成为西班牙最高建筑。它有45层楼，建成后石油天然气公司也将入驻。有趣的是，尽管是能源公司的总部大楼，能源储备丰厚，但是这座大楼却是用屋顶上的风力发电机解决自己的能源问题。它也被美国《时代》杂志评为2007年世界十大建筑之一。马德里银行塔，是现代文明与科技发展的产物，它的存在代表着进步。也许，在未来的某一天，它也会变成代表这座城市的一个标志性建筑。这座银行塔有一个独特的外观设计，它外部的建筑结构将位于中央的所有办公室的地板包围起来，而且这个外部的结构还要支撑整个塔的重量。这是一种合作式的设计形式，这使得大楼整体结合更为紧密，负重能力也达到最高。而为了让这座银行塔能够有更加灵活的办公空间，设计师借鉴了香港汇丰银行的建筑样式，采用了它的建筑技巧，即不间断地创造出1200平方米的楼板。如此一来，大楼的空间便被灵活地利用起来。石油和天然气公司的入驻，使得这部大楼也成为一个能源的总部。但尽管能源储备丰富，这座大楼的能源使用却是十分的环保与节约。在这所建筑的顶部设计有风力转化设备，可以为大楼提供相当大比例的电力供应，这个屋顶上的风力发电机完全有能力解决大楼的能源问题。";
	currentDisplayId = &introductionDisplayId;
	display();
	CString cstr=_T("设计师:诺曼·福斯特\n");
	GetDlgItem(IDC_STATIC_INTRODUCTION)->SetWindowText(cstr+_T("    马德里银行大楼位于西班牙首都马德里，又称马德里银行塔，是西班牙马德里储蓄银行（CajaMadira）的新总部。它于2008年建成，已经成为西班牙最高的建筑物。该建筑将成为西班牙最高建筑。它有45层楼，建成后石油天然气公司也将入驻。有趣的是，尽管是能源公司的总部大楼，能源储备丰厚，但是这座大楼却是用屋顶上的风力发电机解决自己的能源问题。它也被美国《时代》杂志评为2007年世界十大建筑之一。马德里银行塔，是现代文明与科技发展的产物，它的存在代表着进步。也许，在未来的某一天，它也会变成代表这座城市的一个标志性建筑。这座银行塔有一个独特的外观设计，它外部的建筑结构将位于中央的所有办公室的地板包围起来，而且这个外部的结构还要支撑整个塔的重量。这是一种合作式的设计形式，这使得大楼整体结合更为紧密，负重能力也达到最高。而为了让这座银行塔能够有更加灵活的办公空间，设计师借鉴了香港汇丰银行的建筑样式，采用了它的建筑技巧，即不间断地创造出1200平方米的楼板。如此一来，大楼的空间便被灵活地利用起来。石油和天然气公司的入驻，使得这部大楼也成为一个能源的总部。但尽管能源储备丰富，这座大楼的能源使用却是十分的环保与节约。在这所建筑的顶部设计有风力转化设备，可以为大楼提供相当大比例的电力供应，这个屋顶上的风力发电机完全有能力解决大楼的能源问题。"));
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
