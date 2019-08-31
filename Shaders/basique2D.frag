#version 410 core

in vec2 coordTexture;
uniform vec4 vertex_color;
uniform sampler2D our_texture;
out vec4 out_color;

void main()
{
	out_color = texture(our_texture, coordTexture);
}
