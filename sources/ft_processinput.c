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
	t_env			*e;
	static float	lastPress = 0.f;
	float			cameraspeed;

	e = ft_getenvironment();
	cameraspeed = 5.f * e->time.delta; 
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(e->cam.vfront, cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(e->cam.vfront, cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(ft_vec3norm(ft_vec3cross(e->cam.vfront, e->cam.vup)), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(ft_vec3norm(ft_vec3cross(e->cam.vfront, e->cam.vup)), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(ft_vec3set(0.f, 1.f, 0.f), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(ft_vec3set(0.f, 1.f, 0.f), cameraspeed));
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && lastPress + 0.25f < e->time.currentframe)
	{
		e->cam.target = !e->cam.target;
		lastPress = e->time.currentframe;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		e->cam.vpos = ft_vec3set(0.f, 0.f, 3.f);
		e->cam.vfront = ft_vec3set(0.f, 0.f, -1.f);
		e->cam.vtarget = ft_vec3set(0.f, 0.f, 0.f);
		e->cam.fov = 45.f;
		e->cam.yaw = -90.f;
		e->cam.pitch = 0.f;
	}
	return ;
}
