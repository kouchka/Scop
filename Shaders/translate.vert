#version 410 core

uniform mat4 trans;
uniform mat4 rotate;
in vec3 vertex;

void main()
{
		gl_Position = trans * vec4(vertex, 1.0) * rotate;
}
