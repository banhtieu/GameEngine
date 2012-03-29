//
//  MediaPlayeriPhone.h
//  AnimoGame
//
//  Created by Quang Phan on 19/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_MediaPlayeriPhone_h
#define AnimoGame_MediaPlayeriPhone_h


#include "SoundPack.h"
#include "Engine.h"

class MediaPlayeriPhone
{
public:
  MediaPlayeriPhone();
  void Create(int id);
  void Play();
  void Stop();
  void isPlaying();
  void Pause();
  void Resume();
  int type;
  
};

#endif
