/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:53:18 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:21:46 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
** http://www.opengl-tutorial.org/fr/beginners-tutorials/tutorial-1-opening-a-window/
*/

int		ft_createwindow(GLFWwindow **window)
{
	if (!glfwInit())
	{
		ft_putendl("Failed to initialize GLFW");
		return (-1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(*window = glfwCreateWindow(WIDTH, HEIGHT, "scop", NULL, NULL)))
	{
		ft_putendl("Failed to open GLFW window");
		return (-1);
	}
	glfwMakeContextCurrent(*window);
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

int		ft_createvao(GLuint *vertexarrayid)
{
	glGenVertexArrays(1, vertexarrayid);
	glBindVertexArray(*vertexarrayid);
    ft_putendl("Vertex array object created");
	return (0);
}

/*
** TODO
*/

int		ft_createvbo(GLuint *vertexbuffer, GLuint *colorbuffer)
{
	GLfloat	vertexbufferdata[] = {
		-1.f, -1.f, -1.f,
		-1.f, -1.f, 1.f,
		-1.f, 1.f, 1.f,
		1.f, 1.f, -1.f,
		-1.f, -1.f, -1.f,
		-1.f, 1.f, -1.f,
		1.f, -1.f, 1.f,
		-1.f, -1.f, -1.f,
		1.f, -1.f, -1.f,
		1.f, 1.f, -1.f,
		1.f, -1.f, -1.f,
		-1.f, -1.f, -1.f,
		-1.f, -1.f, -1.f,
		-1.f, 1.f, 1.f,
		-1.f, 1.f, -1.f,
		1.f, -1.f, 1.f,
		-1.f, -1.f, 1.f,
		-1.f, -1.f, -1.f,
		-1.f, 1.f, 1.f,
		-1.f, -1.f, 1.f,
		1.f, -1.f, 1.f,
		1.f, 1.f, 1.f,
		1.f, -1.f, -1.f,
		1.f, 1.f, -1.f,
		1.f, -1.f, -1.f,
		1.f, 1.f, 1.f,
		1.f, -1.f, 1.f,
		1.f, 1.f, 1.f,
		1.f, 1.f, -1.f,
		-1.f, 1.f, -1.f,
		1.f, 1.f, 1.f,
		-1.f, 1.f, -1.f,
		-1.f, 1.f, 1.f,
		1.f, 1.f, 1.f,
		-1.f, 1.f, 1.f,
		1.f, -1.f, 1.0f
	};
	GLfloat colorbufferdata[] = {
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};

	glGenBuffers(1, vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexbufferdata), vertexbufferdata, GL_STATIC_DRAW);
	glGenBuffers(1, colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexbufferdata), colorbufferdata, GL_STATIC_DRAW);
    ft_putendl("Vertex buffer object created");
	return (0);
}

/*
** TODO
** glVertexAttribPointer(0, size, type, normalizedn stride, arraybufferoffset);
*/

void	ft_drawvertexbuffer()
{
	t_env   *e;

	e = ft_getenvironment();
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, e->colorbuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	return ;
}

/*
** TODO
*/

int		main(void)
{
	t_env   *e;

	e = ft_getenvironment();
	if (ft_createwindow(&(e->window)))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetInputMode(e->window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.8f, 0.8f, 0.8f, 1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	ft_createvao(&(e->vertexarrayid));
	ft_createvbo(&(e->vertexbuffer), &(e->colorbuffer));
	ft_createshaderprogram(&(e->shaderprogramid));
	while (glfwGetKey(e->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
			&& !glfwWindowShouldClose(e->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ft_updatecamera(&(e->cam));
		ft_setpvmmatrices(e->cam);
		glUseProgram(e->shaderprogramid);
		ft_drawvertexbuffer();
		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &(e->vertexarrayid));
	glDeleteBuffers(1, &(e->vertexbuffer));
	glDeleteProgram(e->shaderprogramid);
	glfwTerminate();
    ft_putendl("Delete VBO\nDelete VAO\nExit program");
	exit(EXIT_SUCCESS);
}