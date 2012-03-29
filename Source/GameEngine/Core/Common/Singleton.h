//
//  BTSingleton.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_BTSingleton_h
#define GameEngine_BTSingleton_h


// The Singleton Template For The Game ENgine.
template <class T>
class Singleton
{
public:
  // The static Getter.
  static T* GetInstance();
  static void FreeInstance();
protected:
  // The Instance;
  static T *instance;
  
  // Protected Constructor...
  Singleton();

  // The destroyer.
  virtual ~Singleton();
};
  
// The Instaniater.
template <class T>
Singleton<T>::Singleton()
{
  instance = (T* ) this;
}

// The destroyer..
template <class T>
Singleton<T>::~Singleton()
{
  instance = 0;
}

template <class T>
void Singleton<T>::FreeInstance()
{
  delete instance;
  instance = NULL;
}

// The static getter for Singleton Pattern.
template <class T>
T* Singleton<T>::GetInstance()
{
  return instance;
}

// The static linkage.
template <class T>
T* Singleton<T>::instance;


#endif
