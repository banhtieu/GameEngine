//
//  BTDevice.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Device_h
#define GameEngine_Device_h

// Name space BT;

class Device: public Singleton<Device>
{
public:
  Device():exit(0) {};
  ~Device();
  virtual void Init();
  virtual bool Run();
  virtual void Exit();
  virtual void Free();
protected:
  Graphics2D *graphics2D;
  bool exit;
};

#endif
