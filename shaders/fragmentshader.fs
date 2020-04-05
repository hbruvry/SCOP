#version 330 core

in vec3 fragmentColor;
in vec2 UV;

out vec4 color;

uniform sampler2D myTextureSampler;

void main()
{
	color = vec4(fragmentColor, 1.0);
	color = vec4(UV.x, UV.y, UV.x, 1.0);
	color = vec4(texture(myTextureSampler, UV).rgb, 1.0);
}