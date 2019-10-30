#version 120

varying vec4 globalColor;

// the time value is passed into the shader by the OF app.
uniform float time;

void main()
{
    vec4 position = ftransform();
    
    // the sine wave travels along the x-axis (across the screen),
    // so we use the x coordinate of each vertex for the calculation,
    // but we displace all the vertex along the y axis (up the screen)/
    float displacementHeight = 10.0;
    float displacementY = tan(mod(time, 9.) + (position.x / 100.0)) * displacementHeight;
	
    vec4 modifiedPosition = position;
    modifiedPosition.y += displacementY;
    gl_Position = modifiedPosition;
    globalColor = gl_Color;
}

