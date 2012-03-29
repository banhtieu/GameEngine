//
//  MainMenuState.h
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_MainMenuState_h
#define AnimoGame_MainMenuState_h

#include "Engine.h"
#include "SoundPack.h"

#define NUM_MENU 5
class MainMenuState: public State, Singleton<MainMenuState>
{
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  virtual void Free();
protected:
  Sprite *bgSprite;
  Sprite *menuSprite;
  StringManager *stringManager;
  int numMenuItems;
  MenuInstance *menuList[NUM_MENU];
  
  int playX, playY;
  int oldX, oldY;
  int aX;
  bool selecting;
};



#endif
