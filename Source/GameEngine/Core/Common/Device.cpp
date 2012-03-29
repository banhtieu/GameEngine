//
//  Device.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"
  
// Free The Device
Device::~Device()
{
}

void Device::Free()
{
  Graphics2D::FreeInstance();
}

// Init This Device..
void Device::Init()
{
  graphics2D = new Graphics2D();
  graphics2D->Init();
}

bool Device::Run()
{
  return !exit;
}

void Device::Exit()
{
  exit = true;
}