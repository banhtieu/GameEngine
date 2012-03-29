//
//  Touch.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

// Init the Touch
Touch::Touch(int touchId, int x, int y, int type)
{
  this->touchId = touchId;
  data.x = x;
  data.y = y;
  data.type = type;
  lastData.type = TOUCH_NONE;
}

// destroy Touch
Touch::~Touch()
{
}

// Get Type
int Touch::GetType()
{
  return data.type;
}

// return Touch X
int Touch::GetX()
{
  return data.x;
}

// Return Touch Y
int Touch::GetY()
{
  return data.y;
}

// get Touch Id
int Touch::GetTouchId()
{
  return touchId;
}

// Get Delta X
int Touch::GetDeltaX()
{
  int value = data.x - lastData.x;
  lastData.x = data.x;
  return value;
}

// Get Delta Y
int Touch::GetDeltaY()
{
  int value = data.y - lastData.y;
  lastData.y = data.y;
  return value;
}

// Check if Touch is Int Rectangle
bool Touch::IsInRect(int x, int y, int w, int h)
{
  return data.x >= x && data.x <= x + w
      && data.y >= y && data.y <= y + h;
}

// Check if Touch is Down
bool Touch::IsJustTouch()
{
  return data.type == TOUCH_DOWN;
}

// Check if Touch is Up
bool Touch::IsJustUp()
{
  return data.type == TOUCH_UP;
}

bool Touch::IsMoving()
{
  return data.type = TOUCH_MOVE;
}

