//
//  Matrix33.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"
#include <math.h>

// Matrix Creator
Matrix33::Matrix33()
{
  value.a.a1 = 1.0f;
  value.a.a2 = 0.0f;
  value.a.a3 = 0.0f;
  value.a.b1 = 0.0f;
  value.a.b2 = 1.0f;
  value.a.b3 = 0.0f;
  value.a.c1 = 0.0f;
  value.a.c2 = 0.0f;
  value.a.c3 = 1.0f;
}


// Matrix Creator
Matrix33::Matrix33(float a1, float a2, float b1, float b2)
{
  value.a.a1 = a1;
  value.a.a2 = a2;
  value.a.a3 = 0.0f;
  value.a.b1 = b1;
  value.a.b2 = b2;
  value.a.b3 = 0.0f;
  value.a.c1 = 0.0f;
  value.a.c2 = 0.0f;
  value.a.c3 = 1.0f;
}

// Init a Matrix
Matrix33::Matrix33(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
  value.a.a1 = a1;
  value.a.a2 = a2;
  value.a.a3 = a3;
  value.a.b1 = b1;
  value.a.b2 = b2;
  value.a.b3 = b3;
  value.a.c1 = c1;
  value.a.c2 = c2;
  value.a.c3 = c3;
}

// Return a Translate Matrix
Matrix33 Matrix33::TranslateMatrix(float dx, float dy)
{
  return Matrix33(1.0f, 0.0f, dx, 0.0f, 1.0f, dy, 0.0f, 0.0f, 1.0f);
}

// Return a ScaleMatrix
Matrix33 Matrix33::ScaleMatrix(float sx, float sy)
{
  return Matrix33(sx, 0.0f, 0.0f, sy);
}

// Return a ScaleMatrix
Matrix33 Matrix33::ScaleMatrix(float sx, float x, float y)
{
  return TranslateMatrix(x, y) * ScaleMatrix(sx, sx) * TranslateMatrix(-x, -y);
}

// Return a Rotate Matrix
Matrix33 Matrix33::RotateMatrix(float alpha, float x, float y)
{
  return TranslateMatrix(x, y) * RotateMatrix(alpha) * TranslateMatrix(-x, -y);
}

// Return a Rotate Matrix
Matrix33 Matrix33::RotateMatrix(float alpha)
{
  alpha *= (float) M_PI / 180.0f;
  return Matrix33(cos(alpha), -sin(alpha), sin(alpha), cos(alpha));
}

// Multiple two matrix.
Matrix33 Matrix33::operator*(const Matrix33 &matrix)
{
  return Matrix33(
    value.a.a1 * matrix.value.a.a1 + value.a.a2 * matrix.value.a.b1 + value.a.a3 * matrix.value.a.c1,
    value.a.a1 * matrix.value.a.a2 + value.a.a2 * matrix.value.a.b2 + value.a.a3 * matrix.value.a.c2,
    value.a.a1 * matrix.value.a.a3 + value.a.a2 * matrix.value.a.b3 + value.a.a3 * matrix.value.a.c3,
    value.a.b1 * matrix.value.a.a1 + value.a.b2 * matrix.value.a.b1 + value.a.b3 * matrix.value.a.c1,
    value.a.b1 * matrix.value.a.a2 + value.a.b2 * matrix.value.a.b2 + value.a.b3 * matrix.value.a.c2,
    value.a.b1 * matrix.value.a.a3 + value.a.b2 * matrix.value.a.b3 + value.a.b3 * matrix.value.a.c3,                  
    value.a.c1 * matrix.value.a.a1 + value.a.c2 * matrix.value.a.b1 + value.a.c3 * matrix.value.a.c1,
    value.a.c1 * matrix.value.a.a2 + value.a.c2 * matrix.value.a.b2 + value.a.c3 * matrix.value.a.c2,
    value.a.c1 * matrix.value.a.a3 + value.a.c2 * matrix.value.a.b3 + value.a.c3 * matrix.value.a.c3                   
  );
}
