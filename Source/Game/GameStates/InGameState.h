//
//  InGameState.h
//  AnimoGame
//
//  Created by Tran Khiem on 3/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_InGameState_h
#define AnimoGame_InGameState_h

#include "Engine.h"
#include <vector>

using namespace std;

/**
 * The In Game State 
 **/
class InGameState: public State, public Singleton<InGameState>
{
public:
  void Init();
  void Update();
  void Render(Graphics2D *g);
  void Free();
 
};

#endif
