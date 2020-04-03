/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:19:58 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:20:00 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_vec3	ft_vec3norm(t_vec3 vec)
{
	int		i;
	float	mag;

	i = -1;
	mag = ft_vec3magnitude(vec);
	while (++i < 3)
		vec.v[i] /= mag;
	return (vec);
}
