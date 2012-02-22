//
//  LogoState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "LogoState.h"
#include "Graphics2D.h"
using namespace bt;

void LogoState::Init()
{
  logo = Texture::LoadTexturePNG("logo.png");
}

void LogoState::Render()
{
  LOGI("Render Logo State");
};

void LogoState::Update()
{
  LOGI("Update LogoState");
}
