//
//  ItemInstance.h
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_ItemInstance_h
#define GameEngine_ItemInstance_h
#include "Engine.h"

// Item Type
enum ItemType {
    ITEM_SUPPORT,// hổ trợ
    ITEM_TEAT,   // núm vú
    ITEM_DIAPER, // tả lót
    ITEM_WEAPON  // vũ khí
};

// Class ItemInstance
class ItemInstance
{
public:
    static Sprite *spriteItems;
    
    ItemInstance(int type);
    ~ItemInstance();
    void SetPosition(int x, int y);
    void Price(int price);
    void Paint();
    
public:
    int itemId;
    int itemPrice;
    int posX;
    int posY;
    bool isUnlocked;
    bool isBought;
    char* objectiveUnlock;
    char* capability;
};

#endif
