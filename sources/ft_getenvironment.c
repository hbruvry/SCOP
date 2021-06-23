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

/*
** TODO
*/

void	ft_setenvironmentobject(t_obj *obj)
{
	obj->vertexbufferdata = NULL;
	obj->normalbufferdata = NULL;
	obj->uvbufferdata = NULL;
	obj->indicebufferdata = NULL;
	obj->istextured = TRUE;
	obj->texturealpha = 1.f;
	obj->vcount = 0;
	obj->fcount = 0;
	obj->elementlength = 0;
	return ;
}

/*
** TODO
*/

void	ft_setenvironmentcamera(t_cam *cam)
{
	cam->vup = ft_vec3set(0.f, 1.f, 0.f);
	cam->vpos = ft_vec3set(0.f, 0.f, 5.f);
	cam->vfront = ft_vec3set(0.f, 0.f, -1.f);
	cam->vtarget = ft_vec3set(0.f, 0.f, 0.f);
	cam->target = FALSE;
	cam->turnaround = FALSE;
	cam->fov = FOV;
	cam->yaw = -90.f;
	cam->pitch = 0.f;
	cam->firstmouse = TRUE;
	cam->lastx = WIDTH * 0.5f;
	cam->lasty = HEIGHT * 0.5f;
	return ;
}

/*
** TODO
*/

t_env	*ft_getenvironment(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
	{
		e = ft_memalloc(sizeof(t_env));
		if (!e)
			return (NULL);
		ft_setenvironmentcamera(&(e->cam));
		ft_setenvironmentcamera(&(e->camreset));
		ft_setenvironmentobject(&(e->obj));
		e->time.delta = 0.f;
		e->time.lastframe = 0.f;
	}
	return (e);
}
