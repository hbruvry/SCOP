/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatecamera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:06:38 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 16:17:20 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

void    ft_updatecamera(t_cam *cam)
{
    t_vec3  vup;

    vup = ft_vec3set(0.f, 1.f, 0.f);
	/*
	if (cam->target == true)
		cam->vdir = ft_vec3norm(ft_vec3sub(cam->vpos, cam->vtarget));
	else
	*/
	cam->vdir = ft_vec3norm(ft_vec3sub(cam->vpos,
		ft_vec3add(cam->vpos, cam->vfront)));
	cam->vright = ft_vec3norm(ft_vec3cross(vup, cam->vdir));
	cam->vup = ft_vec3cross(cam->vdir, cam->vright);
	return ;   
}