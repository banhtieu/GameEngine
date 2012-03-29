//
//  MediaPlayerManager.cpp
//  AnimoGame
//
//  Created by Quang Phan on 18/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "MediaPlayerManager.h"
#include "SoundPack.h"
#include "MediaPlayeriPhone.h"

MediaPlayerManager::MediaPlayerManager()
{
  numberSound = NUM_SOUND;
  for( int i=0; i< numberSound; i++)
  {
    listSound[i] = new MediaPlayeriPhone();
    listSound[i]->Create(i);
    
  }
}

void MediaPlayerManager::Init()
{
  
}

void MediaPlayerManager::Play(int id)
{
  
  //listSound[id]->Play(0);;
  listSound[id]->Play();
}

void MediaPlayerManager::Stop(int id)
{
}

void MediaPlayerManager::Pause(int id)
{
  
}

void MediaPlayerManager::PauseAllSounds()
{
  
}
