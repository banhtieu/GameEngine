//
//  InGameState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 3/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "InGameState.h"
#include "logo.h"
#include "ExportedStrings.h"
#include "BackgroundData.h"
#include <Box2D/Box2D.h>

// Init The GameState
void InGameState::Init()
{
  sprite = new Sprite("logo");
  background = Texture::LoadTexturePNG("background.png");
  mainActor = new Actor(sprite, F_BIKE, 4);
  mainActor->SetPosition(0, 0);
  mainActor->SetFlippedY(true);
  mainActor->SetFlippedX(false);
  
  stringManager = new StringManager();
  stringManager->Load("strings.vi.bin");
  stringManager->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
// Init 
  CreateWorld();

  
  //read XML
  char filepath[256];
  sprintf(filepath,"%s/ak.xml",FileSystem::GetInstance()->resourcePath);
  TiXmlDocument* doc= new TiXmlDocument(filepath);
  bool xxx = doc->LoadFile();
  TiXmlElement* root = doc->FirstChildElement( "ITEM_EN" );
  TiXmlElement* child = root->FirstChildElement("SUPPORT");
  const char* gg = new char[24];
  gg= child->GetText();// gg="Hehe"
  // end read XML
}


// 
void InGameState::Update()
{
  world->Step(1.0f/20.0f, 60, 20);
  
  if (TouchManager::GetInstance()->IsTouchInRect(SCREEN_WD2, 0, SCREEN_WD2, SCREEN_H))
  {
    bicycle->ApplyForce(b2Vec2(1000.0f, 0.0f), bicycle->GetWorldCenter());
  }
  else if (TouchManager::GetInstance()->IsTouchInRect(0, 0, SCREEN_WD2, SCREEN_H))
  {
    bicycle->ApplyForce(b2Vec2(-1000.0f, 0.0f), bicycle->GetWorldCenter());
  }
}

// Render the InGame State
void InGameState::Render(Graphics2D *g)
{
  // Draw Background
  for (int i = 0; i < SCREEN_W; i+= bgFrameData[CLOUD1].w * 2)
  {
    g->DrawTexture(background, i, 0, bgFrameData[CLOUD1]);
    g->DrawTexture(background, i + bgFrameData[CLOUD1].w, 0, bgFrameData[CLOUD2]);
  }
  
  for (int i = -bicycle->GetPosition().x * 3 - 500; i < SCREEN_W; i+= bgFrameData[BG1].w + bgFrameData[BG2].w)
  {
    g->DrawTexture(background, i, 20, bgFrameData[BG1]);
    g->DrawTexture(background, i + bgFrameData[BG1].w, 0, bgFrameData[BG2]);
  }
  
  for (int i = -bicycle->GetPosition().x * 9 - 500; i < SCREEN_W; i+= bgFrameData[FRONT1].w + bgFrameData[FRONT2].w)
  {
    g->DrawTexture(background, i, 40, bgFrameData[FRONT1]);
    g->DrawTexture(background, i + bgFrameData[FRONT1].w, 0, bgFrameData[FRONT2]);
  }
  
  stringManager->Draw(STR_INGAME_INTRO, 10, 10);
  g->Save();
  g->ConcatTrasform(Matrix33::TranslateMatrix(SCREEN_WD2 - bicycle->GetPosition().x * 10, SCREEN_HD2 + 200) * Matrix33::ScaleMatrix(1.0f, -1.0f));
  

  g->Save();
  g->ConcatTrasform(Matrix33::TranslateMatrix(bicycle->GetPosition().x * 10, bicycle->GetPosition().y * 10));
  
  g->ConcatTrasform(Matrix33::RotateMatrix(bicycle->GetAngle() * 180 / M_PI));

  mainActor->Paint();
  g->Restore();
  g->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
  for (b2Body *body = world->GetBodyList(); body; body = body->GetNext())
  {
    for (b2Fixture *fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
    {
      if (body == bicycle)
      {
        continue;
      }
      
      g->Save();      
      b2Vec2 position = body->GetPosition();
      g->ConcatTrasform(Matrix33::ScaleMatrix(10.0f, 10.0f));      
      g->ConcatTrasform(Matrix33::TranslateMatrix(position.x, position.y));
      g->ConcatTrasform(Matrix33::RotateMatrix(body->GetAngle() * 180 / M_PI));
      b2Shape *shape = fixture->GetShape();
      if (shape->GetType() == b2Shape::e_polygon)
      {
        b2PolygonShape *polygon = (b2PolygonShape *)shape;
        b2Vec2 pos = polygon->GetVertex(0);
        for (int i = 1; i < polygon->GetVertexCount() + 1; i++)
        {
          b2Vec2 nextPos = polygon->GetVertex(i % polygon->GetVertexCount());
          g->DrawLine(pos.x, pos.y, nextPos.x, nextPos.y);
          pos = nextPos;
        }
      }
      else if (shape->GetType() == b2Shape::e_circle)
      {
        b2CircleShape *circle = (b2CircleShape *) shape;
        g->DrawCirle(circle->m_p.x, circle->m_p.y, circle->m_radius);
      }
      
      g->Restore();
    }
  }
  g->Restore();

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
  world = new b2World(b2Vec2(0.0f, -10.0f));
  
  AddGround(-35.0f, 5.0f, -30.0f);  
  AddGround(0.0f, -3.0f, 10.0f);
  AddGround(40.0f, 1.0f, 10.0f);
  AddGround(70.0f, 5.0f, 30.0f);
  AddGround(100.0f, 8.0f, 10.0f);
  AddGround(140.0f, 13.0f, 10.0f);
  AddGround(180.0f, 18.0f, 10.0f);
  AddGround(200.0f, 40.0f, 90.0f);
  
  AddBicycle();
  
}

void InGameState::AddBicycle()
{
  b2BodyDef dynamicBodyDef;
  b2FixtureDef fixtureDef;
  
  // wheel 1.
  dynamicBodyDef.type = b2_dynamicBody;
  dynamicBodyDef.position.Set(3.0f, 2.0f);
  wheel1 = world->CreateBody(&dynamicBodyDef);
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  b2CircleShape circleShape;
  circleShape.m_radius = 2.0f;
  fixtureDef.shape = &circleShape;
  wheel1->CreateFixture(&fixtureDef);
  
  // wheel 2
  dynamicBodyDef.position.Set(-3.0f, 2.0f);
  wheel2 = world->CreateBody(&dynamicBodyDef);  
  wheel2->CreateFixture(&fixtureDef);
  
  dynamicBodyDef.position.Set(0.0f, 5.0f);
  bicycle = world->CreateBody(&dynamicBodyDef);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(5.0f, 4.0f);
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.shape = &dynamicBox;
  bicycle->CreateFixture(&fixtureDef);
  
  b2RevoluteJointDef joinDef;
  joinDef.Initialize(wheel1, bicycle, wheel1->GetWorldCenter());
  joinDef.enableMotor = true;
  
  world->CreateJoint(&joinDef);
  
  joinDef.Initialize(wheel2, bicycle, wheel2->GetWorldCenter());
  joinDef.enableMotor = true;
  
  world->CreateJoint(&joinDef);
  
}

void InGameState::AddGround(float x, float y, float alpha)
{
  b2BodyDef groundBodyDef;
//  groundBodyDef.position.Set(x, y);
  
  b2Body *groundBody = world->CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  groundBody->SetTransform(b2Vec2(x, y), alpha * M_PI / 180.0f);
  groundBox.SetAsBox(20.0f, 2.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
}