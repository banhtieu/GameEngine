//
//  MainMenuState.h
//  GameEngine
//
//  Created by Quang Phan on 23/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_LoadingState_h
#define GameEngine_LoadingState_h

#include "Engine.h"

class LoadingState: public State, Singleton<LoadingState>
{
public:
    virtual void Init();
    virtual void Render(Graphics2D *g);
    virtual void Update();
protected:
};

#endif
