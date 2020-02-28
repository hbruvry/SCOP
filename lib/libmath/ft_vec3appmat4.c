/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3appmat4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:18:59 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:19:02 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libmath.h"

/*
** TODO
*/

t_vec3	ft_vec3appmat4(t_vec3 vec, t_mat4 mat)
{
	t_vec3	vdst;
	float	w;

	vdst.v[0] = vec.v[0] * mat.m[0]
				+ vec.v[1] * mat.m[4] + vec.v[2] * mat.m[8] + mat.m[12];
	vdst.v[1] = vec.v[0] * mat.m[1]
				+ vec.v[1] * mat.m[5] + vec.v[2] * mat.m[9] + mat.m[13];
	vdst.v[2] = vec.v[0] * mat.m[2]
				+ vec.v[1] * mat.m[6] + vec.v[2] * mat.m[10] + mat.m[14];
	w = vec.v[0] * mat.m[3]
		+ vec.v[1] * mat.m[7] + vec.v[2] * mat.m[11] + mat.m[15];
	if (w != 1.f)
	{
		printf("w = %f\n", w);
		vdst = ft_vec3scalar(vdst, 1.f / w);
	}
	return (vdst);
}
