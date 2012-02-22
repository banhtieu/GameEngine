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

#define LOGI(...) printf(__VA_ARGS__)
#define LOGE(...) printf(__VA_ARGS__)

#include "Singleton.h"

#endif