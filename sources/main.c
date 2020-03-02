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
	if (!(*window = glfwCreateWindow(WIDTH, HEIGHT, "scop", NULL, NULL)))
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
** Create VAO (vertex array object), so we can send
** large batches of data all at once to the graphics card,
** the VAO stores our vertex attribute configuration,
** which VBO (vertex buffer object) to use
** and EBO (element buffer objects) that contain indices
** used to decide what vertices to draw
*/

void		ft_createvao(uint *vao)
{
	uint	vbo;
	uint	ebo;
	float	vertices[] = {
		0.5f, 0.5f, 0.f, 1.f, 0.f, 0.f, 1.f, 1.f,
		0.5f, -0.5f, 0.f, 0.f, 1.f, 0.f, 1.f, 0.f,
		-0.5f, -0.5f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f,
		-0.5f, 0.5f, 0.f, 1.f, 1.f, 0.f, 0.f, 1.f
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
						8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
						8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
						8 * sizeof(float), (void*)(6 * sizeof(float)));
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
** [+0][+1][+2][+3]
** [+4][+5][+6][+7]
** [+8][+9][10][11]
** [12][13][14][15]
*/

t_mat4		ft_setprojectionmat4(float fov, float ratio, float near, float far)
{
	t_mat4	mat;
	float	tanhalffov;

	ft_bzero(&mat, 16 * sizeof(float));
	tanhalffov = tan(fov * 0.5f * M_PI / 180.f);
	mat.m[0] = 1.f / (ratio * tanhalffov);
	mat.m[5] = 1.f / tanhalffov;
	mat.m[10] = -(far + near) / (far - near);
	mat.m[11] = -1.f;
	mat.m[14] = -2.f * far * near / (far - near);
	return (mat);
}

/*
** TODO
*/

void		ft_setpvmmatrices(uint shaderprogram)
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	projection;

	ft_mat4set(&model, IDENTITY);
	model = ft_mat4transpose(ft_mat4transform(model,
											ft_vec3set(1.f, 1.f, 1.f),
											ft_vec3set(0.f, 0.f, 0.f),
											ft_vec3set(0.f, 0.f, 0.f)));
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "model"),
											1, GL_FALSE, model.m);
	view = ft_mat4transpose(ft_setviewmatrix());
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "view"),
											1, GL_FALSE, view.m);
	projection = ft_setprojectionmat4(FOV, WIDTH / (float)HEIGHT, NEAR, FAR);
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "projection"),
											1, GL_FALSE, projection.m);
	return ;
}

/*
** TODO
*/

int			main(void)
{
	GLFWwindow	*window;
	uint		shaderprogram;
	uint		texture[2];
	uint		vao;
	t_env		*e;

	e = ft_getenv();
	if (ft_createwindow(&window)
		|| ft_creatematerial(&shaderprogram, &texture[0]))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	ft_createvao(&vao);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(window))
	{
		e->time.currentframe = glfwGetTime();
		e->time.delta = e->time.currentframe - e->time.lastframe;
		e->time.lastframe = e->time.currentframe;
		ft_processinput(window);
		ft_setpvmmatrices(shaderprogram);
		ft_draw(shaderprogram, texture, vao);
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}