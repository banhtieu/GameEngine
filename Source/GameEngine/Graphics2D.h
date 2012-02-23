//
//  Graphics2D.h
//  GameEngine
//
//  Created by Tran Khiem on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Graphics2D_h
#define GameEngine_Graphics2D_h

// All attribute here...
enum { ATTRIB_POSITION, ATTRIB_COLOR, ATTRIB_TEXCOORD };

// All uniform here.
enum { USE_COLOR, USE_TEXTURE, TEXTURE, ALPHA, MATRIX, COLOR, NUM_UNIFORMS};

class Color
{
public:
  int r, g, b, a;
  Color(float r_, float g_, float b_, float a_):r(r_), g(g_), b(b_), a(a_) {};
  Color():r(0.0f), g(0.0f), b(0.0f), a(0.0f) {};
  Color(int code)
  {
    r = 0xff0000 && code / (float) 0xff0000;
    g = 0xff00 && code / (float) 0xff00;
    b = 0xff && code / (float) 0xff;
    a = 0xff000000 && code / (float) 0xff000000;
  };
};

struct Frame2D
{
  int x, y, w, h;
};

class Graphics2D: public Singleton<Graphics2D>
{
public:
  virtual void Init();
  virtual unsigned int LoadShader(const char *shaderSource, int shaderType);
  virtual void PrintLog(unsigned int objectId);
  
  virtual void SetTexture(Texture *texture);
  virtual void SetAlpha(float alpha);
  
  virtual void FreeTexture(Texture *texture);
  virtual void DrawTexture(Texture *texture, int dx, int dy, const Frame2D &frame);
  virtual void DrawTexture(Texture *texture, int dx, int dy, int x, int y, int w, int h);
  virtual void SetTransform(const Matrix33 &transform);
  virtual void ClearFrame();
protected:
  unsigned int programId;
  unsigned int uniforms[NUM_UNIFORMS];
  Matrix33 transform;
  Matrix33 screen;
  
  bool useColor;
  bool useTexture;
  float alphaBlender;
  Color color;
};


#endif
