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
** Create or return environment structure
*/

t_env	*ft_getenv(void)
{
	static	t_env	*e = NULL;

	if (e == NULL)
	{
		if (!(e = ft_memalloc(sizeof(t_env))))
			return (NULL);
		e->time.delta = 0.f;
		e->time.lastframe = 0.f;
		e->cam.vpos = ft_vec3set(0.f, 0.f, 3.f);
		e->cam.vfront = ft_vec3set(0.f, 0.f, -1.f);
		e->cam.vup = ft_vec3set(0.f, 1.f, 0.f);
		e->cam.target = false;
	}
	return (e);
}
