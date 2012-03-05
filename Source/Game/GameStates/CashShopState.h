//
//  CashShopState.h
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_CashShopState_h
#define GameEngine_CashShopState_h
#include "Engine.h"

struct CashPack
{
  float price;
  int cash;
};

class CashShopState: public State, Singleton<CashShopState>
{
public:
  CashPack cashPackList[6];

public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  
};
#endif
