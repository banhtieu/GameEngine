//
//  BTApplication.h
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef GameEngine_BTApplication_h
#define GameEngine_BTApplication_h


class MediaPlayerManager;
class TouchScreenBase;
class Application:public Singleton<Application>
{
public:
  Application();
  virtual ~Application();
  virtual void Init();
  virtual void Render();
  virtual void Update();
  virtual void Free();
  virtual void SwitchState(State *newState);
  long GetCurrentTime();// milisecond
protected:
  State *currentState;
public:
  TouchScreenBase*		m_touchScreen;
  MediaPlayerManager* mediaPlayer;
  
  int curLanguage; //en:0 vn:1
  bool isSoundOn;
};

#endif
