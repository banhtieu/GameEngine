//
//  Texture.h
//  GameEngine
//
//  Created by Tran Khiem on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Texture_h
#define GameEngine_Texture_h

#include "Config.h"

// Namespace BT.
namespace bt
{
  
  class Texture
  {
    
  public:
    unsigned int width;
    unsigned int height;
    unsigned int textureId;
    unsigned char *data;
    
    Texture();
    virtual ~Texture();
    
    static Texture* LoadTexture(const char *filename);
  };
  
};


#endif
