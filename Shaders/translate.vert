#version 410 core

uniform mat4 mvp;
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 colors;
layout(location = 2) in vec2 texture_coord;
out vec2 coordTexture;
out vec4 vertex_color;

void main()
{
	gl_Position = mvp * vec4(vertex, 1.0);
	coordTexture = texture_coord;
	vertex_color = vec4(colors, 1.0);
}
