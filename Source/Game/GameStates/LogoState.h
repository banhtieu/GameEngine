//
//  LogoState.h
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_LogoState_h
#define GameEngine_LogoState_h

#include "Engine.h"

class LogoState: public State, Singleton<LogoState>
{
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  virtual void Free();
protected:
  Sprite *splashSprite;
  long timeStart;
};

#endif
