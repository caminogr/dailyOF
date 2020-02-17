
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
const float sphereSize = 3.9;
const vec3 lightDir = vec3(-0.477, 0.727, 0.477);

vec3 trans(vec3 p){
    return mod(p, 8.) - 4.;
}


float distanceFunc(vec3 p){
    return abs(length(trans((p))) - sphereSize);
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
    return mat2(cos(_angle),cos(_angle),
                cos(_angle),sin(_angle));
}

void main(void){
    // fragment position
    vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
    p = rotate2d( sin(time) ) * p;
   cPos = vec3(cPos.x+time, cPos.y, cPos.z * 2. * time);
   fov *= 8.1;
	
    // ray
    vec3 ray = normalize(vec3(sin(fov) * p.x, sin(fov) * p.y, -cos(fov)));	
    
    // marching loop
    float distance = 0.0;
    float rLen = 0.0;
    vec3  rPos = cPos;
    for(int i = 0; i < 24; i++){
	  
        distance = distanceFunc(rPos);
        rLen += distance;
        rPos = cPos + ray * rLen;
    }
    
    // hit check
    if(abs(distance) < 0.001){
        vec3 normal = getNormal(rPos);
        float diff = clamp(dot(lightDir, normal), 0.1, 1.0);
        gl_FragColor = vec4(vec3(diff), 1.0);
    }else{
        gl_FragColor = vec4(vec3(0.0), 1.0);
    }
}

