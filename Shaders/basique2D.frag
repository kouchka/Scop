#version 410 core

uniform vec4 vertex_color;
out vec4 out_color;

void main()
{
	out_color = vertex_color;
}
