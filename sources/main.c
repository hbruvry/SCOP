/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:53:18 by hbruvry           #+#    #+#             */
/*   Updated: 2020/01/09 17:05:49 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

const char	*vertexshadersource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char	*fragmentshadersource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";

/*
** TODO
*/

int			ft_createshaders(uint *vertexshader, uint *fragmentshader)
{
	int		success;
	char	infolog[512];

	*vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertexshader, 1, &vertexshadersource, NULL);
	glCompileShader(*vertexshader);
	glGetShaderiv(*vertexshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
	//	glGetShaderinfolog(*vertexshader, 512, NULL, infolog);
		ft_putstr("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
		ft_putendl((char *)infolog);
		return (-1);
	}
	*fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(*fragmentshader, 1, &fragmentshadersource, NULL);
	glCompileShader(*fragmentshader);
	return (0);
}

int			ft_createshaderprogram(uint *shaderprogram,
									uint *vertexshader, uint *fragmentshader)
{
	int		success;
	char	infolog[512];

	*shaderprogram = glCreateProgram();
	glAttachShader(*shaderprogram, *vertexshader);
	glAttachShader(*shaderprogram, *fragmentshader);
	glLinkProgram(*shaderprogram);
	glGetProgramiv(*shaderprogram, GL_LINK_STATUS, &success);
	if (!success)
	{
	//	glGetPrograminfolog(*shaderprogram, 512, NULL, infolog);
		ft_putstr("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
		ft_putendl((char *)infolog);
		return (-1);
	}
	glDeleteShader(*vertexshader);
	glDeleteShader(*fragmentshader);
	return (0);
}

/*
** TODO
*/

void		ft_draw(uint shaderprogram, uint vao)
{
	glUseProgram(shaderprogram);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return ;
}

/*
**	Create window function, setting 4x antialiasing and OpenGL 3
*/

int			ft_createwindow(GLFWwindow **window)
{
	if (!glfwInit())
	{
		ft_putstr("Failed to initialize GLFW\n");
		return (-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(*window = glfwCreateWindow(500, 500, "scop", NULL, NULL)))
	{
		ft_putstr("Failed to open GLFW window\n");
		return (-1);
	}
	glfwMakeContextCurrent(*window);
	glfwSwapInterval(1);
	if (glewInit() != GLEW_OK)
	{
		ft_putstr("Failed to initialize GLEW\n");
		return (-1);
	}
	ft_putendl((char*)glGetString(GL_RENDERER));
	ft_putstr("OpenGL version supported ");
	ft_putendl((char*)glGetString(GL_VERSION));
	return (0);
}

/*
** TODO
*/

int			main(void)
{
	GLFWwindow	*window;
	uint		vertexshader;
	uint		fragmentshader;
	uint		shaderprogram;
	uint		vao;
	uint		vbo;
	float		vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	if (ft_createwindow(&window))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	ft_createshaders(&vertexshader, &fragmentshader);
	ft_createshaderprogram(&shaderprogram, &vertexshader, &fragmentshader);
/**/
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
	3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
	3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
/**/
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ft_draw(shaderprogram, vao);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
