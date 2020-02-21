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

/*
** TODO
*/

t_mat4  ft_mat4transpose(t_mat4 mat)
{
    int     i;
    int     j;
    t_mat4  mtmp;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            mtmp.m[j * 4 + i] = mat.m[i * 4 + j];
    }
    mat = ft_mat4cpy(&mat, mtmp);
    return (mat);
}