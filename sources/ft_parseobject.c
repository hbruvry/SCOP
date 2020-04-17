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

void		ft_printobjectdata(t_obj obj)
{
	int vinc;
	int	finc;

	vinc = 0;
	finc = -1;
	while (vinc < obj.vcount * 3)
	{
		printf("%f, ", obj.vertexbufferdata[vinc++]);
		printf("%f, ", obj.vertexbufferdata[vinc++]);
		printf("%f;\n", obj.vertexbufferdata[vinc++]);
	}
	vinc = 0;
	while (vinc < obj.vcount * 3)
	{
		printf("%f, ", obj.colorbufferdata[vinc++]);
		printf("%f, ", obj.colorbufferdata[vinc++]);
		printf("%f;\n", obj.colorbufferdata[vinc++]);
	}
	vinc = 0;
	while (vinc < obj.vcount * 2)
	{
		printf("%f, ", obj.uvbufferdata[vinc++]);
		printf("%f;\n", obj.uvbufferdata[vinc++]);		
	}	
	while (++finc < obj.fcount)
	{
		if (finc == obj.fcount - 1)
			printf("%d;\n", obj.indicebufferdata[finc]);
		else
			printf("%d, ", obj.indicebufferdata[finc]);
	}
	return;
}

int			ft_createobject(t_obj *obj, char *objdata)
{
	int		i;
	int		j;
	int		k;
	int		vinc;
	int		vtinc;
	int		finc;
	int		fincprev;

	i = -1;
	j = 0;
	k = 0;
	vinc = -1;
	finc = -1;
	vtinc = -1;
	k = 0;
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
				ft_setcolorbufferdata(&(obj->colorbufferdata[k * 3]), k);
				i += j;
				j = 0;
			}
			if (k % 4 == 0)
			{
				obj->uvbufferdata[++vtinc] = 0.f;
				obj->uvbufferdata[++vtinc] = 0.f;
			}
			else if (k % 4 == 1)
			{
				obj->uvbufferdata[++vtinc] = 0.f;
				obj->uvbufferdata[++vtinc] = 1.f;
			}
			else if (k % 4 == 2)
			{
				obj->uvbufferdata[++vtinc] = 1.f;
				obj->uvbufferdata[++vtinc] = 1.f;
			}
			else if (k % 4 == 3)
			{
				obj->uvbufferdata[++vtinc] = 1.f;
				obj->uvbufferdata[++vtinc] = 0.f;
			}
			k++;
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
	ft_printobjectdata(*obj);
	return (0);
}

int			ft_parseobject(t_obj *obj)
{
	int		i;
	int		j;
	char	*objdata;

	i = -1;
	if(!(objdata = ft_filecpy("./resources/objects/42.obj")))
	{
		ft_putstr("Failed to load object\n");
		return (-1);
	}
	while (objdata[++i] != '\0')
	{
		if (objdata[i] == 'v')
			obj->vcount++;   
		else if (objdata[i] == 'f')
		{
			j = 0;
			while (objdata[i] != '\n' && objdata[i] != '\0')
			{
				while (ft_isalpha(objdata[i]) || objdata[i] == ' ')
					i++;
				while (ft_isdigit(objdata[i]))
					i++;
				if (j == 3)
					obj->fcount += 2;
				obj->fcount++;
				j++;
			}
		}
		while (objdata[i] != '\n' && objdata[i] != '\0')
			i++;
	}
	if (obj->vcount && !(obj->vertexbufferdata = ft_memalloc(obj->vcount * 3 * sizeof(*(obj->vertexbufferdata)))))
		return (-1);
	if (obj->vcount && !(obj->colorbufferdata = ft_memalloc(obj->vcount * 3 * sizeof(GLfloat))))
		return (-1);
	if (obj->vcount && !(obj->uvbufferdata = ft_memalloc(obj->vcount * 2 * sizeof(GLfloat))))
		return (-1);
	if (obj->fcount && !(obj->indicebufferdata = ft_memalloc(obj->fcount * sizeof(GLuint))))
		return (-1);
	ft_createobject(obj, objdata);
	/*
	ft_putstr("vcount = ");
	ft_putnbr(obj->vcount);
	ft_putstr(";\nfcount = ");
	ft_putnbr(obj->fcount);
	ft_putstr(";\n");
	*/
	ft_putendl("Object parsed");
	return (0);
}
