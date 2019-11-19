// uniform vec4 bkg_color;
#define M_PI 3.14159265359

uniform float time;

vec3 funcSphere(vec2 inPos) {
	float s = M_PI * 0.5 - M_PI * inPos.y;
	float t = 2. * M_PI * inPos.x;
	float r = 2.;

	return vec3(
	sin(t) * cos(s) * r,
	cos(t) * cos(s) * r,
	sin(s) * r);
}

void main (void) {
  vec2 p = -1.0 + 2.0 * gl_TexCoord[0].xy;
  float r = sqrt(dot(p,p));
  // if (r < 1.0)
  // {
    vec2 uv;
    float f = (1.0-sqrt(1.0-r))/(r);
    uv.x = p.x*f + time;
    uv.y = p.y*f + time;
    // gl_FragColor = texture2D(tex0,uv);
    gl_FragColor = vec4(funcSphere(uv), 0.3);
  }
  // else
  // {
    // gl_FragColor = vec4(vec3(0.8), 1.0);
  // }
}

