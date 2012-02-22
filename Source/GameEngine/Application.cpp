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
  // Init the application.
  void Application::Init()
  {
    isExit = false;
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
  
  // Check the Application is Still Run.
  bool Application::Run()
  {
    return !isExit;
  }
  
  // Exit The Application.
  void Application::Exit()
  {
    isExit = true;
  }
  
};
