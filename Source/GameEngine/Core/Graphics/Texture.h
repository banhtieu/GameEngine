//
//  Texture.h
//  GameEngine
//
//  Created by Tran Khiem on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Texture_h
#define GameEngine_Texture_h


class Texture
{
  
public:
  unsigned int width;
  unsigned int height;
  unsigned int textureId;
  unsigned int nChannels;
  char *data;
  
  Texture();
  virtual ~Texture();
  
  static Texture* LoadTexturePNG(FILE *fp);
  static Texture* LoadTexturePNG(const char *filename);
};


#endif
