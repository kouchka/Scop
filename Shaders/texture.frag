#version 410 core

in vec2 coordTexture;
uniform sampler2D texture;
uniform vec4 uni_color;
uniform float interpolate;
out vec4 out_Color;

void main()
{
	vec4 color = (uni_color * interpolate) + (texture(texture, coordTexture) * (1.0f - interpolate)
	out_Color = color;
}
