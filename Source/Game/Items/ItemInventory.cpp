//
//  ItemInventory.cpp
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ItemInventory.h"

ItemInventory::ItemInventory()
{
    
}

void ItemInventory::LoadInventory()
{
    
}

void ItemInventory::SaveInventory()
{
    
}

void ItemInventory::PaintInventory(int startID, int endId)
{
  for (int i = startID; i < endId; i++)
  {
    itemList[i]->Paint();
  }
}