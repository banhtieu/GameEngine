//
//  ItemInstance.cpp
//  GameEngine
//
//  Created by Quang Phan on 05/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ItemInstance.h"

Sprite *ItemInstance::spriteItems = NULL;

ItemInstance::ItemInstance(int type)
{
    itemId = type;
    if(ItemInstance::spriteItems ==  NULL)
    {
        Texture *spriteTexture = Texture::LoadTexturePNG("itemList.png");
        ItemInstance::spriteItems = new Sprite("itemList");
    }
}

void ItemInstance::SetPosition(int x, int y)
{
    posX = x;
    posY = y;
}

void ItemInstance::Paint()
{
    Graphics2D *g = Graphics2D::GetInstance();
}