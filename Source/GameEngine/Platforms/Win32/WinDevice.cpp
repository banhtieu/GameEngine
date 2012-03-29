#ifdef WIN32
// Only Compile on Windows 32 bit
#include "WinDevice.h"
#include <time.h>
#include <assert.h>

/**
 * Windows Proc
 **/
LRESULT WINAPI WndProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );


/**
  * Init Windows Device
  **/
void WinDevice::Init()
{
  InitWindow();
  InitGLES();

  Device::Init();
};

bool WinDevice::Run()
{
  MSG msg = {0};
  long startFrame = clock();
  int gotMessage = (PeekMessage(&msg, window, 0, 0, PM_REMOVE) != 0);

  if (gotMessage)
  {
    if (msg.message == WM_QUIT)
    {
      exit = true;
    }
    else
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    };
  }
  else
  {

    long frameTime = clock() - startFrame;
    if (frameTime < 1000 / LIMIT_FPS)
    {
      Sleep(1000 / LIMIT_FPS - frameTime);
    }

    eglSwapBuffers ( display, surface );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  return !exit;
};

/**
  * Init Windows
  **/
void WinDevice::InitWindow()
{
  WNDCLASS wndClass = {0};

  DWORD    wStyle   = 0;
  RECT     windowRect;
  HINSTANCE hInstance = GetModuleHandle(NULL);


  wndClass.style         = CS_OWNDC;
  wndClass.lpfnWndProc   = (WNDPROC) WndProc; 
  wndClass.hInstance     = hInstance; 
  wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
  wndClass.lpszClassName = "BanhtieuGame";

  // Register Windows Class
  assert(RegisterClass (&wndClass) );
        

  wStyle = WS_VISIBLE | WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION;
  windowRect.left = 0;
  windowRect.top = 0;
  windowRect.right = SCREEN_W;
  windowRect.bottom = SCREEN_H;

  AdjustWindowRect ( &windowRect, wStyle, FALSE );
  window = CreateWindow(
    "BanhTieuGame",
    "99Cents Game",
    wStyle,
    0,
    0,
    windowRect.right - windowRect.left,
    windowRect.bottom - windowRect.top,
    NULL,
    NULL,
    hInstance,
    NULL
  );

  ShowWindow(window, true);
  LOGI("CREATE WINDOWS %d\n", window);
};

void WinDevice::InitGLES()
{
  EGLint numConfigs;
  EGLint majorVersion;
  EGLint minorVersion;

  EGLConfig config;
  EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };

  EGLint attribList[] =
  {
    EGL_RED_SIZE, 5,
    EGL_GREEN_SIZE, 6,
    EGL_BLUE_SIZE, 5,
    EGL_ALPHA_SIZE, 8,
    EGL_DEPTH_SIZE, 8,
    EGL_STENCIL_SIZE, 8,
    EGL_SAMPLE_BUFFERS, 1,
    EGL_NONE
  };

  display = eglGetDisplay(GetDC(window));

  if ( display == EGL_NO_DISPLAY )
  {
    LOGE("Cannot Get Display for OPENGLES 2.0");
  }

  // Initialize EGL
  if ( !eglInitialize(display, &majorVersion, &minorVersion) )
  {
    LOGE("Cannot Init OPENGLES 2.0");
  }

  // Get configs
  if ( !eglGetConfigs(display, NULL, 0, &numConfigs) )
  {
    LOGE("Cannot get Config for OPENGLES 2.0");
  }

  // Choose config
  if ( !eglChooseConfig(display, attribList, &config, 1, &numConfigs) )
  {
    LOGE("Cannot Chose Config for OPENGLES 2.0");
  }

  // Create a surface
  surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType) window, NULL);
  if ( surface == EGL_NO_SURFACE )
  {
    LOGE("Cannot Create Window Surface for OPENGLES 2.0");
  }

  // Create a GL context
  EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs );

  if ( context == EGL_NO_CONTEXT )
  {
    LOGE("Cannot Create Context for OPENGLES 2.0");
  }   
   
  // Make the context current
  if ( !eglMakeCurrent(display, surface, surface, context) )
  {
    LOGE("Cannot Display Current OPENGLES 2.0");
  }
};


    
/**
 * WINDOWS PROC
 **/
LRESULT WINAPI WndProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{
  LRESULT  lRet = 1; 
  int x = LOWORD(lParam); 
  int y = HIWORD(lParam);
  int key = 0;
  static int mouseDown = false;

  switch (uMsg) 
  { 
  case WM_DESTROY:
    Device::GetInstance()->Exit();
    break; 
  case WM_LBUTTONDOWN:        
    mouseDown = true;
    break;

  case WM_MOUSEMOVE:
    if (mouseDown)
    {
    };
    break;

  case WM_LBUTTONUP:
    mouseDown = false;
    break;    

  case WM_KEYDOWN:
    x = wParam; // x for key code        
    break;
  default: 
    // return for DefWindowProc Handle
    lRet = DefWindowProc (hWnd, uMsg, wParam, lParam); 
    break; 
  };
  return lRet;
};

#endif