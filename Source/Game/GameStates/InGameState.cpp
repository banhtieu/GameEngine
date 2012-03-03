//
//  InGameState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "InGameState.h"
#include "logo.h"
#include <Box2D/Box2D.h>

// Init The GameState
void InGameState::Init()
{
  actor = new Sprite("logo");
}


// 
void InGameState::Update()
{
  
}

void InGameState::Render(Graphics2D *g)
{
  actor->DrawFrame(F_BIKE, SCREEN_WD2, SCREEN_HD2);
}


void InGameState::Free()
{
  SAFE_DEL(actor);
}