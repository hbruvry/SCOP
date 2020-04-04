/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpvmmatrices.c                                :+:      :+:    :+:   */
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

t_mat4	ft_setlookatmatrix(t_cam cam)
{
	t_mat4	mat;
	t_mat4	mtrans;

	ft_bzero(&mat, 16 * sizeof(float));
	mat.m[0] = cam.vright.v[0];
	mat.m[1] = cam.vright.v[1];
	mat.m[2] = cam.vright.v[2];
	mat.m[4] = cam.vup.v[0];
	mat.m[5] = cam.vup.v[1];
	mat.m[6] = cam.vup.v[2];
	mat.m[8] = cam.vdir.v[0];
	mat.m[9] = cam.vdir.v[1];
	mat.m[10] = cam.vdir.v[2];
	mat.m[15] = 1.f;
	ft_mat4set(&mtrans, IDENTITY);
	mtrans = ft_mat4translate(mtrans, ft_vec3scalar(cam.vpos, -1.f));
	mat = ft_mat4mul(mat, mtrans);
	return (mat);
}

/*
** TODO
*/

t_mat4	ft_setprojectionmat4(float fov, float ratio, float near, float far)
{
	t_mat4	mat;
	float	tanhalffov;

	ft_bzero(&mat, 16 * sizeof(float));
	tanhalffov = tan(fov * 0.5f * M_PI / 180.f);
	mat.m[0] = 1.f / (ratio * tanhalffov);
	mat.m[5] = 1.f / tanhalffov;
	mat.m[10] = -(far + near) / (far - near);
	mat.m[11] = -1.f;
	mat.m[14] = -2.f * far * near / (far - near);
	return (mat);
}

/*
** TODO
*/

void	ft_setpvmmatrices(t_cam cam)
{
	t_env	*e;
	t_mat4	modelmat;
	t_mat4	viewmat;
	t_mat4	projectionmat;

	e = ft_getenvironment();

	ft_mat4set(&modelmat, IDENTITY);
	modelmat = ft_mat4transpose(ft_mat4transform(modelmat,
		ft_vec3set(1.f, 1.f, 1.f),
		ft_vec3set(M_PI / 6, M_PI / 3, 0.f),
		ft_vec3set(0.f, 0.f, 0.f)));
	viewmat = ft_mat4transpose(ft_setlookatmatrix(cam));
	projectionmat = ft_setprojectionmat4(cam.fov,
		WIDTH / (float)HEIGHT, NEAR, FAR);
    glUniformMatrix4fv(glGetUniformLocation(e->shaderprogramid, "projection"),
		1, GL_FALSE, projectionmat.m);
	glUniformMatrix4fv(glGetUniformLocation(e->shaderprogramid, "view"),
		1, GL_FALSE, viewmat.m);
	glUniformMatrix4fv(glGetUniformLocation(e->shaderprogramid, "model"),
		1, GL_FALSE, modelmat.m);
	return ;
}