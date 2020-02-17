#ifdef GL_ES
precision mediump float;
#endif
uniform vec2  resolution;
uniform vec2  mouse;
uniform float time;

float rand(float v){
    return fract(sin(v));
}

void main(){
    vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
	 float pct = smoothstep(.1, .9,distance(p,vec2(.1))) ;
        vec3 col = vec3(pct);

    vec3 line = vec3(0.0);
    for(float i = 0.0; i < 100.0; ++i){;
      float timer = time * 0.01;
	    float motion =  exp(.9 * sin(time) /exp(.9));
	    vec3 color = vec3(.1);
      line += 0.005 / abs(  mod(.8,p.y) + sin( 5.*p.x +(pow(2.,5.))) * rand(8. * motion) )  * color;
    }
    gl_FragColor = vec4(line, 1.0);
}
