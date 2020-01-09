/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:30:05 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 14:30:12 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Check if c is a number (0 to 9)
*/

int	ft_isdigit(int c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}
