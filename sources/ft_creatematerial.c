/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatematerial.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:26:34 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 12:26:37 by hbruvry          ###   ########.fr       */
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
** Create vertex shader function
*/

int			ft_createvertexshader(uint *vertexshader)
{
	int			success;
	const char	*vertexshadersource;
	char		infolog[512];

	*vertexshader = glCreateShader(GL_VERTEX_SHADER);
	if(!(vertexshadersource = ft_filecpy("./shaders/vertexshader.vs")))
	{
		ft_putstr("Failed to load vertex shader\n");
		return (-1);
	}
	glShaderSource(*vertexshader, 1, &vertexshadersource, NULL);
	glCompileShader(*vertexshader);
	glGetShaderiv(*vertexshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*vertexshader, 512, NULL, infolog);
		ft_putstr("Failed to create vertex shader\n");
		ft_putstr(infolog);
		return (-1);
	}
	return (0);
}

/*
** Create fragment shader function
*/

int			ft_createfragmentshader(uint *fragmentshader)
{
	const char	*fragmentshadersource;

	*fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	if(!(fragmentshadersource = ft_filecpy("./shaders/fragmentshader.fs")))
	{
		ft_putstr("Failed to load fragment shader\n");
		return (-1);
	}
	glShaderSource(*fragmentshader, 1, &fragmentshadersource, NULL);
	glCompileShader(*fragmentshader);
	return (0);
}

/*
** Create a program from vertex and fragment shaders
** and delete shaders once we've linked them into the program
**
** TODO : delete shader in !succes case
*/

int			ft_createshaderprogram(uint *shaderprogram,
									uint *vertexshader, uint *fragmentshader)
{
	int		success;
	char	infolog[512];

	*shaderprogram = glCreateProgram();
	glAttachShader(*shaderprogram, *vertexshader);
	glAttachShader(*shaderprogram, *fragmentshader);
	glLinkProgram(*shaderprogram);
	glGetProgramiv(*shaderprogram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(*shaderprogram, 512, NULL, infolog);
		ft_putstr("Failed to create shader program\n");
		ft_putstr(infolog);
		return (-1);
	}
	glDeleteShader(*vertexshader);
	glDeleteShader(*fragmentshader);
	return (0);
}

/*
** TODO
*/

int			ft_creatematerial(uint *shaderprogram, uint *texture)
{
	uint	vertexshader;
	uint	fragmentshader;

	if (ft_createtexture(texture, "resources/textures/STONE_TEXTURE.jpg")
	|| ft_createtexture(texture + 1, "resources/textures/SNOW_TEXTURE.jpg")
	|| ft_createvertexshader(&vertexshader)
	|| ft_createfragmentshader(&fragmentshader)
	|| ft_createshaderprogram(shaderprogram, &vertexshader, &fragmentshader))
	{
		return (-1);
	}
	glUseProgram(*shaderprogram);
	glUniform1i(glGetUniformLocation(*shaderprogram, "texture1"), 0);
	glUniform1i(glGetUniformLocation(*shaderprogram, "texture2"), 1);
	return (0);
}
