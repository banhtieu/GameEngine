//
//  TouchManager.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

TouchManager::TouchManager():touches(NULL)
{
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

// Get Number of Touches
int TouchManager::GetNumberOfTouches()
{
  return touches->size();
}

// Update touches
void TouchManager::UpdateTouches(TouchList *newTouches)
{
  if (touches)
  {
    for (TouchList::iterator item = newTouches->begin(); item != newTouches->end(); item++)
    {
      for (TouchList::iterator oldItem = touches->begin(); oldItem != touches->end(); oldItem++)
      {
        if ((*item)->GetTouchId() == (*oldItem)->GetTouchId())
        {
          (*item)->lastData = (*oldItem)->data;
          break;
        }
      }
    }
  
  
    for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
    {
      delete *item;
    }
  
    delete touches;
  }
  
  touches = newTouches;
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

// Transfer Touches
void TouchManager::BeginTransferTouches()
{
  newTouches = new TouchList();
}

// Add Touch
void TouchManager::AddTouch(int touchId, int x, int y, int type)
{
  Touch *touch = new Touch(touchId, x, y, type);
  newTouches->push_back(touch);
}

// Update Touch events
void TouchManager::EndTransferTouches()
{
  this->UpdateTouches(newTouches);
}
