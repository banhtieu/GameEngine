#ifdef WIN32

#include <stdio.h>
#include "WinDevice.h"
#include "MyGame.h"
#include "FileSystem.h"

bt::Application *app;
bt::Device *device;
bt::FileSystem *fileSystem;

int main()
{
  device = new bt::WinDevice();
  app = new MyGame();
  fileSystem = new bt::FileSystem(".", ".");
  device->Init();
  app->Init();

  while(device->Run())
  {
    app->Update();
    app->Render();
  }

  delete app;
  delete device;
  delete fileSystem;

  return 0;
};

#endif