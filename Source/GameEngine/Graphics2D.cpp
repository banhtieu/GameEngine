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
    
    PrintLog(programId);
    
    LOGI("Link Shader OK");
    
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
  
}
