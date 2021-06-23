#version 330 core

layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexUV;

flat out vec3 fragmentColor;
out vec2 uv;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vec4(vertexPos, 1.0);

	float level;
	if (gl_VertexID % 2 == 1)
		level = (gl_VertexID % 8) * 0.125;
	else
		level = 1 - ((gl_VertexID % 8) * 0.125);
	fragmentColor = vec3(level);
	uv = vertexUV;
}