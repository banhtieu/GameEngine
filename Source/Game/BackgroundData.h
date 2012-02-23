//
//  BackgroundData.h
//  GameEngine
//
//  Created by Tran Khiem on 2/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_BackgroundData_h
#define GameEngine_BackgroundData_h

struct Frame
{
  int x, y, w, h;
};

enum 
{
  CLOUD1, CLOUD2, BG1, BG2, FRONT1, FRONT2, NUM_FRAMES
};

Frame frameData[NUM_FRAMES] = {
  776, 543, 495, 345,
  776, 911, 496, 345,
  0, 0, 2040, 543,
  0, 538, 721, 543,
  0, 1316, 2048, 690,
  1296, 543, 752, 734
};

#endif
