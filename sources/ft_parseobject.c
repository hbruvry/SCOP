/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseobject.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:48:03 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/04 16:48:07 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** File copy function
*/

static char	*ft_filecpy(char *path)
{
	int		fd;
	int		ret;
	char	*line;
	char	*file;

	fd = 0;
	line = NULL;
	file = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
	}
	file = ft_strjoin(file, "\0");
	return (file);
}

/*
** TODO
*/

void		ft_setuvbufferdata(GLfloat *uvbufferdata, t_vec3 vertex)
{
	vertex = ft_vec3norm(vertex);
	uvbufferdata[0] = 2.f * (0.5f + atan2(vertex.v[2], vertex.v[0]) / (2 * M_PI)) - 1.f;
	uvbufferdata[1] = 2.f * (0.5f + asin(vertex.v[1]) / M_PI) - 1.f;
	return ;
}

/*
** TODO
*/

void		ft_setcolorbufferdata(GLfloat *colorbufferdata, int vinc)
{
	if (vinc % 3 == 0)
	{
		colorbufferdata[0] = 1.f;
		colorbufferdata[1] = 0.f;
		colorbufferdata[2] = 0.f;
	}
	else if (vinc % 3 == 1)
	{
		colorbufferdata[0] = 0.f;
		colorbufferdata[1] = 1.f;
		colorbufferdata[2] = 0.f;
	}
	else if (vinc % 3 == 2)
	{
		colorbufferdata[0] = 0.f;
		colorbufferdata[1] = 0.f;
		colorbufferdata[2] = 1.f;
	}
	return ;
}

/*
** TODO
*/

void		ft_printobjectdata(t_obj obj)
{
	int vinc;
	int	finc;

	vinc = -1;
	finc = -1;
	ft_putstr("vcount = ");
	ft_putnbr(obj.vcount);
	ft_putstr(";\nfcount = ");
	ft_putnbr(obj.fcount);
	while (++vinc < obj.vcount)
	{
		if (vinc % 3 == 0)
			printf("\nv %f", obj.vertexbufferdata[vinc]);
		else
			printf(" %f", obj.vertexbufferdata[vinc]);
	}
	vinc = -1;
	while (++vinc < obj.vcount)
	{
		if (vinc % 3 == 0)
			printf("\nc %f", obj.colorbufferdata[vinc]);
		else
			printf(" %f", obj.colorbufferdata[vinc]);
	}
	vinc = -1;
	while (++vinc < obj.vcount / 3 * 2)
	{
		if (vinc % 2 == 0)
			printf("\nvt %f", obj.uvbufferdata[vinc]);
		else
			printf(" %f", obj.uvbufferdata[vinc]);	
	}	
	while (++finc < obj.fcount)
	{
		if (finc % 3 == 0)
			printf("\nf %d", obj.indicebufferdata[finc]);
		else
			printf(" %d", obj.indicebufferdata[finc]);
	}
	printf("\n");
	return;
}

/*
** TODO
*/

int			ft_createobject(t_obj *obj, char *objdata)
{
	int		i;
	int		j;
	int		vinc;
	int		vtinc;
	int		finc;
	int		fincprev;
	t_vec3	vertex;
	t_vec3	vsum;

	i = -1;
	j = 0;
	vinc = -1;
	finc = -1;
	vsum = ft_vec3set(0.f, 0.f, 0.f);
	while (objdata[++i] != '\0')
	{
		if (objdata[i] == 'v')
		{
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (objdata[i + j] == '-' || ft_isdigit(objdata[i + j]) || objdata[i + j] == '.')
					j++;
				obj->vertexbufferdata[++vinc] = (GLfloat)ft_atof(ft_strsub(objdata, i, j));
				ft_setcolorbufferdata(&(obj->colorbufferdata[vinc]), vinc);
				i += j;
				j = 0;
			}
			vertex = ft_vec3set(obj->vertexbufferdata[vinc - 2],
								obj->vertexbufferdata[vinc - 1],
								obj->vertexbufferdata[vinc]);
			vsum = ft_vec3add(vsum, vertex);
		}
		else if (objdata[i] == 'f')
		{
			fincprev = finc;
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (ft_isdigit(objdata[i + j]))
					j++;
				if (finc - fincprev == 3)
				{
					obj->indicebufferdata[finc + 1] = obj->indicebufferdata[finc];
					obj->indicebufferdata[finc + 2] = ft_atoi(ft_strsub(objdata, i, j)) - 1;
					obj->indicebufferdata[finc + 3] = obj->indicebufferdata[finc - 2];
					finc += 3;
				}
				else
					obj->indicebufferdata[++finc] = ft_atoi(ft_strsub(objdata, i, j)) - 1;
				i += j;
				j = 0;
			}
		}
		while (objdata[i] != '\n' && objdata[i] != '\0')
			i++;
	}
	vsum = ft_vec3scalar(vsum, 1.f / (obj->vcount / 3.f));
	i = 2;
	while (i < obj->vcount)
	{
		vertex = ft_vec3set(obj->vertexbufferdata[i - 2],
							obj->vertexbufferdata[i - 1],
							obj->vertexbufferdata[i]);
		vertex = ft_vec3sub(vertex, vsum);
		if (i == obj->vcount - 1)
			ft_vec3print(vertex);
		obj->vertexbufferdata[i - 2] = vertex.v[0];
		obj->vertexbufferdata[i - 1] = vertex.v[1];
		obj->vertexbufferdata[i] = vertex.v[2];
		i += 3;
	}
	ft_putendl("\n");
	ft_putnbr(i);
	i = 2;
	vtinc = -1;
	while (i < obj->vcount)
	{
		vertex = ft_vec3set(obj->vertexbufferdata[i - 2],
							obj->vertexbufferdata[i - 1],
							obj->vertexbufferdata[i]);
		ft_setuvbufferdata(&(obj->uvbufferdata[++vtinc]), vertex);
		vtinc++;
		i += 3;
	}
	ft_putendl("\n");
	ft_putnbr(i);
	return (0);
}

/*
** TODO
*/

void		ft_getobjectcounts(t_obj *obj, char *objdata)
{
	int		i;
	int		j;

	i = -1;
	while (objdata[++i] != '\0')
	{
		if (objdata[i] == 'v')
			obj->vcount += 3;
		else if (objdata[i] == 'f')
		{
			j = obj->fcount;
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (ft_isdigit(objdata[i]))
					i++;
				if (obj->fcount - j == 3)
					obj->fcount += 2;
				obj->fcount++;
			}
		}
		while (objdata[i] != '\n' && objdata[i] != '\0')
			i++;
	}
}

/*
** TODO
*/

int			ft_parseobject(t_obj *obj)
{
	int		i;
	char	*objdata;

	i = -1;
	if(!(objdata = ft_filecpy("./resources/objects/42.obj")))
	{
		ft_putstr("Failed to load object\n");
		return (-1);
	}
	ft_getobjectcounts(obj, objdata);
	if (obj->vcount && !(obj->vertexbufferdata = ft_memalloc(obj->vcount * sizeof(*(obj->vertexbufferdata)))))
		return (-1);
	if (obj->vcount && !(obj->colorbufferdata = ft_memalloc(obj->vcount * sizeof(GLfloat))))
		return (-1);
	if (obj->vcount && !(obj->uvbufferdata = ft_memalloc(obj->vcount / 3 * 2 * sizeof(GLfloat))))
		return (-1);
	if (obj->fcount && !(obj->indicebufferdata = ft_memalloc(obj->fcount * sizeof(GLuint))))
		return (-1);
	ft_createobject(obj, objdata);
	ft_printobjectdata(*obj);
	ft_putendl("Object parsed");
	return (0);
}
