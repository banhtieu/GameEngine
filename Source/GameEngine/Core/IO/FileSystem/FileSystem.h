//
//  FileSystem.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_FileSystem_h
#define GameEngine_FileSystem_h

#include <stdio.h>

class FileSystem: public Singleton<FileSystem>
{
public:
  FileSystem(const char *documentP, const char *resourceP);
  virtual ~FileSystem(); 
  virtual char *GetResourceContent(const char *filename);
  virtual FILE *OpenResource(const char *filename, const char *mode);
  virtual FILE *OpenDocument(const char *filename, const char *mode);
public:
  char *documentPath;
  char *resourcePath;
};

#endif
