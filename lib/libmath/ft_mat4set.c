/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:18:13 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:18:14 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmath.h"

/*
** TODO
*/

void	ft_mat4set(t_mat4 *mat, float f)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (f == IDENTITY)
		{
			if (i % 5 == 0)
				mat->m[i] = 1.f;
			else
				mat->m[i] = 0.f;
		}
		else
			mat->m[i] = f;
	}
	return ;
}
