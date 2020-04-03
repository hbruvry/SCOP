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
	t_env	*e;

	glfwGetKey(window, GLFW_KEY_Z);
	e = ft_getenvironment();
	if (e->cam.firstmouse == true)
	{
		e->cam.lastx = posx;
		e->cam.lasty = posy;
		e->cam.firstmouse = false;
	}
	offsetx = (posx - e->cam.lastx) * SENSI;
	offsety = (e->cam.lasty - posy) * SENSI;
	e->cam.lastx = posx;
	e->cam.lasty = posy;
	e->cam.yaw += offsetx;
	if (-90.f < e->cam.pitch + offsetx && e->cam.pitch + offsetx < 90.f)
		e->cam.pitch += offsety;
	e->cam.vfront = ft_vec3norm(ft_vec3set(
		cos(e->cam.yaw * M_PI / 180.f) * cos(e->cam.pitch * M_PI / 180.f),
		sin(e->cam.pitch * M_PI / 180.f),
		sin(e->cam.yaw * M_PI / 180.f) * cos(e->cam.pitch * M_PI / 180.f)));
	return ;
}
