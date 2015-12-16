/************************************************************************
*                                                                       *
*   ImageBox.h -- This module implements a slide file box, support many *
*   popular toggle effects.                                             *
*                                                                       *                                                                 *
*   CSDN PCRADIO. All rights reserved.									*
*	2015.7.24															*
*                                                                       *
************************************************************************/
#ifndef __IMAGE_BOX_H_INCLUDED__
#define __IMAGE_BOX_H_INCLUDED__

#include <afxtempl.h>

/** CImageBox resource type */
#define RESTYPE TEXT("IMAGE_BOX_DATA")

/** Count of blind piece */
#define BLIND_PIECE	8

/** 
 * Class CImageBox 
 */
class CImageBox : public CWnd
{
public:
	DECLARE_DYNAMIC(CImageBox)

	/** Animation type */
	enum AnimationType
	{
		kNone,
		kAnimationFade,
		kAnimationSlideLeft,
		kAnimationSlideRight,
		kAnimationSlideTop,
		kAnimationSlideBottom,
		kAnimationBlindLeft,
		kAnimationBlindRight,
		kAnimationBlindTop,
		kAnimationBlindBottom,
		kAnimationCoverLeft,
		kAnimationCoverRight,
		kAnimationCoverTop,
		kAnimationCoverBottom,
		kAnimationRandom
	};

	CImageBox();
	virtual ~CImageBox();

public:
	/**
	 * Create object, here we can perform creation of off screen bitmap 
	 */
	BOOL	Create();

	void	Destroy();

	/** 
	 * Add image from file.
	 * @param lpszImageName - Image file name.
	 */
	void	AddImage(LPCTSTR lpszImageName);

	/** 
	 * Add image from resource.
	 * @param uResId - Resource identifier.
	 */
	void	AddImage(UINT uResId);

	/** 
	 * Get image.
	 */
	CImage* GetImageAt(int iIndex) const;

	/** 
	 * Remove image.
	 */
	void	RemoveImageAt(int iIndex);

	/** 
	 * Remove all images.
	 */
	void	RemoveAllImage();

	/** 
	 * Get the number of images.
	 */
	int		GetSize() const;

	/**
	 * Set animation duration.
	 * @param iTime - Duration in milliseconds.
	 */
	void	SetDuration(int iTime);

	/**
	 * Set frame retention duration.
	 * @param iTime - Duration in milliseconds.
	 */
	void	SetRetention(int iTime);

	/** 
	 * Set animation type
	 * @param iType - Animation type.
	 */
	void	SetAnimationType(AnimationType iType);

	/**
	 * Start animation
	 */
	void	Play();

	/**
	 * End animation 
	 */
	void	Stop();

	/** 
	 * Get linear interpolation 
	 */
	static int GetLinearInterpolation(int x1, int x2, double delta);

protected:	
	/** 
	 * Get the next frame image index.
	 */
	int		GetNextFrameIndex() const;

	/**
	 * Perform alpha animation. 
	 * @param dwTick - Current system time tick.
	 */
	void	AnimationRender_Alpha(DWORD dwTick);

	/** 
	 * Perform slide animation.
	 * @param dwTick - Current system time tick.
	 */
	void    AnimationRender_Slide(DWORD dwTick);

	/** 
	 * Perform blind animation.
	 * @param dwTick - Current system time tick.
	 */
	void    AnimationRender_Blind(DWORD dwTick);

	/** 
	 * Perform cover animation.
	 * @param dwTick - Current system time tick.
	 */
	void    AnimationRender_Cover(DWORD dwTick);

	/** Animation render. */
	void    Render();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void	OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL	OnEraseBkgnd(CDC* pDC);
	afx_msg void	OnPaint();

private:
	/** Image container */
	CArray<CImage*, CImage*> m_arrImages;

	/** Current frame image index */
	int				m_iIndex;

	/** Animation duration in milliseconds */
	int				m_iDuration;

	/** Frame retention in milliseconds */
	int				m_iRetention;

	/** Current animation type */
	AnimationType	m_iCurAnimType;

	/** Off screen bitmap */
	CImage*			m_pOffScreenImage;

	/** Starting tick of current animation */
	DWORD			m_dwAnimStartTick;

	/** Delay tick for next animation */
	DWORD			m_dwDelayStartTick;

	/** Is delayed */
	BOOL			m_bIsDelayed;

	/** Is animating */
	BOOL			m_bIsAnimating;

	/** Play toggle */
	BOOL			m_bPlay;
};
#endif /* __IMAGE_BOX_H_INCLUDED__ */