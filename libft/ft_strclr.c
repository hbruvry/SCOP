/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:05:04 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 16:24:48 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Sets to 0 all characters of string s
*/

void	ft_strclr(char *s)
{
	size_t	ls;

	ls = 0;
	if (s)
	{
		ls = ft_strlen(s);
		ft_memset(s, '\0', ls);
	}
	return ;
}
