//
//  ItemInventory.h
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_ItemInventory_h
#define GameEngine_ItemInventory_h

#include "ItemInstance.h"

#define ITEM_COUNT 24

class ItemInventory
{
    
public:
    ItemInventory();
    ~ItemInventory();
public:
    void LoadInventory(const char *filename);
    void SaveInventory(const char *filename);
    void PaintInventory(int shopId, int startId = 0, int endId = 0);
public:
    ItemInstance *itemList[ITEM_COUNT];
};
#endif
