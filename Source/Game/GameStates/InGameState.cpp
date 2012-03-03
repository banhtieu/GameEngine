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
  sprite = new Sprite("logo");
  mainActor = new Actor(sprite, F_BIKE, 4);
  mainActor->SetPosition(SCREEN_WD2, SCREEN_HD2);
  
}


// 
void InGameState::Update()
{
}

// Render the InGame State
void InGameState::Render(Graphics2D *g)
{
  mainActor->Paint();
}

// Free The In Game 
void InGameState::Free()
{
  SAFE_DEL(mainActor);
  SAFE_DEL(sprite);
}