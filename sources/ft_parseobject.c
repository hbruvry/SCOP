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

void		ft_parseobject(char *objpath)
{
    int		i;
    int		vcount;
    int		vncount;
    int		vtcount;
    int		fcount;
	char	*objdata;

    i = -1;
    vcount = 0;
    vncount = 0;
    vtcount = 0;
    fcount = 0;
	objdata = ft_filecpy(objpath);
    while (*objdata)
    {
        if (*objdata == 'v')
        {
            if (*(objdata + 1) == 'n')
                vncount++;
            else if (*(objdata + 1) == 't')
                vtcount++;
            else
                vcount++;   
        }
        else if (*objdata == 'f')
            fcount++;
        while (*objdata != '\n' && *objdata != '\0')
            objdata++;
        if (*objdata)
            objdata++;
    }
    ft_putstr("vcount = ");
    ft_putnbr(vcount);
    ft_putstr(";\nvncount = ");
    ft_putnbr(vncount);
    ft_putstr(";\nvtcount = ");
    ft_putnbr(vtcount);
    ft_putstr(";\nfcount = ");
    ft_putnbr(fcount);
    ft_putstr(";\n");
	return ;
}
