#include "stdafx.h"
#include "ImageBox.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

IMPLEMENT_DYNAMIC(CImageBox, CWnd)

BEGIN_MESSAGE_MAP(CImageBox, CWnd)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CImageBox::CImageBox()
: m_iCurAnimType(kNone)
, m_iDuration(2000)
, m_iRetention(2000)
, m_iIndex(0)
, m_pOffScreenImage(NULL)
, m_dwAnimStartTick(0)
, m_dwDelayStartTick(0)
, m_bIsDelayed(FALSE)
, m_bIsAnimating(FALSE)
, m_bPlay(FALSE)
{

}

CImageBox::~CImageBox()
{
	RemoveAllImage();
	if(m_pOffScreenImage != NULL)
	{
		m_pOffScreenImage->Destroy();
		delete m_pOffScreenImage;
	}
}

BOOL CImageBox::Create()
{
	BOOL bCreate = FALSE;
	if(m_pOffScreenImage == NULL)
	{
		m_pOffScreenImage = new CImage;
		CRect rcClient;
		GetClientRect(rcClient);
		bCreate = m_pOffScreenImage->Create(rcClient.Width(), rcClient.Height(), 24, 0);
	}
	return bCreate;
}

void CImageBox::Destroy()
{
	m_bPlay = FALSE;
}

void CImageBox::AddImage(LPCTSTR lpszImageName)
{
	CImage* pImage = new CImage;
	HRESULT hRet = pImage->Load(lpszImageName);
	ASSERT(hRet == S_OK);
	if(hRet == S_OK)
		m_arrImages.Add(pImage);
}

void CImageBox::AddImage(UINT uResId)
{
	HRSRC hResSrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(uResId), RESTYPE);
	ASSERT(hResSrc);
	if(!hResSrc) return;
	HGLOBAL hRes = ::LoadResource(AfxGetResourceHandle(), hResSrc);
	ASSERT(hRes);
	if (!hRes) return;

	LPVOID pRes = ::LockResource(hRes);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hResSrc);
	HGLOBAL hTempBuf = ::GlobalAlloc(GHND, dwSize);
	LPBYTE pTempBuf = (LPBYTE)::GlobalLock(hTempBuf);
	memcpy(pTempBuf, pRes, dwSize);
	::GlobalUnlock(pTempBuf);
	::FreeResource(hRes);

	HRESULT hRet = ::CreateStreamOnHGlobal(hTempBuf, TRUE, &pStream);
	ASSERT(hRet == S_OK);
	if(hRet != S_OK)
	{
		GlobalFree(hTempBuf);
		return;
	}
	CImage* pImage = new CImage;
	pImage->Load(pStream);
	::GlobalFree(hTempBuf);
}

void CImageBox::SetDuration(int iTime)
{
	if(iTime < 5)
	{
		m_iDuration = 5;
		return;
	}
	m_iDuration = iTime;
}

void CImageBox::SetRetention(int iTime)
{
	if(iTime < 0)
	{
		iTime = 0;
		return;
	}
	m_iRetention = iTime;
}

void CImageBox::SetAnimationType(AnimationType iType)
{
	m_iCurAnimType = iType;
}

void CImageBox::Play()
{
	m_bPlay = TRUE;
	MSG msg;
	while(m_bPlay)
	{
		if(!::PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			Render();
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void CImageBox::Stop()
{
	m_bPlay = FALSE;
}

CImage* CImageBox::GetImageAt(int iIndex) const
{
	ASSERT(iIndex < m_arrImages.GetSize());
	return m_arrImages.GetAt(iIndex);
}

void CImageBox::RemoveImageAt(int iIndex)
{
	ASSERT(iIndex < m_arrImages.GetSize());
	CImage* pImage = m_arrImages.GetAt(iIndex);
	pImage->Destroy();
	delete pImage;
	m_arrImages.RemoveAt(iIndex);
}

void CImageBox::RemoveAllImage()
{
	for(int i = 0; i < GetSize(); i++)
	{
		CImage* pImage = GetImageAt(i);
		pImage->Destroy();
		delete pImage;
	}
	m_arrImages.RemoveAll();
}

int	CImageBox::GetSize() const
{
	return m_arrImages.GetSize();
}

int CImageBox::GetNextFrameIndex() const
{
	return (m_iIndex < GetSize() - 1) ? m_iIndex + 1 : 0;

}

void CImageBox::OnTimer(UINT_PTR nIDEvent)
{
	Render();
	CWnd::OnTimer(nIDEvent);
}

BOOL CImageBox::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CImageBox::AnimationRender_Alpha(DWORD dwTick)
{
	if(GetSize() == 0)
		return;

	if (!m_bIsAnimating)
	{
		m_bIsAnimating = TRUE;
		m_dwAnimStartTick = dwTick;
	}
	CImage* pCurImage = GetImageAt(m_iIndex);
	CImage* pNextImage = GetImageAt(GetNextFrameIndex());
	CRect rcClient;
	GetClientRect(rcClient);
	// DEST
	HDC hOffScreenDC = m_pOffScreenImage->GetDC();
	::SetStretchBltMode(hOffScreenDC, COLORONCOLOR);
	pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
	// SRC
	double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
	int iAlpha = GetLinearInterpolation(0, 255, delta);
	pCurImage->AlphaBlend(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height(), 
		0, 0, pCurImage->GetWidth(), pCurImage->GetHeight(), iAlpha);

	// Current frame animation ends.
	if(iAlpha == 0)
	{
		if(++m_iIndex >= GetSize())
			m_iIndex = 0;
		m_dwDelayStartTick = dwTick;
		m_bIsAnimating = FALSE;
		m_bIsDelayed = TRUE;
	}
	m_pOffScreenImage->ReleaseDC();
	Invalidate(FALSE);
}	

void CImageBox::AnimationRender_Slide(DWORD dwTick)
{
	if(GetSize() == 0)
		return;

	if (!m_bIsAnimating)
	{
		m_bIsAnimating = TRUE;
		m_dwAnimStartTick = timeGetTime();
	}
	CImage* pCurImage = GetImageAt(m_iIndex);
	CImage* pNextImage = GetImageAt(GetNextFrameIndex());
	CRect rcClient;
	GetClientRect(rcClient);

 	HDC hOffScreenDC = m_pOffScreenImage->GetDC();
 	::SetStretchBltMode(hOffScreenDC, COLORONCOLOR);
	int iMode = ::SaveDC(hOffScreenDC);
	double delta = (double)(min(dwTick, m_dwAnimStartTick + m_iDuration) - m_dwAnimStartTick) / (double)m_iDuration;
	POINT ptOldViewportOrg;
	// Slide left.
	if(m_iCurAnimType == kAnimationSlideLeft)
	{
		int iOffsetX = GetLinearInterpolation(0, -rcClient.Width(), delta);
		::SetViewportOrgEx(hOffScreenDC, iOffsetX, 0, &ptOldViewportOrg);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, rcClient.Width(), 0, rcClient.Width(), rcClient.Height());
		if(iOffsetX == -rcClient.Width())
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationSlideRight)
	{
		int iOffsetX = GetLinearInterpolation(0, rcClient.Width(), delta);
		::SetViewportOrgEx(hOffScreenDC, iOffsetX, 0, &ptOldViewportOrg);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, -rcClient.Width(), 0, rcClient.Width(), rcClient.Height());
		if(iOffsetX == rcClient.Width())
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationSlideTop)
	{
		int iOffsetY = GetLinearInterpolation(0, -rcClient.Height(), delta);
		::SetViewportOrgEx(hOffScreenDC, 0, iOffsetY, &ptOldViewportOrg);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, 0, rcClient.Height(), rcClient.Width(), rcClient.Height());
		if(iOffsetY == -rcClient.Height())
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationSlideBottom)
	{
		int iOffsetY = GetLinearInterpolation(0, rcClient.Height(), delta);
		::SetViewportOrgEx(hOffScreenDC, 0, iOffsetY, &ptOldViewportOrg);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, 0, -rcClient.Height(), rcClient.Width(), rcClient.Height());
		if(iOffsetY == rcClient.Height())
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	::RestoreDC(hOffScreenDC, iMode);
	m_pOffScreenImage->ReleaseDC();
	Invalidate(FALSE);
}

void CImageBox::AnimationRender_Blind(DWORD dwTick)
{
	if(GetSize() == 0)
		return;

	if (!m_bIsAnimating)
	{
		m_bIsAnimating = TRUE;
		m_dwAnimStartTick = timeGetTime();
	}
	CImage* pCurImage = GetImageAt(m_iIndex);
	CImage* pNextImage = GetImageAt(GetNextFrameIndex());
	CRect rcClient;
	GetClientRect(rcClient);

	HDC hOffScreenDC = m_pOffScreenImage->GetDC();
	::SetStretchBltMode(hOffScreenDC, COLORONCOLOR);
	pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());

	// Resize image to fit the size of client.
	CImage imageFit;
	imageFit.Create(rcClient.Width(), rcClient.Height(), 24, 0);
	HDC hImageTempDC = imageFit.GetDC();
	::SetStretchBltMode(hImageTempDC, COLORONCOLOR);
	pCurImage->Draw(hImageTempDC, 0, 0, rcClient.Width(), rcClient.Height());
	imageFit.ReleaseDC();

	int iPiece = rcClient.Width() / BLIND_PIECE;
	if(m_iCurAnimType == kAnimationBlindLeft)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iPieceWidth = GetLinearInterpolation(0, iPiece, delta);
		for (int i = 0; i < iPiece; i++)
		{
			imageFit.BitBlt(hOffScreenDC, i * iPiece, 0, iPieceWidth+1, rcClient.Height(),  i * iPiece, 0, SRCCOPY);
		}
		if(iPieceWidth == 0)
		{
			// Erase the gaps.
			pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
 	else if(m_iCurAnimType == kAnimationBlindRight)
 	{
		double delta = (double)(min(dwTick, m_dwAnimStartTick + m_iDuration) - m_dwAnimStartTick) / (double)m_iDuration;
		int iPieceWidth = GetLinearInterpolation(0, iPiece, delta);
		for (int i = 0; i < iPiece; i++)
		{
			imageFit.BitBlt(hOffScreenDC, i * iPiece + iPieceWidth, 0, iPiece - iPieceWidth + 1, rcClient.Height(),  i * iPiece + iPieceWidth, 0, SRCCOPY);
		}
		if(iPieceWidth == iPiece)
		{
			// Erase the gaps.
			pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
 	}
	if(m_iCurAnimType == kAnimationBlindTop)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iPieceWidth = GetLinearInterpolation(0, iPiece, delta);
		for (int i = 0; i < iPiece; i++)
		{
			imageFit.BitBlt(hOffScreenDC, 0, i * iPiece, rcClient.Width(), iPieceWidth + 1,  0, i * iPiece, SRCCOPY);
		}
		if(iPieceWidth == 0)
		{
			// Erase the gaps.
			pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationBlindBottom)
	{
		double delta = (double)(min(dwTick, m_dwAnimStartTick + m_iDuration) - m_dwAnimStartTick) / (double)m_iDuration;
		int iPieceWidth = GetLinearInterpolation(0, iPiece, delta);
		for (int i = 0; i < iPiece; i++)
		{
			imageFit.BitBlt(hOffScreenDC, 0, i * iPiece + iPieceWidth, rcClient.Width(), iPiece - iPieceWidth + 1,  0, i * iPiece + iPieceWidth, SRCCOPY);
		}
		if(iPieceWidth == iPiece)
		{
			// Erase the gaps.
			pNextImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	imageFit.Destroy();
	m_pOffScreenImage->ReleaseDC();
	Invalidate(FALSE);
}

void CImageBox::AnimationRender_Cover(DWORD dwTick)
{
	if(GetSize() == 0)
		return;

	if (!m_bIsAnimating)
	{
		m_bIsAnimating = TRUE;
		m_dwAnimStartTick = timeGetTime();
	}
	CImage* pCurImage = GetImageAt(m_iIndex);
	CImage* pNextImage = GetImageAt(GetNextFrameIndex());
	CRect rcClient;
	GetClientRect(rcClient);

 	HDC hOffScreenDC = m_pOffScreenImage->GetDC();
 	::SetStretchBltMode(hOffScreenDC, COLORONCOLOR);
	// Cover left.
	if(m_iCurAnimType == kAnimationCoverLeft)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iX = GetLinearInterpolation(0, rcClient.Width(), delta);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, iX, 0, rcClient.Width(), rcClient.Height());
		if(iX == 0)
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationCoverRight)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iX = GetLinearInterpolation(0, -rcClient.Width(), delta);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, iX, 0, rcClient.Width(), rcClient.Height());
		if(iX == 0)
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationCoverTop)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iY = GetLinearInterpolation(0, rcClient.Height(), delta);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, 0, iY, rcClient.Width(), rcClient.Height());
		if(iY == 0)
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	else if(m_iCurAnimType == kAnimationCoverBottom)
	{
		double delta = (double)(m_dwAnimStartTick + m_iDuration - min(dwTick, m_dwAnimStartTick + m_iDuration)) / (double)m_iDuration;
		int iY = GetLinearInterpolation(0, -rcClient.Height(), delta);
		pCurImage->Draw(hOffScreenDC, 0, 0, rcClient.Width(), rcClient.Height());
		pNextImage->Draw(hOffScreenDC, 0, iY, rcClient.Width(), rcClient.Height());
		if(iY == 0)
		{
			if(++m_iIndex >= GetSize())
				m_iIndex = 0;
			m_dwDelayStartTick = dwTick;
			m_bIsAnimating = FALSE;
			m_bIsDelayed = TRUE;
		}
	}
	m_pOffScreenImage->ReleaseDC();
	Invalidate(FALSE);
}

void CImageBox::Render()
{
	// Frame delay toggle.
	if(m_bIsDelayed)
	{
		if(timeGetTime() - m_dwDelayStartTick > m_iRetention)
			m_bIsDelayed = FALSE;
		return;
	}
	bool isRandom = false;
	if(kAnimationRandom == m_iCurAnimType){
		isRandom = true;
		//0 - 12 随机一个数字
		srand((int)time(0));
		int randxxx = rand()%13;
		
		switch(randxxx){
		case 0:
			m_iCurAnimType = kAnimationFade;
			break;
		case 1:
			m_iCurAnimType = kAnimationSlideLeft;
			break;
		case 2:
			m_iCurAnimType = kAnimationSlideRight;
			break;
		case 3:
			m_iCurAnimType = kAnimationSlideTop;
			break;
		case 4:
			m_iCurAnimType = kAnimationSlideBottom;
			break;
		case 5:
			m_iCurAnimType = kAnimationBlindLeft;
			break;
		case 6:
			m_iCurAnimType = kAnimationBlindRight;
			break;
		case 7:
			m_iCurAnimType = kAnimationBlindTop;
			break;
		case 8:
			m_iCurAnimType = kAnimationBlindBottom;
			break;
		case 9:
			m_iCurAnimType = kAnimationCoverLeft;
			break;
		case 10:
			m_iCurAnimType = kAnimationCoverRight;
			break;
		case 11:
			m_iCurAnimType = kAnimationCoverTop;
			break;
		case 12:
			m_iCurAnimType = kAnimationCoverBottom;
			break;
		}
	}

	switch(m_iCurAnimType)
	{
	case kAnimationFade:
		AnimationRender_Alpha(timeGetTime());
		break;
	case kAnimationSlideLeft:
	case kAnimationSlideRight:
	case kAnimationSlideTop:
	case kAnimationSlideBottom:
		AnimationRender_Slide(timeGetTime());
		break;
	case kAnimationBlindLeft:
	case kAnimationBlindRight:
	case kAnimationBlindTop:
	case kAnimationBlindBottom:
		AnimationRender_Blind(timeGetTime());
		break;
	case kAnimationCoverLeft:
	case kAnimationCoverRight:
	case kAnimationCoverTop:
	case kAnimationCoverBottom:
		AnimationRender_Cover(timeGetTime());
		break;
	}
	if(isRandom)
		m_iCurAnimType = kAnimationRandom;
}

void CImageBox::OnPaint()
{
	CPaintDC dc(this);
	CRect rcClient;
	GetClientRect(rcClient);
	dc.SetStretchBltMode(COLORONCOLOR);
	m_pOffScreenImage->Draw((HDC)dc, 0, 0, rcClient.Width(), rcClient.Height());
}

int CImageBox::GetLinearInterpolation(int x1, int x2, double delta)
{
return (int)((double)x1 + (double)(x2 - x1) * delta);
}