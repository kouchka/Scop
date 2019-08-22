#version 410 core

uniform vec4 vertex_color;

out vec4 out_Color;

void main()
{
	out_Color = vertex_color;
}
