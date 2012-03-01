//
//  BTApplication.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_BTApplication_h
#define GameEngine_BTApplication_h

class Application:public Singleton<Application>
{
public:
  Application();
  virtual ~Application();
  virtual void Init();
  virtual void Render();
  virtual void Update();
  virtual void Free();
  virtual void SwitchState(State *newState);
protected:
  State *currentState;
};

#endif