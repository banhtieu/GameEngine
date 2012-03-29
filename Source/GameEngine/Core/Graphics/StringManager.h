//
//  StringManager.h
//  GameEngine
//
//  Created by Tran Khiem on 3/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_StringManager_h
#define GameEngine_StringManager_h

// Class String Manager
class StringManager:public Singleton<StringManager>
{
public:
  // Generate A String
  StringManager();
  
  // Destroy 
  virtual ~StringManager();
  
  virtual void Load(const char* filename);
  virtual void Draw(int index, int x, int y, int flag = 0);
  virtual void Draw(const char *string, int x, int y, int flag = 0);
  virtual void DrawChars(unsigned char *data, int x, int y, int flag = 0);
  
  // Get Bound of String
  virtual Frame2D GetBound(int index);
  virtual Frame2D GetBound(unsigned char *data);
  virtual void FreeData();
  virtual void SetColor(Color color);
  
protected:
  int numStrings; // number of Strings;
  unsigned char **strings; // string data;
  Sprite sprite; // Texture Sprite;
  Color textColor;
};


#endif
