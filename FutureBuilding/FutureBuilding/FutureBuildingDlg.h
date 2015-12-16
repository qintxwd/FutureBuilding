
// FutureBuildingDlg.h : ͷ�ļ�
//

#pragma once
#include "imagebox.h"

#include <vector>
#include "MyButton.h"
using namespace std;

//�Զ�����Ϣ 
#define WM_INTRODUCE_BLOCH (WM_USER+101)
#define WM_INTRODUCE_CAJA (WM_USER+102)
#define WM_INTRODUCE_CCTV (WM_USER+103)
#define WM_INTRODUCE_CNS (WM_USER+104)
#define WM_INTRODUCE_HT5 (WM_USER+105)
#define WM_INTRODUCE_ICA (WM_USER+106)
#define WM_INTRODUCE_LH (WM_USER+107)
#define WM_INTRODUCE_MOCA (WM_USER+108)
#define WM_INTRODUCE_NFB (WM_USER+109)
#define WM_INTRODUCE_OSP (WM_USER+110)
// CFutureBuildingDlg �Ի���
class CFutureBuildingDlg : public CDialogEx
{
// ����
public:
	CFutureBuildingDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FUTUREBUILDING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	afx_msg void OnBnClickedButtonBack();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CMyButton m_btnBack;
protected:
	afx_msg LRESULT OnIntroduceBloch(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceCctv(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceCaja(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceCns(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceHt5(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceIca(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceLh(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceMoca(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceNfb(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIntroduceOsp(WPARAM wParam, LPARAM lParam);

};
