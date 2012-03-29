//
//  MainMenuState.cpp
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "MainMenuState.h"
#include "MenuBar.h"
#include "ExportedStrings.h"
#include "InGameState.h"
#include "AboutState.h"
#include "OptionState.h"
#include "MediaPlayerManager.h"

void MainMenuState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");
  
  menuSprite = new Sprite();
  menuSprite->LoadSprite("MenuBar");
  
  stringManager = new StringManager();
  stringManager->Load("strings.en.bin");
  stringManager->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
  
  numMenuItems = 0;
  
  // Options
  menuList[numMenuItems] = new MenuInstance((SCREEN_W - menuSprite->GetModuleWidth(M_OPTION)) >> 1, 595, menuSprite->GetModuleWidth(M_OPTION), menuSprite->GetModuleHeight(M_OPTION));
  menuList[numMenuItems++]->id = M_OPTION;
  
  // About Us
  menuList[numMenuItems] = new MenuInstance((SCREEN_W - menuSprite->GetModuleWidth(M_ABOUT_US))  >> 1, 660, menuSprite->GetModuleWidth(M_ABOUT_US), menuSprite->GetModuleHeight(M_ABOUT_US));
  menuList[numMenuItems++]->id = M_ABOUT_US;

  menuList[numMenuItems] = new MenuInstance((SCREEN_W - menuSprite->GetModuleWidth(M_ACHIEVEMENTS)) >> 1, 732, menuSprite->GetModuleWidth(M_ACHIEVEMENTS), menuSprite->GetModuleHeight(M_ACHIEVEMENTS));
  menuList[numMenuItems++]->id = M_ACHIEVEMENTS;

  playX = 20;
  playY = 430;

  selecting = false;
}

void MainMenuState::Render(Graphics2D *g)
{
  static int blink = 0;
  blink = (blink + 1) % 10;
  
  bgSprite->DrawModule(0, 0, 0);
  menuSprite->DrawModule(M_ANIMAL_PLAY_SHADOW, SCREEN_W - 30 -  menuSprite->GetModuleWidth(M_ANIMAL_PLAY_SHADOW), 430);
  
  menuSprite->DrawModule(M_SLIDE_TO_PLAY + ((blink > 5) ? 0 : 1), (SCREEN_W - menuSprite->GetModuleWidth(M_SLIDE_TO_PLAY)) >> 1, 480);
  
  menuSprite->DrawModule(M_SHADOW, 15, 435);
  menuSprite->DrawModule(M_ANIMAL_PLAY, playX, playY);
  
  for( int i = 0; i < numMenuItems; i++)
  {
     if(menuList[i]->isPressed())
    {
      switch (menuList[i]->id) {
        case M_ANIMAL_PLAY:
          Application::GetInstance()->mediaPlayer->Play(SELECT_SOUND);
          Application::GetInstance()->SwitchState(new InGameState());
          break;
        case M_ABOUT_US:
          Application::GetInstance()->mediaPlayer->Play(SELECT_SOUND);
          Application::GetInstance()->SwitchState(new AboutState());
          
          break;
        case M_OPTION:
          Application::GetInstance()->mediaPlayer->Play(SELECT_SOUND);
          Application::GetInstance()->SwitchState(new OptionState());
          break;
        case M_ACHIEVEMENTS:
          Application::GetInstance()->mediaPlayer->Play(SELECT_SOUND);
          break;
        default:
          break;
      }
    }
    else if(menuList[i]->isTouching())
    {
        menuSprite->DrawModule(menuList[i]->id + 1, menuList[i]->x, menuList[i]->y);      
        //Application::GetInstance()->mediaPlayer->Play(0);
    }
    
    else
    {
      menuSprite->DrawModule(menuList[i]->id, menuList[i]->x, menuList[i]->y);
    }
    
  }
};

void MainMenuState::Update()
{
  TouchManager *touchManager = TouchManager::GetInstance();
  if (!selecting)
  {
    if (touchManager->IsTouchDownInRect(playX, playY, menuSprite->GetModuleWidth(M_ANIMAL_PLAY), menuSprite->GetModuleHeight(M_ANIMAL_PLAY)))
    {
      selecting = true;
      Touch *touch = touchManager->GetFirstTouch();
      oldX = touch->GetX();
      oldY = touch->GetY();
      aX = 5;
    }
    
    if (playX > 20)
    {
      playX += aX;
      aX-=3;
    }

    if (playX < 20)
    {
      playX = 20;
    }

  }
  else 
  {
    Touch *touch = touchManager->GetFirstTouch();
    if (touch)
    {
      if (playX < SCREEN_W - 30 -  menuSprite->GetModuleWidth(M_ANIMAL_PLAY_SHADOW))
      {
         playX += touch->GetX() - oldX; 
      }
      else 
      {
        playX = SCREEN_W - 30 -  menuSprite->GetModuleWidth(M_ANIMAL_PLAY_SHADOW);
      }
      //playY += touch->GetY() - oldY;
      oldX = touch->GetX();
      oldY = touch->GetY();
    }
    else 
    {
      selecting = false;
      if (playX >= SCREEN_W - 30 -  menuSprite->GetModuleWidth(M_ANIMAL_PLAY_SHADOW))
      {
        Application::GetInstance()->mediaPlayer->Play(PLAY_SOUND);
        Application::GetInstance()->SwitchState(new InGameState());
      }
    }

  }
}

void MainMenuState::Free()
{
  delete bgSprite;
  delete menuSprite;
}
