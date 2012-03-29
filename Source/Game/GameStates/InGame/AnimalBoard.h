//
//  AnimalBoard.h
//  AnimoGame
//
//  Created by Tran Khiem on 3/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_AnimalBoard_h
#define AnimoGame_AnimalBoard_h

#include "AnimalTray.h"

#define MAX_ROWS 6
#define MAX_COLUMN 10

/**
 * The Animal Board 
 **/
class AnimalBoard:public Singleton<AnimalBoard>
{

public:
  AnimalBoard();
  ~AnimalBoard();
  
  virtual void Update();
  virtual void Init(int maxAnimals, int rowsCount, int columnsCount);
private:
  
  int maxAnimals;
  int rowsCount;
  int columnsCount;
  
  AnimalTray *tray;
  vector<Animal> selectedAnimals;
};



#endif
