//
//  InGameState.h
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_InGameState_h
#define GameEngine_InGameState_h

#include "Engine.h"
#include "Box2D/Box2D.h"

class InGameState:public State, Singleton<InGameState>
{
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  virtual void Free();
  
  virtual void CreateWorld();
  virtual void AddGround();
protected:
  Sprite *sprite;
  Actor *mainActor;
  b2World *world;
  
};


#endif
