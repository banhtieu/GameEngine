//
//  TouchManager.h
//  GameEngine
//
//  Created by Tran Khiem on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_TouchManager_h
#define GameEngine_TouchManager_h

#include "Touch.h"
#include <list>

using namespace std;

typedef list<Touch*> TouchList;

class TouchManager:public Singleton<TouchManager>
{
public:
  // Touch Manager.
  TouchManager();
  // Touch Manager
  ~TouchManager();
  
  // Begin Transfer Touches
  virtual void AddTouch(int touchId, int x, int y, int type);
  // Update Touches
  virtual void Update();
  
  virtual TouchList* GetTouches();
  virtual int GetNumberOfTouches();
  virtual bool IsTouchInRect(int x, int y, int w, int h);
  
private:
  TouchList *touches;
};


#endif
