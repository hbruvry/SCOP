/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:20:08 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:20:10 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_vec3	ft_vec3scalar(t_vec3 vec, float scale)
{
	vec.v[0] *= scale;
	vec.v[1] *= scale;
	vec.v[2] *= scale;
	return (vec);
}