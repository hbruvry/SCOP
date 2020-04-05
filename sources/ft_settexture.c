/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:26:34 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 12:26:37 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

int				ft_getsizefrombmp(FILE *file, int *width, int *height, int *imagesize)
{
	unsigned char	header[54];

	if (!file || fread(header, 1, 54, file) != 54
		|| (header[0] != 'B' || header[1] != 'M'))
	{
		ft_putendl("Image could not be opened");
		return (-1);
	}
	*width = *(int*)&(header[0x12]);
	*height = *(int*)&(header[0x16]);
	if (!(*imagesize = *(int*)&(header[0x22])))
		*imagesize = (*width) * (*height) * 3;
	ft_putstr("width = ");
	ft_putnbr(*width);
	ft_putstr(";\nheight = ");
	ft_putnbr(*height);
	ft_putstr(";\nsize = ");
	ft_putnbr(*imagesize);
	ft_putstr(";\n");
	return (0);
}

/*
** TODO
*/

unsigned char	*ft_getbmpdata(FILE	*file, int imagesize)
{
	unsigned char	*data;

	if (!(data = (unsigned char*)ft_memalloc(imagesize * sizeof(unsigned char))))
	{
		ft_putendl("Could not allocate memory for image data");
		return (0);
	}
	fread(data, 1, imagesize, file);
	return (data);
}

/*
** TODO
*/

GLuint			ft_setbmptexture(void)
{
	FILE			*file;
	int				width;
	int				height;
	int				imagesize;
	unsigned char	*texture;
	GLuint			textureid;

	file = fopen("./resources/textures/uvtemplate.bmp", "rb");
	if (ft_getsizefrombmp(file, &width, &height, &imagesize))
		return (0);
	ft_putnbr(imagesize);
	if (!(texture = ft_getbmpdata(file, imagesize)))
		return (0);
	fclose(file);
	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
	return (textureid);
}