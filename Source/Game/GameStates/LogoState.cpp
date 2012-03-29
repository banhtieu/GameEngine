//
//  LogoState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "LogoState.h"
//#include "BackgroundData.h"
#include "Splash.h"
#include "MainMenuState.h"
#define LOGO_TIME 3

void LogoState::Init()
{
  splashSprite = new Sprite();
  splashSprite->LoadSprite("Splash");
  timeStart = Application::GetInstance()->GetCurrentTime();
}

void LogoState::Render(Graphics2D *g)
{
  splashSprite->DrawModule(M_SPLASH, 0, 0);
};

void LogoState::Update()
{
  if (Application::GetInstance()->GetCurrentTime()- timeStart > LOGO_TIME)
  {
    Application::GetInstance()->SwitchState(new MainMenuState());
  }
}

void LogoState::Free()
{
    delete splashSprite;
}
