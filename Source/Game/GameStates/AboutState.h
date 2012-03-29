//
//  AboutState.h
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_AboutState_h
#define AnimoGame_AboutState_h
#include "Engine.h"

class AboutState: public State, Singleton<AboutState>
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
