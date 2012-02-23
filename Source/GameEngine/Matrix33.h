//
//  Matrix.h
//  GameEngine
//
//  Created by Tran Khiem on 2/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_Matrix_h
#define GameEngine_Matrix_h

// The Points.
struct Point2
{
  float x, y;
};

// Typedef Union Matrix
typedef union
{
  float m[3][3];
  struct{
    float a1, b1, c1;
    float a2, b2, c2;
    float a3, b3, c3;
  } a;
} MatrixValue33;

// Class Matrix 33
class Matrix33
{
public:
  MatrixValue33 value;
  Matrix33();
  Matrix33(float a1, float a2, float b1, float b2);
  Matrix33(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3);
  static Matrix33 TranslateMatrix(float dx, float dy);
  static Matrix33 ScaleMatrix(float sx, float sy);
  static Matrix33 ScaleMatrix(float sx, float x, float y);
  static Matrix33 RotateMatrix(float alpha);
  static Matrix33 RotateMatrix(float alpha, float x, float y);
  Matrix33 operator*(const Matrix33 &matrix);
};

#endif
