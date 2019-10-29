#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2  mouse;
uniform vec2  resolution;

const float PI = 3.14159265;
const float angle = 60.0;
float fov = angle * 0.5 * PI / 180.0;

vec3  cPos = vec3(2., 7., 4.);
const float sphereSize = .4;

vec3 boxTrans(vec3 p){
    return mod(p, 8.) - 4.;
}

vec3 ballTrans(vec3 p){
    return mod(p, 14.) - 7.;
}

float rand(float x)
{
    return fract(sin(x) * 10000.0);
}

float distanceFuncBox(vec3 p){
  vec3 q = abs(boxTrans(p) * rand(-.3) * mod(time, 7.) + 2.);
  return length(max(q- vec3(2., 1. , 1.), .0));
}

float distanceFuncBall(vec3 p){
  vec3 q = abs(ballTrans(p* mod(time, 3.)));
  return length(q) - sphereSize;
}

float distanceFunc(vec3 p) {
    float d1 = distanceFuncBall(p);
    float d2 = distanceFuncBox(p);
    return max(d1, -d2); 
}

vec3 getNormal(vec3 p){
    float d = 0.0001;
    return normalize(vec3(
        distanceFunc(p + vec3(  d, 0.0, 0.0)) - distanceFunc(p + vec3( -d, 0.0, 0.0)),
        distanceFunc(p + vec3(0.0,   d, 0.0)) - distanceFunc(p + vec3(0.0,  -d, 0.0)),
        distanceFunc(p + vec3(0.0, 0.0,   d)) - distanceFunc(p + vec3(0.0, 0.0,  -d))
    ));
}

void main(void){
    vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
    vec3 ray = normalize(vec3(sin(fov) * p.x, sin(fov) * p.y, -cos(fov)));	
    
    float distance = 0.0;
    float rLen = 0.0;
    vec3  rPos = cPos;
    for(int i = 0; i < 90; i++){	  
        distance = distanceFunc(rPos);
        rLen += distance;
        rPos = cPos + ray * rLen;
    }
	
    vec3 col = vec3(.9, .9, .2);
    if(abs(distance) < 0.001){
      vec3 normal = getNormal(rPos);	    
      col *=  col;
      gl_FragColor = vec4(col, 1.);
    }else{
      gl_FragColor = vec4(vec3(1.), 1.);
    }
}
