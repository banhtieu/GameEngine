//
//  MediaPlayerManager.h
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_MediaPlayerManager_h
#define AnimoGame_MediaPlayerManager_h
#include "Engine.h"
//#import "MediaPlayeriPhone.h"

#define MAX_SOUND 10
class MediaPlayeriPhone;
class MediaPlayerManager
{
public:
   MediaPlayerManager();
  ~MediaPlayerManager();
public:
  void Init();
  void Play(int id);
  void Stop(int id);
  void Pause(int id);
  void PauseAllSounds();
  void Update();
public:
  int numberSound;
  MediaPlayeriPhone* listSound[MAX_SOUND];
};


#endif
