/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:15:42 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:15:44 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_mat4	ft_setmat4rotx(float theta)
{
	t_mat4	mat;

	ft_mat4set(&mat, IDENTITY);
	mat.m[5] = cos(theta);
	mat.m[6] = sin(theta);
	mat.m[9] = -sin(theta);
	mat.m[10] = cos(theta);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_setmat4roty(float theta)
{
	t_mat4	mat;

	ft_mat4set(&mat, IDENTITY);
	mat.m[0] = cos(theta);
	mat.m[2] = -sin(theta);
	mat.m[8] = sin(theta);
	mat.m[10] = cos(theta);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_setmat4rotz(float theta)
{
	t_mat4	mat;

	ft_mat4set(&mat, IDENTITY);
	mat.m[0] = cos(theta);
	mat.m[1] = sin(theta);
	mat.m[4] = -sin(theta);
	mat.m[5] = cos(theta);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_mat4rotate(t_mat4 mat, t_vec3 vrot)
{
	ft_vec3scalar(vrot, M_PI / 180.f);
	mat = ft_mat4mul(ft_setmat4rotx(vrot.v[0]), mat);
	mat = ft_mat4mul(ft_setmat4roty(vrot.v[1]), mat);
	mat = ft_mat4mul(ft_setmat4rotz(vrot.v[2]), mat);
	return (mat);
}
