//
//  Shader.vsh
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

attribute vec2 position;
attribute vec4 color;
attribute vec2 texcoord;

varying lowp vec4 colorVarying;
varying lowp vec2 texcoordVarying;

void main()
{    
    gl_Position = vec4(position, 0.0, 1.0);
    colorVarying = color;
    texcoordVarying = texcoord;
}
