/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtexture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:07:28 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 14:07:31 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO : Create my own lib
*/

#define STB_IMAGE_IMPLEMENTATION
#include "includes/stb_image.h"

/*
** TODO
*/

int		ft_createtexture(uint *texture, char *path)
{
	int				width;
	int				height;
	int				nrchannels;
	unsigned char	*data;

	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	data = stbi_load(path, &width, &height, &nrchannels, 0);
	if (!data)
	{
		ft_putstr("Failed to load texture\n");
		return (-1);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
				0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	return (0);
}
