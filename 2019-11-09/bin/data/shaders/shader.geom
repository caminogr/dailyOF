#version 150
precision mediump float;

layout (triangles) in;
layout (triangle_strip, max_vertices = 6) out;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 mvp;
uniform int scale;
uniform float time;
uniform int NormalMode;

in vec3 vNormal[];
in vec4 vColor[];
in vec2 vTexCoord[];
in vec3 vPosition[];

out vec4 gsColor;
out vec2 gsTexCoord;

void main(){
    vec3 offset;

    for(int i=0; i<gl_in.length(); i++){
        // if(NormalMode == 1){
        // float motion = abs(mix(sin(5.*time), exp(cos(time)), sin(time)));
        // float motion = abs(sin(trunc(time/.3)));
        // float motion = abs(mix(sin(trunc(time/.3)), exp(cos(time)),.8));
        float motion = mix(clamp(trunc(mod(time, .5)/.1)/2, 0.0, 1.0), sin(3.*time), .3);
        offset = vNormal[i] * scale * i * motion;
        // }
        gl_Position = mvp * vec4(vPosition[i] + (offset.xyz), 1.0);
        gsColor = vColor[i];
        gsTexCoord = vTexCoord[i];
        EmitVertex();
    }
    EndPrimitive();
}
