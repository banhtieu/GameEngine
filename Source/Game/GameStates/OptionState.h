//
//  OptionState.h
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_OptionState_h
#define AnimoGame_OptionState_h
#include "Engine.h"

class OptionState: public State, Singleton<OptionState>
{
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  virtual void Free();
protected:
  Sprite *bgSprite;
};


#endif
