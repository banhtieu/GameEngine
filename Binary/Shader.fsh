//
//  Shader.fsh
//  GameEngine
//
//  Created by Tran Khiem on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

varying highp vec2 texcoordVarying;

uniform bool useColor;
uniform bool useTexture;
uniform sampler2D texture;
uniform highp float alphaBlender;
uniform highp vec4 colorUniform;

void main()
{
  lowp vec4 result = vec4(0.0, 0.0, 0.0, 0.0);
  
  if (useColor)
  {
    result = result + colorUniform;
  }
  
  result = result + texture2D(texture, texcoordVarying);
  result.a = alphaBlender * result.a;
  
  gl_FragColor = result;
}
