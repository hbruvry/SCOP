/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printobjectdata.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:48:03 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/04 16:48:07 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void		ft_printobjectdata(t_obj obj)
{
	int vinc;
	int	finc;

	vinc = -1;
	finc = -1;
	printf("vcount = %d;\n", obj.vcount);
	printf("fcount = %d;\n", obj.fcount);
	while (++vinc < obj.vcount)
		vinc % 3 == 0 ? printf("\nv %f", obj.vertexbufferdata[vinc])
		: printf(" %f", obj.vertexbufferdata[vinc]);
	vinc = -1;
	while (++vinc < obj.vcount)
		vinc % 3 == 0 ? printf("\nvn %f", obj.normalbufferdata[vinc])
		: printf(" %f", obj.normalbufferdata[vinc]);
	vinc = -1;
	while (++vinc < obj.vcount / 3 * 2)
		vinc % 2 == 0 ? printf("\nvt %f", obj.uvbufferdata[vinc])
		: printf(" %f", obj.uvbufferdata[vinc]);	
	while (++finc < obj.fcount)
		finc % 3 == 0 ? printf("\nf %d", obj.indicebufferdata[finc])
		: printf(" %d", obj.indicebufferdata[finc]);
	printf("\n");
	return;
}