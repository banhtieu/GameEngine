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
  logoFrame = 0;
}

void LogoState::Render()
{
  Graphics2D *g = Graphics2D::GetInstance();
  g->DrawTexture(logo, 20, 200, 0, 0, 512, 161);
  g->DrawTexture(logo, 300, 300, 123*(logoFrame/10), 161, 123, 134);
  logoFrame = (logoFrame + 1) % 40;
};

void LogoState::Update()
{
}
