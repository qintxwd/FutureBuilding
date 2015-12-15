
// FutureBuildingDlg.h : 头文件
//

#pragma once
#include "imagebox.h"

#include <vector>
#include "MyButton.h"
using namespace std;

// CFutureBuildingDlg 对话框
class CFutureBuildingDlg : public CDialogEx
{
// 构造
public:
	CFutureBuildingDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FUTUREBUILDING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticBuildname11();
	afx_msg void OnStnClickedStaticBtn1();
	afx_msg void OnStnClickedStaticBtn2();
	afx_msg void OnStnClickedStaticBuildname12();
	afx_msg void OnStnClickedStaticBtn3();
	afx_msg void OnStnClickedStaticBuildname13();
	afx_msg void OnStnClickedStaticBtn4();
	afx_msg void OnStnClickedStaticBuildname14();
	afx_msg void OnStnClickedStaticBtn5();
	afx_msg void OnStnClickedStaticBuildname15();
	afx_msg void OnStnClickedStaticBtn6();
	afx_msg void OnStnClickedStaticBuildname16();
	afx_msg void OnStnClickedStaticBtn7();
	afx_msg void OnStnClickedStaticBuildname17();
	afx_msg void OnStnClickedStaticBtn8();
	afx_msg void OnStnClickedStaticBuildname18();
	afx_msg void OnStnClickedStaticBtn9();
	afx_msg void OnStnClickedStaticBuildname19();
	afx_msg void OnStnClickedStaticBtn10();
	afx_msg void OnStnClickedStaticBuildname20();
private:
	CImageBox m_PictureBox;
	CFont m_fontIntroduction;

	vector<int> allDisplayId;
	vector<int> chooseDisplayId;
	vector<int> introductionDisplayId;
	vector<int> *currentDisplayId;
	HBITMAP m_hBitmap;
	void display();
	void SetButtonBackGrounds(CDC *pDC);
public:
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CMyButton m_btnBack;
};
