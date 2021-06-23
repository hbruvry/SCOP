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

void	ft_translatevertexbufferdata(GLfloat *vertexbufferdata,
										int vcount, t_vec3 vtrans)
{
	int		i;
	t_vec3	vec;

	i = 0;
	while (i < vcount - 2)
	{
		vec.v[0] = vertexbufferdata[i];
		vec.v[1] = vertexbufferdata[i + 1];
		vec.v[2] = vertexbufferdata[i + 2];
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

void	ft_setvertexbufferdata(GLfloat *vertexbufferdata, char *objdata)
{
	int		i;
	int		j;
	int		vinc;
	char	*fr;

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
		fr = ft_strsub(objdata, i, j);
		vertexbufferdata[++vinc] = (GLfloat)ft_atof(fr);
		free(fr);
		i += j;
		j = 0;
	}
	return ;
}

/*
** TODO
*/

void	ft_setuvbufferdata(GLfloat *uvbufferdata, t_vec3 vertex)
{
	vertex = ft_vec3norm(vertex);
	uvbufferdata[0] = atan2(vertex.v[2], vertex.v[0]) / (2.0f * M_PI);
	uvbufferdata[0] += 0.5f;
	uvbufferdata[1] = 0.5f - asin(vertex.v[1]) / M_PI;
	return ;
}

/*
** TODO
*/

void	ft_setindicebuffer(int index, GLuint *indicebufferdata, char *str)
{
	indicebufferdata[index + 1] = indicebufferdata[index];
	indicebufferdata[index + 2] = ft_atoi(str) - 1;
	indicebufferdata[index + 3] = indicebufferdata[index - 2];
	return ;
}

/*
** TODO
*/

void	ft_setindicebufferdata(GLuint *indicebufferdata, char *objdata)
{
	int		i;
	int		j;
	int		finc;
	char	*fr;

	i = 0;
	j = 0;
	finc = -1;
	while (objdata[i] != '\0')
	{
		while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
			i++;
		while (ft_isdigit(objdata[i + j]))
			j++;
		fr = ft_strsub(objdata, i, j);
		if (finc == 2)
			ft_setindicebuffer(finc, indicebufferdata, fr);
		else
			indicebufferdata[++finc] = ft_atoi(fr) - 1;
		free(fr);
		i += j;
		j = 0;
	}
	return ;
}
