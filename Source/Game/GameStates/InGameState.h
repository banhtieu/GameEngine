//
//  InGameState.h
//  AnimoGame
//
//  Created by Tran Khiem on 3/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_InGameState_h
#define AnimoGame_InGameState_h

#include "Engine.h"
#include <vector>

using namespace std;
#define LINES 5
#define ROWS 10

/**
 * Animal
 **/
class Animal
{
public:
  int x;
  int y;
  int animal;
  bool reveal;
  Animal():x(0), y(0), animal(0), reveal(false){};
  Animal(int animal_, int x_, int y_):animal(animal_), x(x_), y(y_) {};
};

/**
 * The In Game State 
 **/
class InGameState: public State, public Singleton<InGameState>
{
public:
  void Init();
  void Update();
  void Render(Graphics2D *g);
  void Free();
  void DrawAnimal(int animal, int x, int y, int isShadow = false);
  
  void InitLevel(int level);
  void RandomAnimal();
protected:
  Sprite *animalSprite;
  Sprite *shadowSprite;
  
  int gameSpeed;
  int gameTime;
  int rightest;
  
  vector<Animal> animals;
  Animal *selectedAnimal;
  
  int currentLevel;
  int currentSpeed;
  int maxAnimals;
  int currentOffset;
  Animal currentAnimals[LINES][ROWS];
  
  int oldX;
  int oldY;

};

#endif
