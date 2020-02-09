/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:41:22 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 14:41:26 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Check if c is a printable character, including space
*/

int	ft_isprint(int c)
{
	if (c < ' ' || '~' < c)
		return (0);
	return (1);
}
