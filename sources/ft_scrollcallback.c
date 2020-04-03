/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrollcallback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:54:04 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/03 11:54:06 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void	ft_scrollcallback(GLFWwindow *window, double offsetx, double offsety)
{
	t_env	*e;

	(void)offsetx;
	glfwGetKey(window, GLFW_KEY_Z);
	e = ft_getenvironment();
	if (1.0f < e->cam.fov && e->cam.fov < 45.f)
		e->cam.fov -= offsety;
	else if (e->cam.fov <= 1.f)
		e->cam.fov = 1.f;
	else if (e->cam.fov >= 1.f)
		e->cam.fov = 45.f;
	return ;
}
