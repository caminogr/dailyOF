#ifdef GL_ES
precision mediump float;
#endif

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2  mouse;
uniform vec2  resolution;

const float PI = 3.14159265;
const float angle = 60.0;
float fov = angle * 0.5 * PI / 180.0;

vec3  cPos = vec3(0.0, 0.0, 2.0);
const float sphereSize = .5;
const vec3 lightDir = vec3(-0.477, 0.727, 0.477);

vec3 trans(vec3 p){
    return mod(p, 8.) - 4.;
}

float rand(float x)
{
    return fract(sin(x) * 10000.0);
}

float distanceFuncBox(vec3 p){
  vec3 q = abs(trans(p) * rand(2.));
  return length(max(q- vec3(mix(2., 1.,2.), 1. , 1.), .0));
}

float distanceFuncBall(vec3 p){
  return length(p) - sphereSize;
}

float distanceFunc(vec3 p) {
    float d1 = distanceFuncBall(p);
    float d2 = distanceFuncBox(p);
    return min(d1, d2);
}

vec3 getNormal(vec3 p){
    float d = 0.0001;
    return normalize(vec3(
        distanceFunc(p + vec3(  d, 0.0, 0.0)) - distanceFunc(p + vec3( -d, 0.0, 0.0)),
        distanceFunc(p + vec3(0.0,   d, 0.0)) - distanceFunc(p + vec3(0.0,  -d, 0.0)),
        distanceFunc(p + vec3(0.0, 0.0,   d)) - distanceFunc(p + vec3(0.0, 0.0,  -d))
    ));
}

mat2 rotate2d(float _angle){
    return mat2(cos(_angle),-sin(_angle),
                sin(_angle),cos(_angle));
}

void main(void){
    vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
    vec3 ray = normalize(vec3(sin(fov) * p.x, sin(fov) * p.y, -cos(fov)));	
    ray =  ray * exp(9. * sin(time)/exp(.9));
    
    float distance = 0.0;
    float rLen = 0.0;
    vec3  rPos = cPos;
    for(int i = 0; i < 50; i++){
	  
        distance = distanceFunc(rPos);
        rLen += distance;
        rPos = cPos + ray * rLen;
    }
    
    // hit check
    if(abs(distance) < 0.001){
        vec3 normal = getNormal(rPos);
        gl_FragColor = vec4(vec3(normal), 0.);
    }else{
        gl_FragColor = vec4(vec3(0.0), 1.);
    }
}


