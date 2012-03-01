//
//  Sprite.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

// Init a Blank Sprite
Sprite::Sprite():modules(NULL), frames(NULL), nModules(0), nFrames(0), texture(NULL)
{
}

// Init The Sprite with name
Sprite::Sprite(const char *name):modules(NULL), frames(NULL), nModules(0), nFrames(0), texture(NULL)
{
  LoadSprite(name);
}

// Unfinished a sprite
Sprite::~Sprite()
{
  SAFE_DEL_ARRAY(modules);
  SAFE_DEL_ARRAY(frames);
  SAFE_DEL(texture);
}

void Sprite::LoadSprite(const char *name)
{
  char fileName[255];
  sprintf(fileName, "%s.png", name);
  texture = Texture::LoadTexturePNG(fileName);
  
  sprintf(fileName, "%s.bin", name);
  FILE *fp = FileSystem::GetInstance()->OpenResource(fileName, "rb");
  // Read Modules
  fread(&nModules, sizeof(int), 1, fp);
  modules = new Module[nModules];
  fread(modules, sizeof(Module), nModules, fp);
  
  // Read Frames 
  fread(&nFrames, sizeof(int), 1, fp);
  frames = new Frame[nFrames];
  
  for (int i = 0; i < nFrames; i++)
  {
    fread(&frames[i].nVertices, sizeof(int), 1, fp);
    
    frames[i].vertices = new float[frames[i].nVertices * 2];
    frames[i].texcoord = new float[frames[i].nVertices * 2];
    
    fread(frames[i].vertices, sizeof(float), frames[i].nVertices * 2, fp);
    fread(frames[i].texcoord, sizeof(float), frames[i].nVertices * 2, fp);
  }
}


void Sprite::DrawFrame(int frame, int x, int y)
{
  Graphics2D *graphic = Graphics2D::GetInstance();
  if (frame < nFrames)
  {
    graphic->DrawTexture(texture, x, y, frames[frame].nVertices, frames[frame].vertices, frames[frame].texcoord);
  }
}

void Sprite::DrawModule(int module, int x, int y)
{
  Graphics2D *graphic = Graphics2D::GetInstance();
  if (module < nModules)
  {
    graphic->DrawTexture(texture, x, y, modules[module].x, modules[module].y, modules[module].width, modules[module].height);
  }
}

