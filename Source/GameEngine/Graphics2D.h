//
//  Graphics2D.h
//  GameEngine
//
//  Created by Tran Khiem on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Graphics2D_h
#define GameEngine_Graphics2D_h

#include "Config.h"
#include "Singleton.h"
#include "Texture.h"


namespace bt
{
  // All attribute here...
  enum { ATTRIB_POSITION, ATTRIB_COLOR, ATTRIB_TEXCOORD };
  
  // All uniform here.
  enum { USE_COLOR, USE_TEXTURE, TEXTURE, ALPHA, NUM_UNIFORMS};
  
  class Graphics2D: public Singleton<Graphics2D>
  {
  public:
    virtual void Init();
    virtual unsigned int LoadShader(const char *shaderSource, int shaderType);
    virtual void PrintLog(unsigned int objectId);
    
    virtual void SetUseColor(bool useColor){};
    virtual void SetUseTexture(bool useTexture){};
    virtual void SetTexture(Texture *texture);
    virtual void SetAlpha(float alpha){};
    
    virtual void FreeTexture(Texture *texture){};
    
    virtual void DrawTexture(Texture *texture, int dx, int dy, int x, int y, int w, int h);
  protected:
    unsigned int programId;
    unsigned int uniforms[NUM_UNIFORMS];
  };
};


#endif
