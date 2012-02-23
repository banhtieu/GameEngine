//
//  LogoState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "LogoState.h"

void LogoState::Init()
{
  logo = Texture::LoadTexturePNG("logo.png");
  logoFrame = 0;
}

void LogoState::Render(Graphics2D *g)
{
  
  g->DrawTexture(logo, 20, 200, 0, 0, 512, 161);
  static float alpha = 0.0f;
  alpha += 1.0f;
  
  g->SetTransform(Matrix33::ScaleMatrix(2.0f, 300, 300));
  g->DrawTexture(logo, 300, 300, 123*(logoFrame/5), 161, 123, 134);
  logoFrame = (logoFrame + 1) % 20;
};

void LogoState::Update()
{
}
