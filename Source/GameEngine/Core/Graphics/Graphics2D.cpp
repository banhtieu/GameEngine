//
//  Graphics2D.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"
#include <math.h>

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
  uniforms[IS_DRAW_STRING] = glGetUniformLocation(programId, "isDrawString");
  
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
void Graphics2D::DrawTexture(Texture *texture, float dx, float dy, const Frame2D &frame)
{
  DrawTexture(texture, dx, dy, frame.x, frame.y, frame.w, frame.h);
}

// Draw Texture
void Graphics2D::DrawTexture(Texture *texture, float dx, float dy, int x, int y, int w, int h)
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
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  
}

// Draw Texture with vertices and Texcoord
void Graphics2D::DrawTexture(Texture *texture, float x, float y, int nVertices, float *vertices, float *texcoord)
{
  SetTexture(texture);
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glVertexAttribPointer(ATTRIB_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 0, texcoord);
  glEnableVertexAttribArray(ATTRIB_TEXCOORD);
  

  Matrix33 result = screen * transform * Matrix33::TranslateMatrix(x, y);
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 0);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  
  glDrawArrays(GL_TRIANGLES, 0, nVertices);
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
void Graphics2D::Clear()
{
    glClearColor(0.00f, 0.00f, 0.00f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
// Set The Transform Matrix
void Graphics2D::SetTransform(const Matrix33 &transform)
{
  this->transform = transform;
}

// Concat the transform with current transformation 
void Graphics2D::ConcatTrasform(const Matrix33 &addtional)
{
  transform = transform * addtional;
}

// Get Current Transformation
Matrix33 &Graphics2D::GetTransform()
{
  return transform;
}

// Draw Basic Shape - To Debug
// Draw Basic Shape
void Graphics2D::SetColor(Color color)
{
  this->color = color;
}

// Draw a Line
void Graphics2D::DrawLine(float x1, float y1, float x2, float y2)
{
  float vertices[] = {x1, y1, x2, y2};
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 1);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  
  glDrawArrays(GL_LINES, 0, 2);
  
}

void Graphics2D::DrawRectangle(float x, float y, float w, float h)
{
  float vertices[] = {x, y, x + w, y, x + w, y + h, x, y + h};
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 1);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  
  glDrawArrays(GL_LINE_LOOP, 0, 4);
}

// Draw the Circle
void Graphics2D::DrawCirle(float x, float y, float r)
{
  float vertices[36];
  float step = (float) M_PI / 8;
  for (int i = 0; i < 18; i++)
  {
    vertices[i * 2] = x + r * cos(i * step);
    vertices[i * 2 + 1] = y + r * sin(i * step);
  }
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 1);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  
  glDrawArrays(GL_LINE_LOOP, 0, 18);
  
}

void Graphics2D::FillRectange(float x, float y, float w, float h)
{
  float vertices[] = {x, y, x + w, y, x, y + h, x + w, y + h};
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 1);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

// Fill the circle...
void Graphics2D::FillCircle(float x, float y, float r)
{
  float vertices[38];
  float step = (float) M_PI / 8;
  vertices[0] = x;
  vertices[1] = y;
  for (int i = 1; i < 19; i++)
  {
    vertices[i * 2] = x + r * cos(i * step);
    vertices[i * 2 + 1] = y + r * sin(i * step);
  }
  
  glVertexAttribPointer(ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glEnableVertexAttribArray(ATTRIB_POSITION);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  Matrix33 result = screen * transform;
  
  glUniformMatrix3fv(uniforms[MATRIX], 1, GL_FALSE, (float *) result.value.m);
  glUniform1i(uniforms[USE_COLOR], 1);
  glUniform1f(uniforms[ALPHA], alphaBlender);
  glUniform4f(uniforms[COLOR], color.r, color.g, color.b, color.a);
  
  glDrawArrays(GL_TRIANGLE_FAN, 0, 18);
}

// Save Transformation
void Graphics2D::Save()
{
  savedMatrices[currentLevel++] = transform;
}

// Restore Transformation
void Graphics2D::Restore()
{
  SetTransform(savedMatrices[--currentLevel]);
}

// Set is Drawing String or Not
void Graphics2D::SetIsDrawString(bool isDrawString)
{
  glUniform1i(uniforms[IS_DRAW_STRING], isDrawString);
}