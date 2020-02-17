#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

void main(){
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.0);
    vec2 pos = vec2(0.5,0.5)-st;

    float a = atan(pos.y,pos.x)*.4;

    float  pct = 0.0;
    vec3 color1 = vec3(distance(st,vec2(.5)));

    float f = smoothstep(-1.,.1, sin(a*pow(10.,4.)));
    color = vec3(1.-sin(f))- color1;
    gl_FragColor = vec4(color, 1.0);
}

