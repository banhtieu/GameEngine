#ifdef WIN32

#include <stdio.h>
#include "WinDevice.h"
#include "MyGame.h"

Application *app;
Device *device;
FileSystem *fileSystem;

int main()
{
  device = new WinDevice();
  app = new MyGame();
  fileSystem = new FileSystem(".", ".");
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