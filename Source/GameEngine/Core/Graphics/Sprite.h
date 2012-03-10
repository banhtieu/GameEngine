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
  ~Sprite();
  void LoadSprite(const char *name);
  void LoadSprite(FILE *fp);
  void DrawFrame(int frame, int x, int y);
  void DrawModule(int module, int x, int y);
protected:
  Texture *texture;
  Module *modules;
  Frame *frames;
  int nModules;
  int nFrames;
};


#endif
