#version 410 core

uniform mat4 projection;
uniform mat4 modelview;
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 colors;
out vec2 coordTexture;
out vec4 vertex_color;

void main()
{
	gl_Position = projection * vec4(vertex, 1.0);
	coordTexture = vec2(vertex);
	vertex_color = vec4(colors, 1.0);
}
