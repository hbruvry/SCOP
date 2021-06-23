#version 330 core

flat in vec3 fragmentColor;
in vec2 uv;

out vec4 color;

uniform sampler2D texSampler;
uniform float texAlpha;

void main()
{
	vec3 c = mix(fragmentColor, texture(texSampler, uv).rgb, texAlpha);
	color = vec4(c, 1.0);
}