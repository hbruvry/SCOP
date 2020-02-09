/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3norm.c                                      :+:      :+:    :+:   */
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

t_vec3  ft_vec3norm(t_vec3 vec)
{
    int i;
    float mag;

    i = -1;
    mag = ft_vec3magnitude(vec);
    while (i < 3)
        vec.v[i] /= mag;
    return (vec);
}