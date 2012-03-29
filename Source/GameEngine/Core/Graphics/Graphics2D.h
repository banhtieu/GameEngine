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
enum { USE_COLOR, USE_TEXTURE, TEXTURE, ALPHA, MATRIX, COLOR, IS_DRAW_STRING, NUM_UNIFORMS};

// Number of Matrix Level
#define NUM_MATRIX_LEVELS 20

class Color
{
public:
  float r, g, b, a;
  Color(float r_, float g_, float b_, float a_):r(r_), g(g_), b(b_), a(a_) {};
  Color():r(0.0f), g(0.0f), b(0.0f), a(0.0f) {};
  Color(unsigned int code)
  {
    r = (0xff0000 & code) / (float) 0xff0000;
    g = (0xff00 & code) / (float) 0xff00;
    b = (0xff & code) / (float) 0xff;
    a = (0xff000000 & code) / (float) 0xff000000;
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
  virtual void DrawTexture(Texture *texture, float dx, float dy, const Frame2D &frame);
  virtual void DrawTexture(Texture *texture, float dx, float dy, int x, int y, int w, int h);
  virtual void DrawTexture(Texture *texture, float x, float y, int nVertices, float *vertices, float *texcoord);
  virtual void SetTransform(const Matrix33 &transform);
  virtual void ConcatTrasform(const Matrix33 &addtional);
  virtual Matrix33 &GetTransform();
  
  virtual void ClearFrame();
  virtual void Clear();
  // Draw Basic Shape
  virtual void SetColor(Color color);
  virtual void DrawLine(float x1, float y1, float x2, float y2);
  virtual void DrawRectangle(float x, float y, float w, float h);
  virtual void DrawCirle(float x, float y, float r);
  
  virtual void FillRectange(float x, float y, float w, float h);
  virtual void FillCircle(float x, float y, float r);
  
  virtual void Save();
  virtual void Restore();
  
  virtual void SetIsDrawString(bool isDrawString);
  
protected:
  unsigned int programId;
  unsigned int uniforms[NUM_UNIFORMS];
  Matrix33 transform;
  Matrix33 screen;
  
  Matrix33 savedMatrices[NUM_MATRIX_LEVELS];
  int currentLevel;
  
  bool useColor;
  bool useTexture;
  float alphaBlender;
  Color color;
};


#endif
