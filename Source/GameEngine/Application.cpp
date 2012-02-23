//
//  Application.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Application.h"

namespace bt
{

  Application::Application():currentState(0)
  {
  };

  Application::~Application()
  {
    delete currentState;
  }
  // Init the application.
  void Application::Init()
  {
  };
  
  // Update the Application.
  void Application::Update()
  {
    if (currentState)
    {
      currentState->Update();
    }
  };
  
  // Render this Application.
  void Application::Render()
  {
    if (currentState)
    {
      currentState->Render();
    }
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
  void Application::SwitchState(bt::state::State *newState)
  {
    if (currentState)
    {
      currentState->Free();
    }
    
    currentState = newState;
    currentState->Init();
  }
  
};
