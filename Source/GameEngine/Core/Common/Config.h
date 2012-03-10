//
//  Header.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Config_Header_h
#define Config_Header_h

#include <stdio.h>

// The Global Configurations are here.

#define SCREEN_W 960
#define SCREEN_H 640
#define SCREEN_WD2 (SCREEN_W >> 1)
#define SCREEN_HD2 (SCREEN_H >> 1)

#define LIMIT_FPS 60

#define LOGI(...) printf(__VA_ARGS__); printf("\n")
#define LOGE(...) printf(__VA_ARGS__); printf("\n")
#define SAFE_DEL(p) if(p) delete p; p = 0;
#define SAFE_DEL_ARRAY(p) if(p) delete []p; p = 0;

#endif
