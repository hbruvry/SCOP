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

int		ft_setvao(GLuint *vertexarrayid)
{
	glGenVertexArrays(1, vertexarrayid);
	glBindVertexArray(*vertexarrayid);
    ft_putendl("Vertex array object created");
	return (0);
}

/*
** TODO
*/

int		ft_setvbo(GLuint *vertexbuffer, GLuint *colorbuffer, GLuint *uvbuffer, GLuint *elementbuffer, t_obj obj)
{
	glGenBuffers(1, vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, obj.vcount * 3 * sizeof(*(obj.vertexbufferdata)), obj.vertexbufferdata, GL_STATIC_DRAW);

	glGenBuffers(1, colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, obj.vcount * 3 * sizeof(*(obj.colorbufferdata)), obj.colorbufferdata, GL_STATIC_DRAW);

	glGenBuffers(1, uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, obj.vcount * 2 * sizeof(*(obj.uvbufferdata)), obj.uvbufferdata, GL_STATIC_DRAW);

	glGenBuffers(1, elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj.fcount * sizeof(*(obj.indicebufferdata)), obj.indicebufferdata, GL_STATIC_DRAW);	

    ft_putendl("Vertex buffer object created");
	return (0);
}

/*
** TODO
*/

void	setopenglenvironement(t_ogl *o, t_env *e)
{
	glfwSetCursorPosCallback(o->window, ft_mousecallback);
	glfwSetScrollCallback(o->window, ft_scrollcallback);
	glfwSetInputMode(o->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(o->window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.8f, 0.8f, 0.8f, 1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	ft_setvao(&(o->vertexarrayid));
	ft_parseobject(&(e->obj));
	ft_setvbo(&(o->vertexbuffer), &(o->colorbuffer), &(o->uvbuffer), &(o->elementbuffer), e->obj);
	ft_setbmptexture(&(o->texturebuffer));
	ft_setshaderprogram(&(o->shaderprogramid));
	o->textureid = glGetUniformLocation(o->shaderprogramid, "myTextureSampler");
	return ;
}

/*
** TODO
*/

int		main(void)
{
	t_ogl	*o;
	t_env   *e;

	o = ft_getopengl();
	e = ft_getenvironment();
	if (ft_createwindow(&(o->window)))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	setopenglenvironement(o, e);
	while (glfwGetKey(o->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
			&& !glfwWindowShouldClose(o->window))
	{
		ft_drawscop(o, e);
	}
	glDeleteVertexArrays(1, &(o->vertexarrayid));
	glDeleteBuffers(1, &(o->vertexbuffer));
	glDeleteProgram(o->shaderprogramid);
	glfwTerminate();
    ft_putendl("Delete VBO\nDelete VAO\nExit program");
	exit(EXIT_SUCCESS);
}