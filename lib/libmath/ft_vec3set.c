/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:20:17 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:20:23 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_vec3	ft_vec3set(float x, float y, float z)
{
	t_vec3	vec;

	vec.v[0] = x;
	vec.v[1] = y;
	vec.v[2] = z;
	return (vec);
}
