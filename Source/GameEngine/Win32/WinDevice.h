#ifndef WINDEVICE_H_
#define WINDEVICE_H_

#ifdef WIN32

#include "Device.h"
#include <Windows.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>

namespace bt
{
  class WinDevice: public Device
  {
  public:
    virtual void Init();

    virtual void InitWindow();
    virtual void InitGLES();

    virtual bool Run();

  protected:
    HWND window;
    EGLSurface display, surface;
  };
};

#endif
#endif