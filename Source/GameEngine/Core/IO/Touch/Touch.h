//
//  TouchEvent.h
//  GameEngine
//
//  Created by Tran Khiem on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_TouchEvent_h
#define GameEngine_TouchEvent_h

// Type of Touch Event
enum TouchEventType
{
  TOUCH_NONE,
  TOUCH_DOWN,
  TOUCH_MOVE,
  TOUCH_CANCELLED,
  TOUCH_UP
};

// Touch Data
struct TouchData
{
  int x;
  int y;
  int type;
};

// Touch
class Touch
{
public:
  Touch(int touchId, int x, int y, int type);
  virtual ~Touch();
  
  virtual bool IsInRect(int x, int y, int w, int h);
  virtual int GetDeltaX();
  virtual int GetDeltaY();
  
  // Get the touch data.
  virtual int GetType();
  virtual int GetX();
  virtual int GetY();
  
  // is Just Touch
  virtual bool IsJustTouch();
  
  // Get the Touch id
  virtual int GetTouchId();
  
  // is Just Touch Up
  virtual bool IsJustUp();
  
  // the current Data
  TouchData data;
  
  // last Data
  TouchData lastData;
  
  // touch id
  int touchId;
};



#endif
