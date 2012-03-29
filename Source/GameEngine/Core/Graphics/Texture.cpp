//
//  Texture.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"
#include "png.h"



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

// Load Texture From File
Texture* Texture::LoadTexturePNG(FILE *fp)
{
  Texture *readTexture = new Texture();
  unsigned int imageWidth, imageHeight;
  char *imageData;
  
  png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop infoPtr = png_create_info_struct(pngPtr);
  
  png_init_io(pngPtr, fp);
  png_read_info(pngPtr, infoPtr);
  
  imageWidth = png_get_image_width(pngPtr, infoPtr);
  imageHeight = png_get_image_height(pngPtr, infoPtr);
  
  //bits per CHANNEL! note: not per pixel!
  png_uint_32 bitdepth   = png_get_bit_depth(pngPtr, infoPtr);
  
  //Number of channels
  png_uint_32 channels   = png_get_channels(pngPtr, infoPtr);
  
  //Color type. (RGB, RGBA, Luminance, luminance alpha... palette... etc)
  png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);
  
  switch (color_type) {
    case PNG_COLOR_TYPE_PALETTE:
      png_set_palette_to_rgb(pngPtr);        
      channels = 3;           
      break;
  }
  
  /*if the image has a transperancy set.. convert it to a full Alpha channel..*/
  if (png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)) {
    png_set_tRNS_to_alpha(pngPtr);
    channels += 1;
  }
  
  //We don't support 16 bit precision.. so if the image Has 16 bits per channel
  //precision... round it down to 8.
  if (bitdepth == 16)
    png_set_strip_16(pngPtr);
  
  imageData = new char[imageWidth * imageHeight * bitdepth * channels >> 3];
  const unsigned int stride = imageWidth * bitdepth * channels >> 3;
  png_bytep* rowPtrs = new png_bytep[imageHeight];
  
  for (size_t i = 0; i < imageHeight; i++) {
    int q = (i) * stride;
    rowPtrs[i] = (png_bytep) imageData + q;
  }
  
  png_read_image(pngPtr, rowPtrs);
  
  delete [] rowPtrs;
  png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
  
  readTexture->width = imageWidth;
  readTexture->height = imageHeight;
  readTexture->data = imageData;
  readTexture->nChannels = channels;
  
  return readTexture;
}

// Load Texture From File with File name
Texture* Texture::LoadTexturePNG(const char *filename)
{
  FILE *fp = FileSystem::GetInstance()->OpenResource(filename, "rb");
  
  if (!fp)
  {
    LOGE("Cannot Load File %s\n", filename);
    return NULL;
  }
  
  Texture *result = Texture::LoadTexturePNG(fp);
  fclose(fp);
  
  return result;
}
