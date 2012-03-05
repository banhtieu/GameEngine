//
//  CashShopState.cpp
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "CashShopState.h"

void CashShopState::Init()
{
  cashPackList[0].price = 0.99;
  cashPackList[0].cash = 1000;
  
  cashPackList[1].price = 1.99;
  cashPackList[1].cash = 2000;
  
  cashPackList[2].price = 4.99;
  cashPackList[2].cash = 5000;
  
  cashPackList[3].price = 9.99;
  cashPackList[3].cash = 10000;
  
  cashPackList[4].price = 24.99;
  cashPackList[4].cash = 25000;
  
  cashPackList[5].price = 49.99;
  cashPackList[5].cash = 50000;
}

void CashShopState::Render(Graphics2D *g)
{
  
}

void CashShopState::Update()
{
  
}