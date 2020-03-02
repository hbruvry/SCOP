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

t_mat4	ft_setlookatmatrix(t_vec3 vcamright, t_vec3 vcamup, t_vec3 vcamdirection, t_vec3 vcamposition)
{
	t_mat4	mat;
	t_mat4	mtrans;

	ft_bzero(&mat, 16 * sizeof(float));
	mat.m[0] = vcamright.v[0];
	mat.m[1] = vcamright.v[1];
	mat.m[2] = vcamright.v[2];
	mat.m[4] = vcamup.v[0];
	mat.m[5] = vcamup.v[1];
	mat.m[6] = vcamup.v[2];
	mat.m[8] = vcamdirection.v[0];
	mat.m[9] = vcamdirection.v[1];
	mat.m[10] = vcamdirection.v[2];
	mat.m[15] = 1.f;
	ft_mat4set(&mtrans, IDENTITY);
	mtrans = ft_mat4translate(mtrans, ft_vec3scalar(vcamposition, -1.f));
	mat = ft_mat4mul(mat, mtrans);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_setviewmatrix()
{
	t_env   *e;
	float   radius;
//	t_vec3  vcamposition;
	t_vec3  vcamtarget;
	t_vec3  vcamdirection;
	t_vec3  vcamright;
//	t_vec3  vcamup;
	t_mat4  mat;

	e = ft_getenv();
	radius = 1.f;
//	vcamposition = ft_vec3set(sin(glfwGetTime()) * radius, 0.f, cos(glfwGetTime()) * radius);
	if (e->cam.target)
        vcamtarget = ft_vec3set(0.f, 0.f, 0.f);
    else
        vcamtarget = ft_vec3add(e->cam.vpos, e->cam.vfront);
	vcamdirection = ft_vec3norm(ft_vec3sub(e->cam.vpos, vcamtarget));
	vcamright = ft_vec3norm(ft_vec3cross(e->cam.vup, vcamdirection));
//	vcamup = ft_vec3norm(ft_vec3cross(vcamdirection, vcamright));
	mat = ft_setlookatmatrix(vcamright, e->cam.vup, vcamdirection, e->cam.vpos);
	return (mat);
}

