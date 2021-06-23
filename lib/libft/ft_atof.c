/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:02:32 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/28 13:34:43 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert a string into a float
*/

float	ft_atof(const char *str)
{
	int		i;
	int		sign;
	float	atof;
	float	dec;

	i = 0;
	sign = 1;
	atof = 0;
	dec = 10.f;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ' || str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while ('0' <= str[i] && str[i] <= '9')
		atof = (atof * 10) + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while ('0' <= str[i] && str[i] <= '9')
		{
			atof = atof + (str[i++] - '0') / dec;
			dec *= 10.f;
		}
	}
	return (atof * sign);
}
