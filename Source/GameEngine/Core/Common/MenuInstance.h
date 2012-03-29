//
//  MenuInstance.h
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_MenuInstance_h
#define AnimoGame_MenuInstance_h
//#include "Engine.h"

class MenuInstance: public Singleton<MenuInstance>
{
public:
  MenuInstance(int x1, int y1, int w1, int h1)
  {
    x = x1;
    y = y1;
    w = w1;
    h = h1;
  }
 // ~MenuInstance();
  
public:
  int x,y;
  int w,h;
  int id;
 // int moduleID, moduleID;
 
public:
  bool isPressed();
  bool isTouching();
};

#endif
