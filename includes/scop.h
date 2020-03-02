/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:13:30 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:22:00 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOP_H
# define __SCOP_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "lib/libft/libft.h"
# include "lib/libmath/libmath.h"

# define FOV	90
# define WIDTH	480
# define HEIGHT	360
# define NEAR	0.1
# define FAR	100

typedef enum {true, false} bool;

typedef struct	s_cam
{
	t_vec3	vpos;
	t_vec3	vfront;
	t_vec3  vup;
	bool	target;
}				t_cam;

typedef struct	s_time
{
	float	currentframe;
	float	lastframe;
	float	delta;
}				t_time;

typedef struct	s_env
{
	t_cam	cam;
	t_time	time;
}				t_env;

t_env			*ft_getenv(void);
void			ft_processinput(GLFWwindow *window);
int				ft_createtexture(uint *texture, char *path);
int				ft_creatematerial(uint *shaderprogram, uint	*texture);
t_mat4			ft_setviewmatrix();

#endif
