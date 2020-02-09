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

/*
** File copy function
*/

char		*ft_filecpy(char *path)
{
	int		fd;
	int		ret;
	char	*line;
	char	*file;

	fd = 0;
	line = NULL;
	file = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
	}
	file = ft_strjoin(file, "\0");
	return (file);
}

/*
** Create window and context function,
** initialize GLFW and GLEW supporting OpenGL 4
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
** Create vertex shader function
*/

int			ft_createvertexshader(uint *vertexshader)
{
	int			success;
	const char	*vertexshadersource;
	char		infolog[512];

	*vertexshader = glCreateShader(GL_VERTEX_SHADER);
	vertexshadersource = ft_filecpy("./shaders/vertexshader.vs");
	glShaderSource(*vertexshader, 1, &vertexshadersource, NULL);
	glCompileShader(*vertexshader);
	glGetShaderiv(*vertexshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*vertexshader, 512, NULL, infolog);
		ft_putstr("Failed to create vertex shader\n");
		ft_putstr(infolog);
		return (-1);
	}
	return (0);
}

/*
** Create fragment shader function
*/

int			ft_createfragmentshader(uint *fragmentshader)
{
	const char	*fragmentshadersource;

	*fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	fragmentshadersource = ft_filecpy("./shaders/fragmentshader.fs");
	glShaderSource(*fragmentshader, 1, &fragmentshadersource, NULL);
	glCompileShader(*fragmentshader);
	return (0);
}

/*
** Create a program from vertex and fragment shaders
** and delete shaders once we've linked them into the program
**
** TODO : delete shader in !succes case
*/

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
		glGetProgramInfoLog(*shaderprogram, 512, NULL, infolog);
		ft_putstr("Failed to create shader program\n");
		ft_putstr(infolog);
		return (-1);
	}
	glDeleteShader(*vertexshader);
	glDeleteShader(*fragmentshader);
	return (0);
}

/*
**
*/

int			ft_createtexture(uint *texture, char *path)
{
	int				width;
	int				height;
	int				nrchannels;
	unsigned char	*data;

	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	data = stbi_load(path, &width, &height, &nrchannels, 0);
	if (!data)
	{
		ft_putstr("Failed to load texture\n");
		return (-1);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	return (0);
}

/*
** Create VAO (vertex array object), so we can send
** large batches of data all at once to the graphics card,
** the VAO stores our vertex attribute configuration,
** which VBO (vertex buffer object) to use
** and EBO (element buffer objects) that contain indices
** used to decide what vertices to draw
*/

void		ft_creatervao(uint *vao)
{
	uint	vbo;
	uint	ebo;
	float	vertices[] = {
		// positions		// colors		// texels
		0.5f,  0.5f, 0.f,	1.f, 0.f, 0.f,	1.f, 1.f,	
		0.5f, -0.5f, 0.f,	0.f, 1.f, 0.f,	1.f, 0.f,
	   -0.5f, -0.5f, 0.f,	0.f, 0.f, 1.f,	0.f, 0.f,
	   -0.5f,  0.5f, 0.f,	1.f, 1.f, 0.f,	0.f, 1.f
	};
	uint	indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ARRAY_BUFFER,
				sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				sizeof(indices), indices, GL_STATIC_DRAW);
	// Attribute positions
	glVertexAttribPointer(0, 3, GL_FLOAT,
				GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Attribute colors
	glVertexAttribPointer(1, 3, GL_FLOAT,
				GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// Attribute texels
	glVertexAttribPointer(2, 2, GL_FLOAT,
				GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return ;
}

/*
** TODO
*/

void		ft_draw(uint shaderprogram, uint *texture, uint vao)
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glUseProgram(shaderprogram);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwPollEvents();
	return ;
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
	uint		texture[2];
	uint		vao;

	if (ft_createwindow(&window)
	|| ft_createtexture(&texture[0], "ressources/textures/STONE_TEXTURE.jpg")
	|| ft_createtexture(&texture[1], "ressources/textures/SNOW_TEXTURE.jpg")
	|| ft_createvertexshader(&vertexshader)
	|| ft_createfragmentshader(&fragmentshader)
	|| ft_createshaderprogram(&shaderprogram, &vertexshader, &fragmentshader))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glUseProgram(shaderprogram);
	glUniform1i(glGetUniformLocation(shaderprogram, "texture1"), 0);
	glUniform1i(glGetUniformLocation(shaderprogram, "texture2"), 1);
	ft_creatervao(&vao);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(window))
	{
		ft_draw(shaderprogram, texture, vao);
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
