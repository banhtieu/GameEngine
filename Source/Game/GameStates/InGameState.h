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
  virtual void AddGround(float x, float y, float alpha = 0.0f);
  virtual void AddBicycle();
protected:
  Sprite *sprite;
  Texture *background;
  Actor *mainActor;
  b2World *world;
  b2Body *bicycle;
  b2Body *wheel1;
  b2Body *wheel2;
  StringManager *stringManager;
  
};


#endif
