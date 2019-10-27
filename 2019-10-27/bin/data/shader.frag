#ifdef GL_ES
precision mediump float;
#endif
#define PI 3.14159265359

uniform vec2 resolution;
uniform float time;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

float rand(float v){
    return fract(sin(v));
}

mat2 rotate2d(float _angle){
    return mat2(cos(_angle),-sin(_angle),
                sin(_angle),cos(_angle));
}

void main(){
	vec2 st = gl_FragCoord.xy/resolution;
  float pct = 0.0;
	
  pct = step(rand(.1),distance(st,vec2(rand(st*rand(time))))) ;
  vec3 color = vec3(pct);

	gl_FragColor = vec4( color, 1.0 );
}

