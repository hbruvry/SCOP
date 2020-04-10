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

t_ogl	*ft_getopengl(void)
{
	static t_ogl	*o = NULL;

	if (o == NULL)
	{
		if (!(o = ft_memalloc(sizeof(t_ogl))))
			return (NULL);
		o->window = NULL;
		o->vertexarrayid = 0;
		o->shaderprogramid = 0;
		o->vertexbuffer = 0;
		o->colorbuffer = 0;
		o->uvbuffer = 0;
	}
	return (o);
}