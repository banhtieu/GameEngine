//
//  ShopState.cpp
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ItemShopState.h"

void ItemShopState::Init()
{
  itemInv = new ItemInventory();
  itemInv->LoadInventory("");
}

void ItemShopState::Render(Graphics2D *g)
{
  itemInv->PaintInventory(shopId);
};

void ItemShopState::Update()
{
  
}