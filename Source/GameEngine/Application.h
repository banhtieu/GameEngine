//
//  BTApplication.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_BTApplication_h
#define GameEngine_BTApplication_h

#include "Config.h"
#include "Singleton.h"
#include "State.h"

namespace bt
{
  
  using namespace state;
  
  class Application:public Singleton<Application>
  {
  public:
    virtual void Init();
    virtual void Render();
    virtual void Update();
    virtual void Free();
    virtual void SwitchState(State *newState);
    virtual void Exit();
    virtual bool Run();
  protected:
    State *currentState;
    bool isExit;
    
  };
  
};

#endif
