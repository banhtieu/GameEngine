//
//  Texture.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Texture.h"
#include "Graphics2D.h"

namespace bt
{
  
  // Constructor .
  Texture::Texture():textureId(0), data(0), width(0), height(0)
  {
  }
  
  // Delete the texture..
  Texture::~Texture()
  {
    if (textureId)
    {
      Graphics2D::GetInstance()->FreeTexture(this);
    }
    delete data;
  }
}
