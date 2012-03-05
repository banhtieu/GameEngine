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
#include <vector>

using namespace std;

typedef vector<Touch*> TouchList;

class TouchManager:public Singleton<TouchManager>
{
public:
  // Touch Manager.
  TouchManager();
  // Touch Manager
  ~TouchManager();
  
  // Begin Transfer Touches
  virtual void BeginTransferTouches();
  virtual void AddTouch(int touchId, int x, int y, int type);
  // End Transfer Touches
  virtual void EndTransferTouches();
  
  // void Update Touch
  virtual void UpdateTouches(TouchList* newTouches);
  virtual TouchList* GetTouches();
  virtual int GetNumberOfTouches();
  virtual bool IsTouchInRect(int x, int y, int w, int h);
  
private:
  TouchList *touches;
  TouchList *newTouches;
};


#endif
