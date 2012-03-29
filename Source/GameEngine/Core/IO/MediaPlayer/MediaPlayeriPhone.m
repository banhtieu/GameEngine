//
//  MediaPlayeriPhone.m
//  AnimoGame
//
//  Created by Quang Phan on 19/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "MediaPlayeriPhone.h"
#import <AVFoundation/AVAudioPlayer.h>

AVAudioPlayer* player;
MediaPlayeriPhone::MediaPlayeriPhone()
{

}

void MediaPlayeriPhone::Create(int id)
{
  NSError *error;
  NSString *path = [NSString stringWithFormat:@"%s/%d.wav",FileSystem::GetInstance()->resourcePath,id];
  player =[[AVAudioPlayer alloc] initWithContentsOfURL:[NSURL fileURLWithPath:path] error:&error];
  if(!player)
  {
    NSLog(@"Fail to create player id = %d",id);
  }
}

void MediaPlayeriPhone::Play()
{
  [player play];
}
