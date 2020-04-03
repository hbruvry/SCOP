/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:19:25 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:19:30 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_vec3	ft_vec3cross(t_vec3 vdst, t_vec3 vsrc)
{
	t_vec3	vtmp;

	vtmp.v[0] = vdst.v[1] * vsrc.v[2] - vdst.v[2] * vsrc.v[1];
	vtmp.v[1] = vdst.v[2] * vsrc.v[0] - vdst.v[0] * vsrc.v[2];
	vtmp.v[2] = vdst.v[0] * vsrc.v[1] - vdst.v[1] * vsrc.v[0];
	ft_vec3cpy(&vdst, vtmp);
	return (vdst);
}
