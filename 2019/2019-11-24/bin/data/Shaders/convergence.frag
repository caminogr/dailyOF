
#version 120

uniform sampler2DRect image;
uniform float rand;

varying vec3 pos;

void main (void)
{
    vec2 texCoord = vec2(pos.x , pos.y);

    vec4 col = texture2DRect(image,texCoord);
    vec4 col_r = texture2DRect(image,texCoord + vec2(-35.0*rand,0));
    vec4 col_l = texture2DRect(image,texCoord + vec2(35.0*rand,0));
    vec4 col_g = texture2DRect(image,texCoord + vec2( -7.5*rand,0));
    

    col.b = col.b + col_r.b;
    col.r = col.r + col_l.r;
    col.g = col.g + col_g.g;
    // col = vec3(smoothstep(0.5,0.51,col));

    gl_FragColor.rgba = col.rgba;
}
