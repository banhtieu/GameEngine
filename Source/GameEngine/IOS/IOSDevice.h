//
//  BTIosDevice.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_iOSDevice_h
#define GameEngine_iOSDevice_h

#include "Engine.h"

class IOSDevice: public Device
{
public:
  virtual void Init();
  virtual void OnPause();
  virtual void OnResume();
  virtual void Free();
};

#endif
