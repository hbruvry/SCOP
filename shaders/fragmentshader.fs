#version 330 core

flat in vec3 fragmentColor;
in vec2 UV;

out vec4 color;

uniform sampler2D myTextureSampler;
uniform float myTextureAlpha;

void main()
{
	vec3 c = mix(fragmentColor, texture(myTextureSampler, UV).rgb, myTextureAlpha);
	color = vec4(c, 1.0);
}