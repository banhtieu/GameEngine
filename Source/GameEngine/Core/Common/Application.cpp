//
//  Application.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

Application::Application():currentState(0)
{
  new TouchManager();
};

Application::~Application()
{
  delete currentState;
}
// Init the application.
void Application::Init()
{
    //m_touchScreen = new TouchScreeniPhone(0, 0, 960, 640);
};

// Update the Application.
void Application::Update()
{
    Graphics2D *g = Graphics2D::GetInstance();
    g->ClearFrame();
    
    if (currentState)
    {
        currentState->Update();
        currentState->Render(g);
    }

};

// Render this Application.
void Application::Render()
{
};

// Free this Application
void Application::Free()
{
  if (currentState)
  {
    currentState->Free();
  }
};

// Switch to another state.
void Application::SwitchState(State *newState)
{
  if (currentState)
  {
    currentState->Free();
  }
  
  currentState = newState;
  currentState->Init();
}
