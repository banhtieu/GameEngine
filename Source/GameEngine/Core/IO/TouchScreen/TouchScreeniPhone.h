//
//  TouchScreeniPhone.h
//  GameEngine
//
//  Created by Quang Phan on 01/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_TouchScreeniPhone_h
#define GameEngine_TouchScreeniPhone_h
#include "TouchScreenBase.h"


class TouchScreeniPhone: public TouchScreenBase
{
    // ** Members
    // ////////////////////////////////////////////////////////
private:
	TouchType			m_left;
	TouchType			m_right;
	TouchType			m_top;
	TouchType			m_bottom;
    
    
    // ** Ctors / Dtor
    // ////////////////////////////////////////////////////////
public:
    TouchScreeniPhone();
    TouchScreeniPhone(float screenLeft, float screenTop, float screenRight, float screenBottom);
	virtual				~TouchScreeniPhone();
    
    
    // ** Methods
    // ////////////////////////////////////////////////////////
public:
	// TouchScreenBase impl.
	TouchType			getLeftBound()		const	{return m_left;};
	TouchType			getRightBound()		const	{return m_right;};
	TouchType			getTopBound()		const	{return m_top;};
	TouchType			getBottomBound()	const	{return m_bottom;};
    
	//virtual bool		isRegionPressed(const Rect& rect)		const;
	//virtual TouchID		getTouchIDInRegion(const Rect& rect)		const;	// Returns the first point in a region
    
	// Warning: those are specific to the iPhone info; they are not overrides of TouchScreenBase, but rather act as proxies.
	void touchBegan(float x, float y, double timestamp, int tapCount, float oldX, float oldY, long id);
	void touchMoved(float x, float y, double timestamp, int tapCount, float oldX, float oldY, long id);
	void touchEnded(float x, float y, double timestamp, int tapCount, float oldX, float oldY, long id);
	void touchCancelled(float x, float y, double timestamp, int tapCount, float oldX, float oldY, long id);

};
#endif
