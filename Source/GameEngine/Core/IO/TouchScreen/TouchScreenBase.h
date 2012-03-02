//
//  TouchScreenBase.h
//  GameEngine
//
//  Created by Quang Phan on 01/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_TouchScreenBase_h
#define GameEngine_TouchScreenBase_h
#include <list>
#include <vector>
#include "../../Graphics/Point2D.h"

class TouchScreenBase 
{
public:
	typedef long								TouchID;
	typedef short								TouchType;
	typedef Point2D<TouchType>					TouchPoint;
	//typedef rect<float>	IrrRect;
protected:
	enum { MAX_INPUTS = 8 };
	enum { MAX_QUEUE_SIZE = 16 };
    
	static const bool			SHOW_TRACE				= false;
	static const TouchType		DISTANCE_TOLERANCE		= (TouchType)2;
	//static const TimeStamp		CLEAN_UP_DELAY;
    
	static const unsigned short	HORIZ_SWIPE_DRAG_MIN	= 12;
	//static const unsigned short	VERT_SWIPE_DRAG_MAX		= 4;
    
public:
	static const TouchType		INVALID_TOUCH_ID	= (TouchType)-1;
    
    
    // ** Structures
    // ////////////////////////////////////////////////////////
protected:
	enum TouchEvent
	{
		Pressed = 0,
		Moved,
		Ended,
		Processed
	};
    
	struct _TouchPointInfo
	{
		TouchPoint			firstPoint;
		TouchPoint			point;
		TouchPoint			lastPoint;
		//TimeStamp			timeStamp;	// in seconds
		bool				isActive;
        bool				isPressed;
		TouchID				touchID;
		TouchEvent			lastEventType;
        
		_TouchPointInfo() : isActive(false), isPressed(false) {};
	};
    
	struct _QueuedEvent
	{
		TouchEvent	type;
		TouchPoint	point;
		TouchID		touchId;
	};
    // ** Typedefs
    // ////////////////////////////////////////////////////////
protected:
	//typedef _TouchPointInfo TouchList[Cst(TouchScreen, MaxInputs)];
	typedef int TouchListIter;
	typedef int TouchListConstIter;
    
	typedef std::vector<_QueuedEvent>	QueuedEvents;
    
    // ** Members
    // ////////////////////////////////////////////////////////
protected:
	//TouchList					m_touchList;
	_TouchPointInfo				m_touchList[MAX_INPUTS];
	//TimeStamp					m_lastUpdateTimestamp;
	int							m_lastTouch;
    
	QueuedEvents				m_queuedEvents;
	size_t						m_queueBegin, m_queueEnd;
    
	bool						m_isInverted;
    
    // ** Ctors / Dtor
    // ////////////////////////////////////////////////////////
protected:
    TouchScreenBase();
public:
	virtual						~TouchScreenBase();

    
public:
    // Events calls
	virtual void				touchBegan(const TouchPoint& point, TouchID touchID);
	virtual void				touchMoved(const TouchPoint& point, TouchID touchID);
	virtual void				touchEnded(const TouchPoint& point, TouchID touchID);
	virtual void				touchCancelled(const TouchPoint& point, TouchID touchID);
    
    
    TouchID						getID(TouchID touchID);
    
    //update
    void						update(double timestamp);
};


#endif
