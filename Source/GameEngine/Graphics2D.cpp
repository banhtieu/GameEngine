//
//  Graphics2D.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

#if defined(ANDROID_OS) || defined(WIN32)

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#else

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#endif


// Init Graphics...
void Graphics2D::Init()
{
  
  // Init Screen Matrix
  screen =  Matrix33::TranslateMatrix(-1.0f, 1.0f) * Matrix33::ScaleMatrix(1.0f / SCREEN_WD2, - 1.0f / SCREEN_HD2) ;
  alphaBlender = 1.0f;
  
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
  uniforms[USE_COLOR] = glGetUniformLocation(programId, "useColor");
  uniforms[COLOR] = glGetUniformLocation(programId, "colorUniform");
  uniforms[MATRIX] = glGetUniformLocation(programId, "matrix");
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  PrintLog(programId);
  
  LOGI("Link Shader OK %d\n%s", uniforms[MATRIX], vertexShaderSource);
  glUseProgram(programId);
  glUniform1i(uniforms[USE_TEXTURE], 1);
  glUniform1f(uniforms[ALPHA], 1.0f);
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) screen.value.m);
  
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

void Graphics2D::SetTexture(Texture *texture)
{
  if (!texture->textureId)
  {
    glGenTextures(1, &texture->textureId);
    glBindTexture(GL_TEXTURE_2D, texture->textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    SAFE_DEL_ARRAY(texture->data);
  }
  
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->textureId);
  glUniform1i(uniforms[TEXTURE], 0);
  
}

// Free this Texture
void Graphics2D::FreeTexture(Texture *texture)
{
  if (texture->textureId)
  {
    glDeleteTextures(1, &texture->textureId);
  }
  SAFE_DEL_ARRAY(texture->data);
}

// Draw Texture With Frame
void Graphics2D::DrawTexture(Texture *texture, int dx, int dy, const Frame2D &frame)
{
  DrawTexture(texture, dx, dy, frame.x, frame.y, frame.w, frame.h);
}

void Graphics2D::DrawTexture(Texture *texture, int dx, int dy, int x, int y, int w, int h)
{
  SetTexture(texture);
  
  float vertices[] = {
    dx, 
    dy,
    dx + w,
    dy,
    dx,
    dy + h,
    dx + w,
    dy + h
  };
  
  float sx = 1.0f / texture->width;
  float sy = 1.0f / texture->height;
  
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
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 0);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  
}

// Set ALpha to Draw
void Graphics2D::SetAlpha(float alpha)
{
  alphaBlender = alpha;
}

// 
void Graphics2D::ClearFrame()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  SetTransform(Matrix33::Matrix33());
  SetAlpha(1.0f);
}

// Set The Transform Matrix
void Graphics2D::SetTransform(const Matrix33 &transform)
{
  this->transform = transform;
}
