//
//  Point2D.h
//  GameEngine
//
//  Created by Quang Phan on 01/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Point2D_h
#define GameEngine_Point2D_h

#include <cmath>




// ** Macros
// ////////////////////////////////////////////////////////////////////////////////////////////
#define EXPAND_VEC2(v)	(v).x, (v).y



// ** Main Class
// ////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class Point2D
{
    // ** Members
    // ////////////////////////////////////////////////////////
public:
	union
	{
		struct {T x, y;};
		T v[2];
	};
    
    
    // ** Ctors / Dtor
    // ////////////////////////////////////////////////////////
public:
    Point2D()						: x(0), y(0)    {};
	Point2D(T _x, T _y)				: x(_x), y(_y)	{};
    virtual	~Point2D()  {};
    
    // ** Operators
    // ////////////////////////////////////////////////////////
public:
	Point2D<T>&		operator =(const Point2D<T>& ref)			{x=ref.x; y=ref.y; return *this;};
	Point2D<T>&		operator +=(const Point2D<T>& ref)			{x+=ref.x; y+=ref.y; return *this;};
	Point2D<T>&		operator -=(const Point2D<T>& ref)			{x-=ref.x; y-=ref.y; return *this;};
	Point2D<T>&		operator *=(const T& s)						{x*=s; y*=s; return *this;};
	Point2D<T>&		operator /=(const T& s)						{x/=s; y/=s; return *this;};
    
	Point2D<T>		operator +(const Point2D<T>& ref)	const	{return Point2D<T>(x+ref.x, y+ref.y);};
	Point2D<T>		operator -(const Point2D<T>& ref)	const	{return Point2D<T>(x-ref.x, y-ref.y);};
	T				operator *(const Point2D<T>& ref)	const	{return x*ref.x + y*ref.y;};
};
    
typedef Point2D<float>	Vec2f;
typedef Point2D<int>	Vec2i;
#endif
