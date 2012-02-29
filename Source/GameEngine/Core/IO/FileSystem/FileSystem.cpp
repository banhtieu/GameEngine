//
//  FileSystem.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"
#include <string.h>


FileSystem::FileSystem(const char *document, const char *resource)
{
  documentPath = new char[strlen(document) + 1];
  resourcePath = new char[strlen(resource) + 1];
  strcpy(documentPath, document);
  strcpy(resourcePath, resource);
}

FileSystem::~FileSystem()
{
  delete documentPath;
  delete resourcePath;
}

// Open a file from Resource Folder.
FILE *FileSystem::OpenResource(const char *filename, const char *mode)
{
  char realPath[255];
  sprintf(realPath, "%s/%s", resourcePath, filename);
  return fopen(realPath, mode);
}

// Open a file from Document Folder.
FILE *FileSystem::OpenDocument(const char *filename, const char *mode)
{
  char realPath[255];
  sprintf(realPath, "%s/%s", documentPath, filename);
  return fopen(realPath, mode);
}

// Get Resource Content as a String...
char * FileSystem::GetResourceContent(const char *filename)
{
  FILE *fp = OpenResource(filename, "rb");
  int size = 0;
  char *result = NULL;
  
  if (fp)
  {
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    
    fseek(fp, 0, SEEK_SET);
    
    if (size)
    {
      result = new char[size + 1];
      
      fread(result, size, sizeof(char), fp);
      result[size] = 0;
    }
    else
    {
      LOGE("File %s is Empty!!\n", filename);
    }
  }
  else
  {
    LOGE("Cannot Open File %s\n", filename);
  }
  
  return result;
}
