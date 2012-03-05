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
struct ItemAbility
{
  int strengh;  // %suc manh
  int lucky;    // %may man
  int accurate; // %do chinh xác
};
// Class ItemInstance
class ItemInstance
{
public:
  static Sprite *spriteItems;
    
  ItemInstance();
  ~ItemInstance();
  
  void SetId(int price);
  void SetPosition(int x, int y);
  void SetPrice(int price);
  void SetObjectiveUnlock(char *objtive);
  void SetCapability(char *capability); 
  void SetIsUnlock(bool unlock);
  void SetIsBought(bool bought); 
  void SetIsSelecting(bool select);
  
  int GetPrice();
  char* GetObjectiveUnlock();
  char* GetCapability();
  bool IsUnlock();
  bool IsBought();
  bool IsSelecting();
  
  void Paint();
    
public:
  int itemId;
  int itemPrice;
  int posX;
  int posY;
  bool isUnlocked;
  bool isBought;
  bool isSelecting;
  char* objectiveUnlock;
  char* capability;
  
  ItemAbility itemAbility;
};

#endif
