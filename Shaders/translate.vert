#version 410 core

uniform mat4 projection;
uniform mat4 modelview;
in vec3 vertex;
out vec2 coordTexture;

void main()
{
	gl_Position = projection * vec4(vertex, 1.0);
	coordTexture = vec2(vertex);
}
