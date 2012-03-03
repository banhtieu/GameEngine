//
//  Actor.h
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Actor_h
#define GameEngine_Actor_h

// Flip Type
enum FlipType {
  FLIP_NONE,
  FLIP_X,
  FLIP_Y
};

// An Actor in Game
class Actor
{
public:
  
  // Create an actor with the Sprite.
  Actor(Sprite *sprite, int frameId = 0, int nFrames = 0);
  virtual ~Actor();
  
  virtual void SetAnimation(int frameId, int nFrames);
  virtual void SetPosition(int x, int y);
  virtual void SetFlippedX(bool isFlipped);
  virtual void SetFlippedY(bool isFlipped);
  virtual void SetRotation(float alpha);
  virtual void Paint();
  
protected:
  // position
  int x, y;
  
  // type of flipped.
  int flipFlag;
  float alpha;
  int frameId;
  int nFrames;
  int currentFrame;
  Sprite *sprite;
};

#endif
