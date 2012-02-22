//
//  Shader.fsh
//  GameEngine
//
//  Created by Tran Khiem on 2/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
