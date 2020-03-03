/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousecallback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:53:50 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/03 11:53:54 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void	ft_mousecallback(GLFWwindow *window, double posx, double posy)
{
	float	offsetx;
	float	offsety;
	float	sensitivity;
	t_env	*e;

	glfwGetKey(window, GLFW_KEY_Z);
	e = ft_getenvironment();
	if (e->cam.firstmouse == true)
	{
		e->cam.lastx = posx;
		e->cam.lasty = posy;
		e->cam.firstmouse = false;
	}
	offsetx = posx - e->cam.lastx;
	offsety = e->cam.lasty - posy;
	sensitivity = 0.025f;
	e->cam.lastx = posx;
	e->cam.lasty = posy;
	offsetx *= sensitivity;
	offsety *= sensitivity;
	e->cam.yaw += offsetx;
	e->cam.pitch += offsety;
	if (e->cam.pitch > 89.f)
		e->cam.pitch = 89.f;
	if (e->cam.pitch < -89.f)
		e->cam.pitch = -89.f;
	e->cam.vdir.v[0] = cos(e->cam.yaw * M_PI / 180.f) * cos(e->cam.pitch * M_PI / 180.f);
	e->cam.vdir.v[1] = sin(e->cam.pitch * M_PI / 180.f);
	e->cam.vdir.v[2] = sin(e->cam.yaw * M_PI / 180.f) * cos(e->cam.pitch * M_PI / 180.f);
	e->cam.vfront = ft_vec3norm(e->cam.vdir);
	return ;
}
