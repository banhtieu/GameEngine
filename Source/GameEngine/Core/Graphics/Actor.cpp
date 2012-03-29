//
//  Actor.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

// Create an Actor With Sprite & animation
Actor::Actor(Sprite *sprite_, int frameId_, int nFrames_)
  : sprite(sprite_),
    currentFrame(0)
{
  SetAnimation(frameId_, nFrames_);
  SetPosition(x, y);
  SetRotation(0);
}


// Destroy the Actor
Actor::~Actor()
{
}

// Set Animation - animate nFrames from frameId
void Actor::SetAnimation(int frameId, int nFrames)
{
  this->frameId = frameId;
  this->nFrames = nFrames;
}

// Set Position 
void Actor::SetPosition(int x, int y)
{
  this->x = x;
  this->y = y;
}

// Set FlippedX or not
void Actor::SetFlippedX(bool isFlipped)
{
  flipFlag = isFlipped ? (flipFlag | FLIP_X) : (flipFlag & ~FLIP_X);
}

// Set FlippedY or not
void Actor::SetFlippedY(bool isFlipped)
{
  flipFlag = isFlipped ? (flipFlag | FLIP_Y) : (flipFlag & ~FLIP_Y);
}

// Set Rotation 
void Actor::SetRotation(float alpha)
{
  this->alpha = alpha;
}

// Paint this actor
void Actor::Paint()
{
  // Scale X & scale Y
  float scaleX = 1.0, scaleY = 1.0;
  Graphics2D *g = Graphics2D::GetInstance();
  g->Save();
  
  if (flipFlag & FLIP_X) 
  {
    scaleX = -1.0f;
  }
  
  if (flipFlag & FLIP_Y) 
  {
    scaleY = -1.0f;
  }
  
  g->ConcatTrasform(Matrix33::TranslateMatrix(x, y) * Matrix33::RotateMatrix(alpha) * Matrix33::ScaleMatrix(scaleX, scaleY));
  
  sprite->DrawFrame(frameId + currentFrame, 0, 0);
  
  currentFrame = (currentFrame + 1) % nFrames;
  g->Restore();
}
