//
//  InGameState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "InGameState.h"
#include "logo.h"
#include <Box2D/Box2D.h>

// Init The GameState
void InGameState::Init()
{
  sprite = new Sprite("logo");
  mainActor = new Actor(sprite, F_BIKE, 4);
  mainActor->SetPosition(0, 0);
  mainActor->SetFlippedY(true);
  
// Init 
  CreateWorld();
}


// 
void InGameState::Update()
{
  world->Step(1.0f/30.0f, 60, 20);
}

// Render the InGame State
void InGameState::Render(Graphics2D *g)
{
  
  g->Save();
  g->ConcatTrasform(Matrix33::TranslateMatrix(SCREEN_WD2, SCREEN_HD2 + 200) * Matrix33::ScaleMatrix(1.0f, -1.0f));
  
  mainActor->Paint();
  for (b2Body *body = world->GetBodyList(); body; body = body->GetNext())
  {
    for (b2Fixture *fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
    {
      g->Save();
      b2Vec2 position = body->GetPosition();
      g->ConcatTrasform(Matrix33::TranslateMatrix(position.x, position.y));
      g->ConcatTrasform(Matrix33::RotateMatrix(body->GetAngle() * 180 / M_PI));
      b2PolygonShape *shape = (b2PolygonShape *) fixture->GetShape();
      b2Vec2 pos = shape->GetVertex(0);
      for (int i = 1; i < shape->GetVertexCount() + 1; i++)
      {
        b2Vec2 nextPos = shape->GetVertex(i % shape->GetVertexCount());
        g->DrawLine(pos.x, pos.y, nextPos.x, nextPos.y);
        pos = nextPos;
      }
      g->Restore();
    }
  }
  g->Restore();
  TouchList *touches = TouchManager::GetInstance()->GetTouches();
  
  g->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
  if (touches)
  {
    for (TouchList::iterator item = touches->begin(); item != touches->end(); item++)
    {
      g->FillCircle((*item)->GetX(), (*item)->GetY(), 150);
    }
  }
}

// Free The In Game 
void InGameState::Free()
{
  SAFE_DEL(mainActor);
  SAFE_DEL(sprite);
}

// Create An World 
void InGameState::CreateWorld()
{
  world = new b2World(b2Vec2(0.0f, -300.0f));
  
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -50.0f);
  
  b2Body *groundBody = world->CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  
  groundBox.SetAsBox(300.0f, 50.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  
  b2BodyDef dynamicBodyDef;
  dynamicBodyDef.type = b2_dynamicBody;
  dynamicBodyDef.position.Set(0.0f, 500.0f);
  b2Body *dynamicBody = world->CreateBody(&dynamicBodyDef);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(50.0f, 50.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.density = 100.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.shape = &dynamicBox;
  dynamicBody->CreateFixture(&fixtureDef);
  
  dynamicBodyDef.position.Set(60.0f, 100.0f);
  dynamicBody = world->CreateBody(&dynamicBodyDef);
  fixtureDef.density = 10.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.shape = &dynamicBox;
  dynamicBody->CreateFixture(&fixtureDef);
}

void InGameState::AddGround()
{
  
}