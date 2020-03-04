/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setviewmatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:15:42 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 14:15:47 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** [+0][+1][+2][+3]
** [+4][+5][+6][+7]
** [+8][+9][10][11]
** [12][13][14][15]
*/

t_mat4	ft_setlookatmatrix(void)
{
	t_env	*e;
	t_mat4	mat;
	t_mat4	mtrans;

	e = ft_getenvironment();
	ft_bzero(&mat, 16 * sizeof(float));
	mat.m[0] = e->cam.vright.v[0];
	mat.m[1] = e->cam.vright.v[1];
	mat.m[2] = e->cam.vright.v[2];
	mat.m[4] = e->cam.vup.v[0];
	mat.m[5] = e->cam.vup.v[1];
	mat.m[6] = e->cam.vup.v[2];
	mat.m[8] = e->cam.vdir.v[0];
	mat.m[9] = e->cam.vdir.v[1];
	mat.m[10] = e->cam.vdir.v[2];
	mat.m[15] = 1.f;
	ft_mat4set(&mtrans, IDENTITY);
	mtrans = ft_mat4translate(mtrans, ft_vec3scalar(e->cam.vpos, -1.f));
	mat = ft_mat4mul(mat, mtrans);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_setviewmatrix(void)
{
	t_env	*e;
	t_mat4	mat;

	e = ft_getenvironment();
	if (e->cam.target == true)
		e->cam.vdir = ft_vec3norm(ft_vec3sub(e->cam.vpos, e->cam.vtarget));
	else
		e->cam.vdir = ft_vec3norm(ft_vec3sub(e->cam.vpos,
			ft_vec3add(e->cam.vpos, e->cam.vfront)));
	e->cam.vright = ft_vec3norm(ft_vec3cross(e->vup, e->cam.vdir));
	e->cam.vup = ft_vec3cross(e->cam.vdir, e->cam.vright);
	mat = ft_setlookatmatrix();
	return (mat);
}
