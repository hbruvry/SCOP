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

void	ft_setfirstmouse(double posx, double posy)
{
	t_env	*e;

	e = ft_getenvironment();
	e->cam.lastx = posx;
	e->cam.lasty = posy;
	e->cam.firstmouse = FALSE;
	return ;
}

/*
** TODO
*/

void	ft_mousecallback(GLFWwindow *window, double posx, double posy)
{
	float	offsetx;
	float	offsety;
	float	y;
	float	p;
	t_env	*e;

	glfwGetKey(window, GLFW_KEY_Z);
	e = ft_getenvironment();
	if (e->cam.firstmouse == TRUE)
		ft_setfirstmouse(posx, posy);
	offsetx = (posx - e->cam.lastx) * SENSI;
	offsety = (e->cam.lasty - posy) * SENSI;
	e->cam.lastx = posx;
	e->cam.lasty = posy;
	e->cam.yaw += offsetx;
	y = e->cam.yaw * M_PI / 180.f;
	if (-90.f < e->cam.pitch + offsetx && e->cam.pitch + offsetx < 90.f)
		e->cam.pitch += offsety;
	p = e->cam.pitch * M_PI / 180.f;
	e->cam.vfront = ft_vec3set(cos(y) * cos(p), sin(p), sin(y) * cos(p));
	e->cam.vfront = ft_vec3norm(e->cam.vfront);
	return ;
}
