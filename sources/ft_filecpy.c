/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecopy.c                                      :+:      :+:    :+:   */
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

int	ft_filecharlen(char *path)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		len += ft_strlen(line) + 1;
		free(line);
	}
	if (close(fd) == -1)
		return (0);
	return (len + 1);
}

/*
** File copy function
*/

char	*ft_filecpy(char *path)
{
	int		fd;
	char	*line;
	char	*file;

	fd = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = ft_strnew(ft_filecharlen(path));
	while (get_next_line(fd, &line) == 1)
	{
		ft_strcat(file, line);
		ft_strcat(file, "\n");
		free(line);
	}
	ft_strcat(file, "\0");
	return (file);
}

/*
** TODO
*/

int	ft_filelen(char *path)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		len++;
	}
	if (close(fd) == -1)
		return (0);
	return (len);
}

/*
**
*/

int	ft_checkfile(char *path)
{
	int		fd;
	char	b[1];

	fd = open(path, O_RDONLY);
	if (fd == -1 || !read(fd, b, 1) || close(fd) == -1)
	{
		ft_putendl("File could not be opened");
		return (-1);
	}
	return (0);
}

/*
** TODO
*/

char	**ft_filecpytab(char *path)
{
	int		fd;
	int		len;
	char	**fcopy;
	char	*line;

	fcopy = NULL;
	if (ft_checkfile(path))
		return (NULL);
	len = ft_filelen(path);
	if (len != 0)
	{
		fcopy = ft_memalloc((len + 1) * sizeof(char *));
		fd = open(path, O_RDONLY);
		if (!fcopy || fd == -1)
			return (NULL);
		len = -1;
		while (get_next_line(fd, &line) == 1)
		{
			fcopy[++len] = ft_strdup(line);
			free(line);
		}
	}
	return (fcopy);
}
