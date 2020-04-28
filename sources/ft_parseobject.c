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
** TODO
*/

int			ft_createvertexbufferdata(GLfloat **vertexbufferdata, int vcount, char **objdata)
{
	int		i;
	int		vinc;
	t_vec3	vsum;
	t_vec3	vec;

	i = -1;
	vinc = 0;
	vec = ft_vec3set(0.f, 0.f, 0.f);
	vsum = ft_vec3set(0.f, 0.f, 0.f);
	if (!(*vertexbufferdata = ft_memalloc(vcount * sizeof(GLfloat))))
		return (-1);
	while (objdata[++i])
	{
		if (objdata[i][0] == 'v')
		{
			ft_setvertexbufferdata(*vertexbufferdata + vinc, &objdata[i][0]);
			vec = ft_vec3set(*(*vertexbufferdata + vinc),
							*(*vertexbufferdata + vinc + 1),
							*(*vertexbufferdata + vinc + 2));				
			vsum = ft_vec3add(vsum, vec);
			vinc += 3;
		}
	}
	vsum = ft_vec3scalar(vsum, 1.f / (vcount / 3.f));
	ft_translatevertexbufferdata(*vertexbufferdata, vcount, vsum);
	return (0);
}

/*
** TODO
*/

int			ft_createuvbufferdata(GLfloat **uvbufferdata, GLfloat *vertexbufferdata, int vcount)
{
	int 	i;
	int 	vtinc;
	t_vec3	vec;

	i = 0;
	vtinc = 0;
	vec = ft_vec3set(0.f, 0.f, 0.f);
	if (vcount && !(*uvbufferdata = ft_memalloc(vcount / 3 * 2 * sizeof(GLfloat))))
		return (-1);
	while (i < vcount - 2)
	{
		vec = ft_vec3set(vertexbufferdata[i],
						vertexbufferdata[i + 1],
						vertexbufferdata[i + 2]);
		ft_setuvbufferdata(*uvbufferdata + vtinc, vec);
		vtinc += 2;
		i += 3;
	}
	return (0);
}

/*
** TODO
*/

int			ft_createindicebufferdata(GLuint **indicebufferdata, int fcount, char **objdata)
{
	int		i;
	int		j;
	int		k;
	int		finc;

	i = -1;
	finc = 0;
	if (fcount && !(*indicebufferdata = ft_memalloc(fcount * sizeof(GLuint))))
		return (-1);
	while (objdata[++i])
	{
		if (objdata[i][0] == 'f')
		{
			j = -1;
			k = 0;
			ft_setindicebufferdata(*indicebufferdata + finc, &objdata[i][0]);
			while(objdata[i][++j] != '\0')
				if (objdata[i][j] == ' ')
					k++;
			finc += (k > 3) ? 6 : 3;
		}
	}
	return (0);
}

/*
** TODO
*/

void		ft_getobjectdatacounts(t_obj *obj, char **objdata)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (objdata[i])
	{
		if (objdata[i][0] == 'v')
			obj->vcount += 3;
		else if (objdata[i][0] == 'f')
		{
			j = 0;
			k = obj->fcount;
			while (objdata[i][j] != '\n' && objdata[i][j] != '\0')
			{
				while (ft_isalpha(objdata[i][j]) || objdata[i][j] == ' ')
					j++;
				while (ft_isdigit(objdata[i][j]))
					j++;
				obj->fcount += obj->fcount - k == 3 ? 3 : 1;
			}
		}
		i++;
	}
	return ;
}

/*
** TODO
** ft_printobjectdata(*obj);
*/

int			ft_parseobject(char *path, t_obj *obj)
{
	char	**objdata;

	if (!(objdata = ft_filecpytab(path)))
		return (-1);
	ft_getobjectdatacounts(obj, objdata);
	ft_createvertexbufferdata(&(obj->vertexbufferdata), obj->vcount, objdata);
	if (obj->vcount && !(obj->normalbufferdata = ft_memalloc(obj->vcount * sizeof(GLfloat))))
		return (-1);
	ft_createuvbufferdata(&(obj->uvbufferdata), obj->vertexbufferdata, obj->vcount);
	ft_createindicebufferdata(&(obj->indicebufferdata), obj->fcount, objdata);
	ft_putendl("Object parsed");
	return (0);
}