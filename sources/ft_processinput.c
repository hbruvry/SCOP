/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:47:20 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 15:47:24 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void	ft_processinput(GLFWwindow *window)
{
	t_env	*e;
	float	cameraspeed;

	e = ft_getenv();
	cameraspeed = 2.5f * e->time.delta; 
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(e->cam.vfront, cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(e->cam.vfront, cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(ft_vec3norm(ft_vec3cross(e->cam.vfront, e->cam.vup)), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(ft_vec3norm(ft_vec3cross(e->cam.vfront, e->cam.vup)), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		e->cam.target = !e->cam.target;
}