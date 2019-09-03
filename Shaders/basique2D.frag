#version 410 core

in vec2 coordTexture;
in vec4 vertex_color;
uniform sampler2D our_texture;
uniform float interpolate;
vec4 color1;
vec4 color;
out vec4 out_color;

void main()
{
	color1 = texture(our_texture, coordTexture);
	color = (vertex_color * interpolate) +  (color1 * (1.0f - interpolate));
	out_color = color;
}
