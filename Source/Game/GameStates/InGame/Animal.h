//
//  Animal.h
//  AnimoGame
//
//  Created by Tran Khiem on 3/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_Animal_h
#define AnimoGame_Animal_h

/**
 *
 **/
class Animal
{
public:
  int x;
  int y; 
  int state; // Animal ? Border or Picking;
  int animal;
  Touch *touch; // This Touch
  
  
  Animal(int x, int y, int animal);
  Animal();
  virtual ~Animal();
  void Render(Graphics2D graphics);
  void Update(); // Update with touch
  void SetTouch(Touch *touch); // This Touch Picks the Animal Up
};

#endif
