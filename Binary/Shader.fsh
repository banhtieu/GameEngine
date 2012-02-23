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
uniform highp vec4 colorUniform;

void main()
{
  lowp vec4 result = colorVarying;
  
  if (useColor)
  {
    result = result + colorUniform;
  }
  
  result = texture2D(texture, texcoordVarying);
  result.a = alphaBlender * result.a;
  
  gl_FragColor = result;
}
