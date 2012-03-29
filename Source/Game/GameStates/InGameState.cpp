//
//  InGameState.cpp
//  AnimoGame
//
//  Created by Tran Khiem on 3/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "InGameState.h"
#include "Animals.h"

#define ANIMAL_WIDTH 120
#define MAX_ANIMALS 6
#define ANIMAL_Y SCREEN_H - ANIMAL_WIDTH / 2 - 10
#define CELL_WIDTH (ANIMAL_WIDTH + 10)
#define ROW_WIDTH (CELL_WIDTH * ROWS)
#define TOP_PADDING 200

/**
 * Init The In Game State
 **/
void InGameState::Init()
{
  animalSprite = new Sprite();
  animalSprite->LoadSprite("Animals");
  
  shadowSprite = new Sprite();
  shadowSprite->LoadSprite("AnimalShadows");
  
  animals.clear();
  srand(time(NULL));
  gameTime = 0;
  rightest = SCREEN_W + ANIMAL_WIDTH / 2;
  InitLevel(0);
  selectedAnimal = NULL;
  
}


/**
 * Update In Game State
 **/
void InGameState::Update()
{
  TouchManager *touchManager = TouchManager::GetInstance();
  if (!selectedAnimal)
  {
    if (touchManager->HasNewTouch())
    {
      for (int i = 0; i < animals.size(); i++)
      {
        // get touched animal;
        if (touchManager->IsTouchDownInRect(animals[i].x - ANIMAL_WIDTH / 2, animals[i].y - ANIMAL_WIDTH / 2, ANIMAL_WIDTH, ANIMAL_WIDTH))
        {
          selectedAnimal = new Animal(animals[i]);
          Touch *touch = touchManager->GetFirstTouch();
          if (touch)
          {
            oldX = touch->GetX();
            oldY = touch->GetY();
          }
          break;
        }
      }
    }
  }
  else
  {
    Touch *touch = touchManager->GetFirstTouch();
    if (touch)
    {
      selectedAnimal->x += touch->GetX() - oldX;
      selectedAnimal->y += touch->GetY() - oldY;
      oldX = touch->GetX();
      oldY = touch->GetY();
      
      LOGI("X:%d, Y:%d", selectedAnimal->x, selectedAnimal->y);
    }
    else 
    {
      selectedAnimal = NULL;
    }
  }
  
  currentOffset = (currentOffset + 2) % ROW_WIDTH;
  
  if (gameTime % 100 == 0)
  {
    RandomAnimal();
  }
  
  for (int i = 0; i < animals.size(); i++)
  {
    int limit = rightest;
    
    if (i > 0)
    {
      limit = animals[i - 1].x;
    }
    
    if (animals[i].x + ANIMAL_WIDTH + 5 < limit)
    {
      animals[i].x += 5;
    }
  }
  
  gameTime++;
}


/**
 * Update In Game State
 **/
void InGameState::Render(Graphics2D *g)
{
  for (int i = 0; i < LINES; i++)
  {
    int startX = - currentOffset;
    if (i & 0x1)
    {
      startX = - (ROW_WIDTH - currentOffset);
    }
    
    for (int j = 0; j < ROWS * 2; j++)
    {
      DrawAnimal(currentAnimals[i][j % LINES].animal, startX + CELL_WIDTH * j, TOP_PADDING + i * CELL_WIDTH, true);
    }
  }
  
  for (vector<Animal>::iterator i = animals.begin(); i < animals.end(); i++)
  {
    DrawAnimal((*i).animal, (*i).x, (*i).y);  
  }
  
  if (selectedAnimal)
  {
    DrawAnimal(selectedAnimal->animal, selectedAnimal->x, selectedAnimal->y);
  }

}


/**
 * Free In Game State
 **/
void InGameState::Free()
{
  SAFE_DEL(animalSprite);
}

/**
 * draw an animal
 **/
void InGameState::DrawAnimal(int animal, int x, int y, int isShadow)
{
  Graphics2D *g = Graphics2D::GetInstance();
  g->SetColor(Color(0xffff0000));
  g->DrawRectangle(x - ANIMAL_WIDTH / 2, y - ANIMAL_WIDTH / 2, ANIMAL_WIDTH, ANIMAL_WIDTH);
  if (isShadow)
  {
    shadowSprite->DrawModule(animal, x - shadowSprite->GetModuleWidth(animal) / 2, y - shadowSprite->GetModuleHeight(animal) / 2);
  }
  else 
  {
    animalSprite->DrawModule(animal, x - animalSprite->GetModuleWidth(animal) / 2, y - animalSprite->GetModuleHeight(animal) / 2);
  }
}

// Init a Level...
void InGameState::InitLevel(int level)
{
  currentLevel = level;
  currentOffset = 0;
  maxAnimals = 6;
  for (int i = 0; i < LINES; i++)
  {
    for (int j = 0; j < ROWS; j++)
    {
      currentAnimals[i][j].animal = rand() % maxAnimals;
      currentAnimals[i][j].reveal = false;
    }
  }
}

void InGameState::RandomAnimal()
{
  animals.push_back(Animal(rand() % maxAnimals, -ANIMAL_WIDTH, ANIMAL_Y));
}
