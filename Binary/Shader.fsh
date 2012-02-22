//
//  Shader.fsh
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

varying lowp vec4 colorVarying;
varying lowp vec2 texcoordVarying;

uniform bool useColor;
uniform bool useTexture;
uniform sampler2D texture;
uniform lowp float alphaBlender;

void main()
{
  lowp vec4 result = vec4(0.0, 0.0, 0.0, 0.0);
  
  result = texture2D(texture, texcoordVarying);
//  result = vec4(1.0, 0.0, 0.0, 1.0);
  
  gl_FragColor = result;
}
