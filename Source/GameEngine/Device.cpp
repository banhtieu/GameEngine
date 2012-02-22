//
//  Device.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Device.h"

namespace bt
{
  
  // Init This Device..
  void Device::Init()
  {
    graphics2D = new Graphics2D();
    graphics2D->Init();
  }
}