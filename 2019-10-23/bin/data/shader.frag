#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

void main(){
	vec2 st = gl_FragCoord.xy/u_resolution;
  float pct = 0.0;
  pct = step(cos(u_time*1.4),distance(st,vec2(1))) -
      step(cos(u_time*1.4),distance(st,vec2(0))*.6) +
      step(cos(u_time*1.4),distance(st,vec2(0,1))*.3);
  vec3 color = vec3(pct);

	gl_FragColor = vec4( color, 1.0 );
}

