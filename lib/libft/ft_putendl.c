/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:49:16 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 18:53:32 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Write the string s ending with return
*/

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	return ;
}
