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

void	ft_exitscop(void)
{
	t_ogl	*o;

	o = ft_getopengl();
	glDeleteVertexArrays(1, &(o->vertexarrayid));
	glDeleteBuffers(1, &(o->vertexbuffer));
	glDeleteBuffers(1, &(o->normalbuffer));
	glDeleteBuffers(1, &(o->uvbuffer));
	glDeleteBuffers(1, &(o->elementbuffer));
	glDeleteProgram(o->shaderprogramid);
	glfwTerminate();
	ft_putendl("Delete VBO\nDelete VAO\nExit program");
	exit(EXIT_SUCCESS);
}
