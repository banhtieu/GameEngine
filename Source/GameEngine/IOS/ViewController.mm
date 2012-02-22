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
#import "FileSystem.h"

using namespace bt;

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

- (void)update
{
  application->Update();
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
  glClearColor(0.00f, 0.00f, 0.00f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  application->Render();
  // Render Here..
}

@end
