//
//  BTViewController.m
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#import "ViewController.h"

#import "MyGame.h"
#import "IOSDevice.h"
#import "TouchManager.h"

@interface ViewController () 

@property (strong, nonatomic) EAGLContext *context;

- (void)setupGL;
- (void)tearDownGL;

@end

@implementation ViewController

@synthesize context = _context;

Application *application;
Device *device;
FileSystem *fileSystem;

- (void)dealloc
{
  [_context release];
  [super dealloc];
  
  delete application;
  delete device;
  delete fileSystem;
  
}

- (void)viewDidLoad
{
  [super viewDidLoad];
  [self.view setMultipleTouchEnabled:YES];
  self.context = [[[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2] autorelease];

  if (!self.context) {
      NSLog(@"Failed to create ES context");
  }
  
  GLKView *view = (GLKView *)self.view;
  view.context = self.context;
  view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
  
  [self setupGL];
  
}

- (void)viewDidUnload
{    
  [super viewDidUnload];
  
  [self tearDownGL];
  
  if ([EAGLContext currentContext] == self.context) {
      [EAGLContext setCurrentContext:nil];
  }
  self.context = nil;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc. that aren't in use.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation == UIInterfaceOrientationLandscapeLeft);
    } else {
        return YES;
    }
}

// Handles the start of a touch
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
  TouchManager *touchManager = TouchManager::GetInstance();
  NSLog(@"Number of Touches: %d", [touches count]);
  for (UITouch *touch in touches)
  {
    CGPoint location = [touch locationInView:self.view];
    int type = TOUCH_NONE;
    if ([touch phase] == UITouchPhaseBegan)
    {
      type = TOUCH_DOWN;
    }
    else if ([touch phase] == UITouchPhaseEnded)
    {
      type = TOUCH_UP;
    }
    else if ([touch phase] == UITouchPhaseMoved)
    {
      type = TOUCH_MOVE;
    }
    else if ([touch phase] == UITouchPhaseCancelled)
    {
        type = TOUCH_CANCELLED;
    }
    
    NSLog(@"id & type: %ld - %d", (long) touch, type);
    
    touchManager->AddTouch((long) touch, location.x * 2, location.y * 2, type);
  }
    
}

// Handles the continuation of a touch.
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
  [self touchesBegan:touches withEvent:event];
}

// Handles the end of a touch event when the touch is a tap.
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
  [self touchesBegan:touches withEvent:event];  
}

// Handles the end of a touch event.
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
  [self touchesBegan:touches withEvent:event];
}

- (void)setupGL
{
  [EAGLContext setCurrentContext:self.context];
//  glEnable(GL_DEPTH_TEST);
  
  // Init File System.
  NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
  NSString *documentsDirectory = [paths objectAtIndex:0];
  
  fileSystem = new FileSystem([documentsDirectory UTF8String], [[[NSBundle mainBundle] bundlePath] UTF8String]);  
  
  // Init Device...
  device = new IOSDevice();
  device->Init();
  
  // Init Application...
  application = new MyGame();
  application->Init();

    // Set Up GL Here.
}

- (void)tearDownGL
{
  [EAGLContext setCurrentContext:self.context];
  application->Free();
  device->Free();  
}

#pragma mark - GLKView and GLKViewController delegate methods

- (void) update
{
  
  application->Update();
  TouchManager::GetInstance()->Update();

  //glClearColor(0.00f, 0.00f, 0.00f, 1.0f);
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //application->Render();

}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    // Render Here..
}

@end
