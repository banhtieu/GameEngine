//
//  Rect2D.h
//  GameEngine
//
//  Created by Quang Phan on 01/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Rect2D_h
#define GameEngine_Rect2D_h
#include "Point2D.h"

class Rect2D
{
public:
    
    //CTOR-DTOR
    ////////////////////////////
    Rect2D() : UpperLeftCorner(0,0), LowerRightCorner(0,0) {}
    
    Rect2D(T x, T y, T x2, T y2)
    : UpperLeftCorner(x,y), LowerRightCorner(x2,y2) {}
    
    
    //Operator
    ////////////////////////////
    Rect2D<T> operator+(const Point2D<T>& pos) const
    {
        Rect2D<T> ret(*this);
        return ret+=pos;
    }
    
    Rect2D<T>& operator+=(const Point2D<T>& pos)
    {
        UpperLeftCorner += pos;
        LowerRightCorner += pos;
        return *this;
    }
    
    //Method
    ////////////////////////////
    bool isPointInside(const Point2D<T>& pos) const
    {
        return (UpperLeftCorner.X <= pos.X &&
				UpperLeftCorner.Y <= pos.Y &&
				LowerRightCorner.X >= pos.X &&
				LowerRightCorner.Y >= pos.Y);
    }
    Point2D<T> UpperLeftCorner;
    Point2D<T> LowerRightCorner;
};

#endif
