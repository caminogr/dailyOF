#version 150

uniform sampler2DRect thresholded;
uniform vec2 resolution;
uniform float time;

in vec2 texCoordVarying;
out vec4 outputColor;

float rand(float v){
    return fract(sin(v));
}

void main()
{
	vec2 st = gl_FragCoord.xy/resolution;
  vec4 image = texture(thresholded, texCoordVarying);
  float frequency = 1.8;
  float speed = .5;
  float amplitude = 10.;
  float offset = mod((frequency + time * speed) * amplitude, 10.);
  vec4 dest = texture(thresholded, texCoordVarying + vec2(offset));
  outputColor = dest;
}
