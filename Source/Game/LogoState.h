//
//  LogoState.h
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_LogoState_h
#define GameEngine_LogoState_h

#include "State.h"
#include "Texture.h"

using namespace bt;

class LogoState: public bt::state::State, bt::Singleton<LogoState>
{
public:
  virtual void Init();
  virtual void Render();
  virtual void Update();
protected:
  Texture *logo;
  int logoFrame;
};

#endif
