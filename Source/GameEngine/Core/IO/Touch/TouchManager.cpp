//
//  TouchManager.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

TouchManager::TouchManager()
{
  touches = new TouchList;
}


// Destroy touches
TouchManager::~TouchManager()
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    delete *item;
  }
  delete touches;
}

// Get Touches
TouchList* TouchManager::GetTouches()
{
  return touches;
}

// Get Touches
Touch* TouchManager::GetFirstTouch()
{
  if (touches->size())
  {
    return *touches->begin();
  }
  else 
  {
    return NULL;
  }
}

// Get Number of Touches
int TouchManager::GetNumberOfTouches()
{
  return touches->size();
}


// Check any touch in Rectangle
bool TouchManager::HasNewTouch()
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    if ((*item)->IsJustTouch())
    {
      return true;
    };
  }
  return false;
}

// Check any touch in Rectangle
bool TouchManager::IsTouchInRect(int x, int y, int w, int h)
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    if ((*item)->IsInRect(x, y, w, h))
    {
      return true;
    };
  }
  return false;
}

bool TouchManager::IsTouchDownInRect(int x, int y, int w, int h)
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    if ((*item)->IsInRect(x, y, w, h) && (*item)->IsJustTouch())
    {
      return true;
    };
  }
  return false;
}
bool TouchManager::IsTouchUpInRect(int x, int y, int w, int h)
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    if ((*item)->IsInRect(x, y, w, h) && (*item)->IsJustUp())
    {
      touches->erase(item);
      delete *item;
      return true;
    };
  }
  return false;
}

bool TouchManager::IsTouchMovingInRect(int x, int y, int w, int h)
{
  for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
  {
    if ((*item)->IsInRect(x, y, w, h) && (*item)->IsMoving())
    {
      return true;
    };
  }
  return false;
}
// Add Touch
void TouchManager::AddTouch(int touchId, int x, int y, int type)
{
  if (type == TOUCH_DOWN)
  {
    touches->push_back(new Touch(touchId, x, y, type));
  }
  else
  {
    for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
    {
      if (touchId == (*item)->GetTouchId())
      {
        (*item)->lastData = (*item)->data;
        (*item)->data.x = x;
        (*item)->data.y = y;
        (*item)->data.type = type;
      }
    }
  }
}

// Update Touch events
void TouchManager::Update()
{
  bool isErase = true;
  while (isErase) 
  {
    isErase = false;
    for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
    {
      if (TOUCH_CANCELLED == (*item)->GetType() || TOUCH_UP == (*item)->GetType())
      {
        touches->erase(item);
        delete *item;
        isErase = true;
        break;
      }
    }
  }
  
}
