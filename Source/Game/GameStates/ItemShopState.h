//
//  ShopState.h
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_ItemShopState_h
#define GameEngine_ItemShopState_h
#include "ItemInventory.h"

#include "Engine.h"

enum ShopType {
  SHOP_SUPPORT,// hổ trợ
  SHOP_TEAT,   // núm vú
  SHOP_DIAPER, // tả lót
  SHOP_WEAPON  // vũ khí
};


class ItemShopState: public State, Singleton<ItemShopState>
{
public:
  ItemInventory *itemInv;
  int shopId;
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
protected:
};

#endif
