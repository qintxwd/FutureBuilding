///////////////////////////////////////////////////////////////////////////////
// 文件	：MyButton.h
// 作者	: weny by 20110701
// 描述	: 支持png图形的透明异形按钮
///////////////////////////////////////////////////////////////////////////////

#pragma once

// MyButton.h : header file
//

class CGdiPlusBitmapResource;
/////////////////////////////////////////////////////////////////////////////
// CMyButton window

class CMyButton : public CButton
{
public:
	
	CMyButton();
	virtual ~CMyButton();
	
	// image types
	enum	
	{
		STD_TYPE	= 0,
		ALT_TYPE,
		DIS_TYPE
	};

	void SetImage(int type);

	BOOL LoadAltImage(UINT normal_id, UINT mask_id, LPCTSTR pType);
	BOOL LoadAltImage(LPCWSTR normal, LPCTSTR mask, LPCTSTR pType);
		
	BOOL LoadStdImage(UINT normal_id, UINT mask_id, LPCTSTR pType);
	BOOL LoadStdImage(LPCWSTR normal, LPCTSTR mask, LPCTSTR pType);

	void EnableButton(BOOL bEnable = TRUE) 
	{ 
		m_bIsDisabled = !bEnable; 
	}

	void EnableToggle(BOOL bEnable = TRUE);

	BOOL IsDisabled(void) 
	{
		return (m_bIsDisabled == TRUE); 
	}

	void SetBkGnd(CDC* pDC);

	void SetToolTipText(CString spText, BOOL bActivate = TRUE);
	void SetToolTipText(UINT nId, BOOL bActivate = TRUE);
	void SetHorizontal(bool ImagesAreLaidOutHorizontally = FALSE);
	void DeleteToolTip();


protected:

	void PaintBk(CDC* pDC);
	void PaintBtn(CDC* pDC);

	BOOL	m_bHaveAltImage;
	BOOL	m_bHaveBitmaps;

	BOOL	m_bIsDisabled;
	BOOL	m_bIsToggle;
	BOOL	m_bIsHovering;
	BOOL	m_bIsTracking;

	int		m_nCurType;

	CGdiPlusBitmapResource* m_pAltImage;
	CGdiPlusBitmapResource* m_pStdImage;

	CString			m_tooltext;
	CToolTipCtrl*	m_pToolTip;
	
	void	InitToolTip();

	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	//{{AFX_MSG(CMyButton)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
//	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam) ;
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:

	CDC		m_dcBk;			// button background
	
	CDC		m_dcStd;		// standard button
	CDC		m_dcStdP;		// standard button pressed
	CDC		m_dcStdH;		// standard button hot

	CDC		m_dcAlt;		// alternate button
	CDC		m_dcAltP;		// alternate button pressed
	CDC		m_dcAltH;		// alternate button hot

	CDC		m_dcGS;			// grayscale button (does not have a hot or pressed state)

	CDC*	m_pCurBtn;		// current pointer to one of the above

	CBitmap	m_bMask;
	HRGN	hClipRgn;
	HRGN	CreateRgnFromBitmap(HBITMAP hBmp, COLORREF color);
};
