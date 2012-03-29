//
//  AnimalTray.h
//  AnimoGame
//
//  Created by Tran Khiem on 3/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_AnimalTray_h
#define AnimoGame_AnimalTray_h

#include <vector>
#include "Engine.h"
#include "Animal.h"

using namespace std;

class AnimalTray
{
public:
  AnimalTray();
  virtual ~AnimalTray();
  virtual bool IsFull();
  virtual void AddAnimal();
  virtual void Update();
  virtual void Render(Graphics2D graphics);
protected:
  vector<Animal> animals; // Animal in Tray
};


#endif
