//
//  AboutState.cpp
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AboutState.h"

void AboutState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");

}

void AboutState::Update()
{
  
}

void AboutState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
}

void AboutState::Free()
{
  delete bgSprite;
}