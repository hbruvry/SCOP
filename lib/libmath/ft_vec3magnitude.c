/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3magnitude.c                                 :+:      :+:    :+:   */
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

float  ft_vec3magnitude(t_vec3 vec)
{
    float mag;

    mag = sqrt(vec.v[0] * vec.v[0] + vec.v[1] * vec.v[1] + vec.v[2] * vec.v[2]);
    return (mag);
}