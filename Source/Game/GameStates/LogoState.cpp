//
//  LogoState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "LogoState.h"
//#include "BackgroundData.h"
#include "logo.h"
#include "MainMenuState.h"
void LogoState::Init()
{
  logo = Texture::LoadTexturePNG("logo.png");
  background = Texture::LoadTexturePNG("background.png");
  sprite = new Sprite("logo");
  logoFrame = 0;
}

void LogoState::Render(Graphics2D *g)
{
//  sprite->DrawModule(M_LOGO, 0, 0);
//  sprite->DrawFrame(F_LOGO, SCREEN_WD2, SCREEN_HD2);
  sprite->DrawFrame(F_BIKE + logoFrame, SCREEN_WD2, SCREEN_HD2);
  /* static int bgSpeed = 0;
  static int frontSpeed = 0;
  bgSpeed -= 2;
  frontSpeed -= 15;
  
  if (bgSpeed < - bgFrameData[BG1].w - bgFrameData[BG2].w)
  {
    bgSpeed = 0;
  }
  
  if (frontSpeed < - bgFrameData[FRONT1].w - bgFrameData[FRONT2].w)
  {
    frontSpeed = 0;
  }

  for (int i = 0; i < SCREEN_W; i+= bgFrameData[CLOUD1].w * 2)
  {
    g->DrawTexture(background, i, 0, bgFrameData[CLOUD1]);
    g->DrawTexture(background, i + bgFrameData[CLOUD1].w, 0, bgFrameData[CLOUD2]);
  }
  
  for (int i = bgSpeed; i < SCREEN_W; i+= bgFrameData[BG1].w + bgFrameData[BG2].w)
  {
    g->DrawTexture(background, i, 20, bgFrameData[BG1]);
    g->DrawTexture(background, i + bgFrameData[BG1].w, 0, bgFrameData[BG2]);
  }
  
  for (int i = frontSpeed; i < SCREEN_W; i+= bgFrameData[FRONT1].w + bgFrameData[FRONT2].w)
  {
    g->DrawTexture(background, i, 40, bgFrameData[FRONT1]);
    g->DrawTexture(background, i + bgFrameData[FRONT1].w, 0, bgFrameData[FRONT2]);
  }
  
  g->DrawTexture(logo, 300, 500, 123*(logoFrame), 161, 123, 134);
  logoFrame = (logoFrame + 1) % 4;
  
  g->SetColor(0xff00ff00);
  g->DrawLine(0, 0, SCREEN_W, SCREEN_H);
  g->FillCircle(100, 100, 50); */

};

void LogoState::Update()
{
  logoFrame = (logoFrame + 1) % 4;
   // Application::GetInstance()->SwitchState(new MainMenuState());
}

void LogoState::Free()
{
    delete background;
    delete sprite;
    
}
