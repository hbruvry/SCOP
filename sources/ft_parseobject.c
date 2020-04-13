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

int			ft_createobject(char *objdata, int vcount, int fcount)
{
	int		i;
	int		j;
	int		vinc;
	int		vtinc;
	int		finc;
	t_env   *e;

	e = ft_getenvironment();
	i = -1;
	j = 0;
	vinc = -1;
	finc = -1;
	vtinc = -1;
	if (vcount && !(e->obj.vertexbufferdata = ft_memalloc(vcount * 3 * sizeof(GLfloat))))
		return (-1);
	if (vcount && !(e->obj.colorbufferdata = ft_memalloc(vcount * 3 * sizeof(GLfloat))))
		return (-1);
	if (vcount && !(e->obj.uvbufferdata = ft_memalloc(vcount * 2 * sizeof(GLfloat))))
		return (-1);
	if (fcount && !(e->obj.indicebufferdata = ft_memalloc(fcount * sizeof(GLuint))))
		return (-1);
	vcount = 0;
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
				e->obj.vertexbufferdata[++vinc] = ft_atof(ft_strsub(objdata, i, j));
				i += j;
				j = 0;
			}
			if (vcount % 4 == 0)
			{
				e->obj.colorbufferdata[vcount * 3] = 1.f;
				e->obj.colorbufferdata[vcount * 3 + 1] = 0.f;
				e->obj.colorbufferdata[vcount * 3 + 2] = 0.f;
				e->obj.uvbufferdata[++vtinc] = 0.f;
				e->obj.uvbufferdata[++vtinc] = 0.f;
			}
			else if (vcount % 4 == 1)
			{
				e->obj.colorbufferdata[vcount * 3] = 0.f;
				e->obj.colorbufferdata[vcount * 3 + 1] = 1.f;
				e->obj.colorbufferdata[vcount * 3 + 2] = 0.f;
				e->obj.uvbufferdata[++vtinc] = 0.f;
				e->obj.uvbufferdata[++vtinc] = 1.f;
			}
			else if (vcount % 4 == 2)
			{
				e->obj.colorbufferdata[vcount * 3] = 0.f;
				e->obj.colorbufferdata[vcount * 3 + 1] = 0.f;
				e->obj.colorbufferdata[vcount * 3 + 2] = 1.f;
				e->obj.uvbufferdata[++vtinc] = 1.f;
				e->obj.uvbufferdata[++vtinc] = 1.f;
			}
			else if (vcount % 4 == 3)
			{
				e->obj.colorbufferdata[vcount * 3] = 1.f;
				e->obj.colorbufferdata[vcount * 3 + 1] = 0.f;
				e->obj.colorbufferdata[vcount * 3 + 2] = 0.f;
				e->obj.uvbufferdata[++vtinc] = 1.f;
				e->obj.uvbufferdata[++vtinc] = 0.f;
			}
			vcount++;
		}
		else if (objdata[i] == 'f')
		{
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (ft_isdigit(objdata[i + j]))
					j++;
				e->obj.indicebufferdata[++finc] = ft_atoi(ft_strsub(objdata, i, j));
				i += j;
				j = 0;
			}
		}
		while (objdata[i] != '\n' && objdata[i] != '\0')
			i++;
	}
	vinc = 0;
	while (vinc < vcount * 3)
	{
		printf("%f, ", e->obj.vertexbufferdata[vinc++]);
		printf("%f, ", e->obj.vertexbufferdata[vinc++]);
		printf("%f;\n", e->obj.vertexbufferdata[vinc++]);
	}
	vinc = 0;
	while (vinc < vcount * 3)
	{
		printf("%f, ", e->obj.colorbufferdata[vinc++]);
		printf("%f, ", e->obj.colorbufferdata[vinc++]);
		printf("%f;\n", e->obj.colorbufferdata[vinc++]);
	}
	vinc = 0;
	while (vinc < vtinc)
	{
		printf("%f, ", e->obj.uvbufferdata[vinc++]);
		printf("%f;\n", e->obj.uvbufferdata[vinc++]);		
	}	
	finc = -1;
	while (++finc < fcount)
	{
		if (finc == fcount - 1)
			printf("%d;\n", e->obj.indicebufferdata[finc]);
		else
			printf("%d, ", e->obj.indicebufferdata[finc]);
	}
	return (0);
}

int			ft_parseobject(void)
{
	int		i;
	int		vcount;
	int		fcount;
	char	*objdata;

	i = -1;
	vcount = 0;
	fcount = 0;
	if(!(objdata = ft_filecpy("./resources/objects/quad.obj")))
	{
		ft_putstr("Failed to load object\n");
		return (-1);
	}
	while (objdata[++i] != '\0')
	{
		if (objdata[i] == 'v')
			vcount++;   
		else if (objdata[i] == 'f')
		{
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (ft_isdigit(objdata[i]))
					i++;
				fcount++;
			}
		}
		while (objdata[i] != '\n' && objdata[i] != '\0')
			i++;
	}
	ft_createobject(objdata, vcount, fcount);
	ft_putstr("vcount = ");
	ft_putnbr(vcount);
	ft_putstr(";\nfcount = ");
	ft_putnbr(fcount);
	ft_putstr(";\n");
	ft_putendl("Object parsed");
	return (0);
}
