//
//  StringManager.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

// Init the String Manager
StringManager::StringManager(): numStrings(0), strings(NULL)
{
}

// Destroy a String Manager
StringManager::~StringManager()
{
  FreeData();
}

// Set Color of Text
void StringManager::SetColor(Color color)
{
  textColor = color;
}

// Load Data From Resource file
void StringManager::Load(const char *filename)
{
  // Free Last data
  FreeData();
  
  FILE *fp = FileSystem::GetInstance()->OpenResource(filename, "rb");
  if (!fp)
  {
    LOGE("Couldn't open ");
  }
  
  fread(&numStrings, sizeof(int), 1, fp);
  
  strings = new unsigned char*[numStrings]; // create numStrings
  
  for (int i = 0; i < numStrings; i++)
  {
    int length = fgetc(fp); // get length of string
    strings[i] = new unsigned char[length + 1];
    strings[i][0] = (unsigned char) length;
    int count = fread(&strings[i][1], sizeof(char), length, fp);
    LOGI("Count: %d Length: %d", count, length);
  }
  
  sprite.LoadSprite(fp);
  
  fclose(fp);
}

// Draw a String with Index
void StringManager::Draw(int index, int x, int y, int flag)
{
  if (index < numStrings && index > 0)
  {
    DrawChars(strings[index], x, y, flag);
  }
}

// Draw a string Data
void StringManager::DrawChars(unsigned char *string, int x, int y, int flag)
{
  Graphics2D *graphics = Graphics2D::GetInstance();
  graphics->SetIsDrawString(true);
  graphics->SetColor(textColor);
  
  for (int i = 1; i <= string[0]; i++)
  {
    sprite.DrawModule(string[i], x, y);
    x += sprite.GetModuleWidth(string[i]);
  }
   
  graphics->SetIsDrawString(false);
}

// Draw A String
void StringManager::Draw(const char *string, int x, int y, int flag)
{
  unsigned char *data = new unsigned char[strlen(string) + 1];
  data[0] = (unsigned char) strlen(string);
  for (int i = 0; i < data[0]; i++)
  {
    if (string[i] >= ' ' && string[i] <= 'z')
    {
      data[i + 1] = string[i] - 32;
    }
    else
    {
      data[i + 1] = 0;
    }
  }
  DrawChars(data, x, y, flag);
  delete data;
}

// Get Bound of String
Frame2D StringManager::GetBound(int index)
{
  return GetBound(strings[index]);
}

// Get Bound of String Data
Frame2D StringManager::GetBound(unsigned char *data)
{
  return Frame2D();
}

// Free Data
void StringManager::FreeData()
{
  if (numStrings)
  {
    for (int i = 0; i < numStrings; i++)
    {
      delete strings[i];
    }
    delete strings;
  }
  
  sprite.FreeData();
}
