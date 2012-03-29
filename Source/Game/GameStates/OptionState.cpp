//
//  OptionState.cpp
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "OptionState.h"


void OptionState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");
}

void OptionState::Update()
{
  
}

void OptionState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
}

void OptionState::Free()
{
  
}
