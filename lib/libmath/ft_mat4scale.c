/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:16:03 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:16:05 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_mat4	ft_mat4scale(t_mat4 mat, t_vec3 vscale)
{
	t_mat4	mscale;

	ft_mat4set(&mscale, IDENTITY);
	mscale.m[0] = vscale.v[0];
	mscale.m[5] = vscale.v[1];
	mscale.m[10] = vscale.v[2];
	mat = ft_mat4mul(mscale, mat);
	return (mat);
}
