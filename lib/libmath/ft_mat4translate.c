/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:18:29 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:18:30 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_mat4	ft_mat4translate(t_mat4 mat, t_vec3 vtrans)
{
	t_mat4	mtrans;

	ft_mat4set(&mtrans, IDENTITY);
	mtrans.m[3] = vtrans.v[0];
	mtrans.m[7] = vtrans.v[1];
	mtrans.m[11] = vtrans.v[2];
	mat = ft_mat4mul(mtrans, mat);
	return (mat);
}
