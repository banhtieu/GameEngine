//
//  MyGame.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "MyGame.h"
#include "LogoState.h"

void MyGame::Init()
{
  SwitchState(new LogoState());
}