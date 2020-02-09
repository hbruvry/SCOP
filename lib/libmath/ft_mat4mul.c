/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4mul.c                                        :+:      :+:    :+:   */
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

t_mat4  ft_mat4mul(t_mat4 mdst, t_mat4 msrc)
{
    int     i;
    int     j;
    int     k;
    t_mat4  mat;

    i = -1;
    while (i++ < 4)
    {
        j = -1;
        while (j++ < 4)
        {
            k = -1;
            mat.m[i * 4 + j] = 0.f;
            while (k++ < 4)
                mat.m[i * 4 + j] += mdst.m[i * 4 + k] * msrc.m[k * 4 + j];
        }
    }
    return (mat);
}