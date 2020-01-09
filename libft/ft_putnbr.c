/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:54:23 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 19:14:20 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Write the number n
*/

void	ft_putnbr(int n)
{
	int res;

	res = 0;
	if (n == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n >= 0)
	{
		res = (n % 10) + '0';
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(res);
	}
	return ;
}
