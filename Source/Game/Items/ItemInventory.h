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
#define ITEM_COUNT 18
class ItemInventory
{
    
public:
    ItemInventory();
    ~ItemInventory();
public:
    void LoadInventory();
    void SaveInventory();
    void PaintInventory(int startId, int endId);
public:
    ItemInstance *itemList[ITEM_COUNT];
};
#endif
