/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setshaderprogram.c                              :+:      :+:    :+:   */
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

int			ft_setvertexshader(uint *vertexshaderid)
{
	GLint		success;
	const char	*vertexshadersource;
	char		infolog[512];

	success = GL_FALSE;
	*vertexshaderid = glCreateShader(GL_VERTEX_SHADER);
	if (!(vertexshadersource = ft_filecpy("./shaders/vertexshader.vs")))
	{
		ft_putendl("Failed to load vertex shader");
		return (-1);
	}
	glShaderSource(*vertexshaderid, 1, &vertexshadersource, NULL);
	glCompileShader(*vertexshaderid);
	glGetShaderiv(*vertexshaderid, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*vertexshaderid, 512, NULL, infolog);
		ft_putendl("Failed to create vertex shader");
		ft_putstr(infolog);
		return (-1);
	}
	return (0);
}

/*
** TODO
*/

int			ft_setfragmentshader(uint *fragmentshaderid)
{
	GLint		success;
	const char	*fragmentshadersource;
	char		infolog[512];

	success = GL_FALSE;
	*fragmentshaderid = glCreateShader(GL_FRAGMENT_SHADER);
	if (!(fragmentshadersource = ft_filecpy("./shaders/fragmentshader.fs")))
	{
		ft_putendl("Failed to load fragment shader");
		return (-1);
	}
	glShaderSource(*fragmentshaderid, 1, &fragmentshadersource, NULL);
	glCompileShader(*fragmentshaderid);
	glGetShaderiv(*fragmentshaderid, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*fragmentshaderid, 512, NULL, infolog);
		ft_putendl("Failed to create fragment shader");
		ft_putstr(infolog);
		return (-1);
	}
	return (0);
}

/*
** TODO
*/

int			ft_linkshaders(GLuint *shaderprogramid)
{
	GLuint	vertexshaderid;
	GLuint	fragmentshaderid;

	if (ft_setvertexshader(&vertexshaderid)
		|| ft_setfragmentshader(&fragmentshaderid))
		return (-1);
	*shaderprogramid = glCreateProgram();
	glAttachShader(*shaderprogramid, vertexshaderid);
	glAttachShader(*shaderprogramid, fragmentshaderid);
	glLinkProgram(*shaderprogramid);
	glDeleteShader(vertexshaderid);
	glDeleteShader(fragmentshaderid);
	return (0);
}

/*
** TODO
*/

int			ft_setshaderprogram(GLuint *shaderprogramid)
{
	t_env	*e;
	GLint	success;
	char	infolog[512];

	e = ft_getenvironment();
	success = GL_FALSE;
	if (ft_linkshaders(shaderprogramid))
		return (-1);
	glGetProgramiv(*shaderprogramid, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(*shaderprogramid, 512, NULL, infolog);
		ft_putendl("Failed to create shader program");
		ft_putstr(infolog);
		return (-1);
	}
	ft_putendl("Shader program created");
	return (0);
}
