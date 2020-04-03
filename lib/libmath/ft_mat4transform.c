/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:18:02 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:18:05 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

t_mat4	ft_mat4transform(t_mat4 mat, t_vec3 vscale, t_vec3 vrot, t_vec3 vtrans)
{
	mat = ft_mat4scale(mat, vscale);
	mat = ft_mat4rotate(mat, vrot);
	mat = ft_mat4translate(mat, vtrans);
	return (mat);
}
