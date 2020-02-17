// #ifdef GL_ES
// precision mediump float;
// #endif

// uniform vec2 resolution;
// uniform float time;
// varying vec4 globalColor;

// [> void main(){ <]
	// // vec2 st = gl_FragCoord.xy/resolution;
  // // float pct = 0.0;
  // // pct = step(cos(time*1.4),distance(st,vec2(1))) -
      // // step(cos(time*1.4),distance(st,vec2(0))*.6) +
      // // step(cos(time*1.4),distance(st,vec2(0,1))*.3);
  // // vec3 color = vec3(pct);

	// // gl_FragColor = vec4( color, 1.0 );
// [> } <]

// #version 120

// varying vec4 globalColor;

// void main()
// {
    // // globalColor is being set inside the vertex shader.
    // // the fragment color is then set to the globalColor.

    // gl_FragColor = globalColor;
// }




#version 150
precision mediump float;

uniform sampler2DRect tex0;

in vec4 gsColor;
in vec2 gsTexCoord;

out vec4 outputColor;

void main(){
    // vec4 smpColor = texture(tex0, gsTexCoord);
    outputColor = gsColor * smpColor;
}
