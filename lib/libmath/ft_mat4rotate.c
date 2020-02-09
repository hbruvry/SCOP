/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:38:07 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 20:17:04 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

void    ft_setmat4rotx(t_mat4 *mat, float theta)
{
    mat->m[5] = cos(theta);
    mat->m[6] = sin(theta);
    mat->m[9] = -sin(theta);
    mat->m[10] = cos(theta);
    return ;
}

void    ft_setmat4roty(t_mat4 *mat, float theta)
{
    mat->m[0] = cos(theta);
    mat->m[2] = -sin(theta);
    mat->m[8] = sin(theta);
    mat->m[10] = cos(theta);
    return ;
}

void    ft_setmat4rotz(t_mat4 *mat, float theta)
{
    mat->m[0] = cos(theta);
    mat->m[1] = sin(theta);
    mat->m[4] = -sin(theta);
    mat->m[5] = cos(theta);
    return ;
}

/*
** TODO
*/

t_mat4  ft_mat4rotate(t_mat4 mat, int axis, float angle)
{
    t_mat4  mrot;
    float   theta;

    ft_mat4set(&mrot, IDENTITY);
    theta = angle * (M_PI / 180.f);
    if (axis == AXIS_X)
        ft_setmat4rotx(&mrot, theta);
    else if (axis == AXIS_Y)
        ft_setmat4roty(&mrot, theta);
    else if (axis == AXIS_Z)
        ft_setmat4rotz(&mrot, theta);
    mat = ft_mat4mul(mat, mrot);
    return (mat);
}