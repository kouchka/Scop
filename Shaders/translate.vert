#version 410 core

uniform mat4 projection;
uniform mat4 modelview;

uniform mat4 trans;
uniform mat4 rotate;
in vec3 vertex;

out vec2 coordTexture;

void main()
{
		gl_Position = trans * vec4(vertex, 1.0) * rotate;
		coordTexture = vec2(vertex);
}
