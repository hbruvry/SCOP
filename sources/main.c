/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:53:18 by hbruvry           #+#    #+#             */
/*   Updated: 2020/01/09 10:57:37 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void	ft_draw(void)
{
	return ;
}

/*
**	Create window setting 4x antialiasing and OpenGL 3
*/

int		ft_createwindow(GLFWwindow **window)
{
	if (!glfwInit())
	{
		ft_putstr("Failed to initialize GLFW\n");
		return (-1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(*window = glfwCreateWindow(500, 500, "scop", NULL, NULL)))
	{
		ft_putstr("Failed to open GLFW window\n");
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(*window);
	if (glewInit() != GLEW_OK)
	{
		ft_putstr("Failed to initialize GLEW\n");
		return (-1);
	}
	return (0);
}

/*
** TODO
*/

int main(void)
{
    GLFWwindow* window;
    
	if (ft_createwindow(&window))
		exit(EXIT_FAILURE);
	else
	{
		ft_putstr((char*)glGetString(GL_RENDERER));
		ft_putstr("\nOpenGL version supported ");
		ft_putstr((char*)glGetString(GL_VERSION));
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(window))
	{
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		ft_draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
