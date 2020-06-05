/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseobject_utils.c                             :+:      :+:    :+:   */
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

void		ft_translatevertexbufferdata(GLfloat *vertexbufferdata,
										int vcount, t_vec3 vtrans)
{
	int		i;
	t_vec3	vec;

	i = 0;
	while (i < vcount - 2)
	{
		vec = ft_vec3set(vertexbufferdata[i],
						vertexbufferdata[i + 1],
						vertexbufferdata[i + 2]);
		vec = ft_vec3sub(vec, vtrans);
		vertexbufferdata[i] = vec.v[0];
		vertexbufferdata[i + 1] = vec.v[1];
		vertexbufferdata[i + 2] = vec.v[2];
		i += 3;
	}
	return ;
}

/*
** TODO
*/

void		ft_setvertexbufferdata(GLfloat *vertexbufferdata, char *objdata)
{
	int	i;
	int	j;
	int	vinc;

	i = 0;
	j = 0;
	vinc = -1;
	while (objdata[i] != '\0')
	{
		while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
			i++;
		while (objdata[i + j] == '-'
				|| ft_isdigit(objdata[i + j]) || objdata[i + j] == '.')
			j++;
		vertexbufferdata[++vinc] = (GLfloat)ft_atof(ft_strsub(objdata, i, j));
		i += j;
		j = 0;
	}
	return ;
}

/*
** TODO
*/

void		ft_setuvbufferdata(GLfloat *uvbufferdata, t_vec3 vertex)
{
	vertex = ft_vec3norm(vertex);
	uvbufferdata[0] = 2.f * (0.5f + atan2(vertex.v[2], vertex.v[0])
					/ (2 * M_PI)) - 1.f;
	uvbufferdata[1] = 2.f * (0.5f + asin(vertex.v[1]) / M_PI) - 1.f;
	return ;
}

/*
** TODO
*/

void		ft_setindicebufferdata(GLuint *indicebufferdata, char *objdata)
{
	int	i;
	int	j;
	int	finc;

	i = 0;
	j = 0;
	finc = -1;
	while (objdata[i] != '\0')
	{
		while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
			i++;
		while (ft_isdigit(objdata[i + j]))
			j++;
		if (finc == 2)
		{
			indicebufferdata[finc + 1] = indicebufferdata[finc];
			indicebufferdata[finc + 2] = ft_atoi(ft_strsub(objdata, i, j)) - 1;
			indicebufferdata[finc + 3] = indicebufferdata[finc - 2];
		}
		else
			indicebufferdata[++finc] = ft_atoi(ft_strsub(objdata, i, j)) - 1;
		i += j;
		j = 0;
	}
	return ;
}
