//
//  Graphics2D.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Graphics2D.h"
#include "FileSystem.h"

#ifdef ANDROID_OS

#import <GLES2/gl2.h>
#import <GLES2/glext.h>

#else

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#endif

namespace bt {
  
  // Init Graphics...
  void Graphics2D::Init()
  {
    // load shader.
    FileSystem *fileSystem = FileSystem::GetInstance();
    
    char *vertexShaderSource = fileSystem->GetResourceContent("Shader.vsh");
    char *fragmentShaderSource = fileSystem->GetResourceContent("Shader.fsh");
    
    unsigned int vertexShader = LoadShader(vertexShaderSource, GL_VERTEX_SHADER);
    unsigned int fragmentShader = LoadShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    
    programId = glCreateProgram();
    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);
    
    glBindAttribLocation(programId, ATTRIB_POSITION, "position");
    glBindAttribLocation(programId, ATTRIB_COLOR, "color");
    glBindAttribLocation(programId, ATTRIB_TEXCOORD, "texcoord");
    
    glLinkProgram(programId);
    
    uniforms[ALPHA] = glGetUniformLocation(programId, "alphaBlender");
    uniforms[TEXTURE] = glGetUniformLocation(programId, "texture");
    uniforms[USE_TEXTURE] = glGetUniformLocation(programId, "useTexture");
    uniforms[USE_COLOR] = glGetUniformLocation(programId, "useColor");
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    PrintLog(programId);
    
    LOGI("Link Shader OK");
    glUseProgram(programId);
    glUniform1i(uniforms[USE_TEXTURE], 1);
    glUniform1f(uniforms[ALPHA], 1.0f);
    
    delete vertexShaderSource;
    delete fragmentShaderSource;
  }
  
  // Load Shader
  unsigned int Graphics2D::LoadShader(const char *shaderSource, int shaderType)
  {
    unsigned int shaderId = glCreateShader(shaderType);
    int status = 0;
    
    glShaderSource(shaderId, 1, &shaderSource, 0);
    glCompileShader(shaderId);

    PrintLog(shaderId);

    // Check status
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
    
    if (!status)
    {
      glDeleteShader(shaderId);
      shaderId = 0;
    }
    
    return shaderId;
  }
  
  void Graphics2D::PrintLog(unsigned int objectId)
  {
#ifdef DEBUG
    int logLength = 0;
    glGetShaderiv(objectId, GL_INFO_LOG_LENGTH, &logLength);
    
    if (logLength > 0)
    {
      char *logInfo = new char[logLength];
      glGetShaderInfoLog(logLength, logLength, &logLength, logInfo);
      LOGI("Compile Shader: %s\n", logInfo);
      delete logInfo;
    }
#endif
  }
  
  void Graphics2D::SetTexture(bt::Texture *texture)
  {
    if (!texture->textureId)
    {
      glGenTextures(1, &texture->textureId);
      glBindTexture(GL_TEXTURE_2D, texture->textureId);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }
    
    glBindTexture(GL_TEXTURE_2D, texture->textureId);
    glActiveTexture(GL_TEXTURE1);
    glUniform1i(uniforms[TEXTURE], 0);
    
  }
  
  void Graphics2D::DrawTexture(Texture *texture, int dx, int dy, int x, int y, int w, int h)
  {
    SetTexture(texture);
    
    float sx = 2.0f / SCREEN_W;
    float sy = 2.0f / SCREEN_H;
    
    float vertices[] = {
      sx * (dx - SCREEN_WD2), 
      sy * (SCREEN_HD2 - dy),
      sx * (dx + w - SCREEN_WD2),
      sy * (SCREEN_HD2 - dy),
      sx * (dx - SCREEN_WD2),
      sy * (SCREEN_HD2 - dy - h),
      sx * (dx + w - SCREEN_WD2),
      sy * (SCREEN_HD2 - dy - h)
    };
    
    sx = 1.0f / texture->width;
    sy = 1.0f / texture->height;
    
    float texcoord[] = {
      sx * x, 
      sy * y,
      sx * (x + w),
      sy * y,
      sx * x,
      sy * (y + h),
      sx * (x + w),
      sy * (y + h)
    };
    
    glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(ATTRIB_POSITION);
    
    glVertexAttribPointer(ATTRIB_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 0, texcoord);
    glEnableVertexAttribArray(ATTRIB_TEXCOORD);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    
  }
  
}
