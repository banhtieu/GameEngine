//
//  Shader.vsh
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

attribute vec2 position;
attribute vec2 texcoord;

varying highp vec2 texcoordVarying;
uniform mat3 matrix;

void main()
{   
  vec3 pos = matrix * vec3(position, 1.0);
  gl_Position = vec4(pos.xy, 0.0, 1.0);
  texcoordVarying = texcoord;
}
