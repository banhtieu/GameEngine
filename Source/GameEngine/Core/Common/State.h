//
//  State.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_State_h
#define GameEngine_State_h

// The game state 
class State
{
public:
  virtual void Init(){};
  virtual void Update(){};
  virtual void Render(Graphics2D *g){};
  virtual void Free(){};
};

#endif
