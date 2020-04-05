/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenvironment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:06:38 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 16:17:20 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

void	ft_setenvironmentcamera(t_cam *cam)
{
	cam->vup = ft_vec3set(0.f, 1.f, 0.f);
	cam->vpos = ft_vec3set(0.f, 0.f, 4.f);
	cam->vfront = ft_vec3set(0.f, 0.f, -1.f);
	cam->vtarget = ft_vec3set(0.f, 0.f, 0.f);
	cam->target = false;
	cam->fov = FOV;
	cam->yaw = -90.f;
	cam->pitch = 0.f;
	cam->firstmouse = true;
	cam->lastx = WIDTH * 0.5f;
	cam->lasty = HEIGHT * 0.5f;
	return ;
}

t_env	*ft_getenvironment(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
	{
		if (!(e = ft_memalloc(sizeof(t_env))))
			return (NULL);
		e->window = NULL;
		e->vertexarrayid = 0;
		e->shaderprogramid = 0;
		e->vertexbuffer = 0;
		e->colorbuffer = 0;
		e->uvbuffer = 0;
		ft_setenvironmentcamera(&(e->cam));
		ft_setenvironmentcamera(&(e->camreset));
		e->time.delta = 0.f;
		e->time.lastframe = 0.f;
	}
	return (e);
}