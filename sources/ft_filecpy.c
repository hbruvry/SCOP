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
** File copy function
*/

char	*ft_filecpy(char *path)
{
	int		fd;
	int		ret;
	char	*line;
	char	*file;

	fd = 0;
	line = NULL;
	file = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		file = ft_strjoin(file, line);
		file = ft_strjoin(file, "\n");
		free(line);
	}
	file = ft_strjoin(file, "\0");
	return (file);
}

/*
** TODO
*/

int		ft_filelen(char *path)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		len++;
	}
	return (close(fd) == -1 ? 0 : len);
}

/*
** TODO
*/

char	**ft_filecpytab(char *path)
{
	int		fd;
	char	b[1];
	int		len;
	char	**fcopy;
	char	*line;

	fcopy = NULL;
	if ((fd = open(path, O_RDONLY)) == -1 || !read(fd, b, 1) || close(fd) == -1)
	{
		ft_putendl("File could not be opened");
		return (NULL);
	}
	if ((len = ft_filelen(path)) != 0)
	{
		if (!(fcopy = ft_memalloc((len + 1) * sizeof(char*)))
			|| (fd = open(path, O_RDONLY)) == -1)
			return (0);
		len = -1;
		while (get_next_line(fd, &line) == 1)
		{
			fcopy[++len] = ft_strdup(line);
			free(line);
		}
	}
	return (fcopy);
}
