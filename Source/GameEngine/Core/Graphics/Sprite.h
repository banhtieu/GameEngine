//
//  Sprite.h
//  GameEngine
//
//  Created by Tran Khiem on 3/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Sprite_h
#define GameEngine_Sprite_h


// The Image Module
struct Module
{
  int x;
  int y;
  int width;
  int height;
};

struct Frame
{
  int nVertices;
  float *vertices;
  float *texcoord;
};


// Sprite 
class Sprite
{
public:
  Sprite();
  Sprite(const char *name);
  virtual ~Sprite();
  virtual void LoadSprite(const char *name);
  virtual void LoadSprite(FILE *fp);
  virtual void DrawFrame(int frame, int x, int y);
  virtual void DrawModule(int module, int x, int y);
  virtual int GetModuleWidth(int module);
  virtual int GetModuleHeight(int module);
  virtual void FreeData();
protected:
  Texture *texture;
  Module *modules;
  Frame *frames;
  int nModules;
  int nFrames;
};


#endif
