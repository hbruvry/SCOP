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

/*
** TODO : Create my own lib
*/

# define STB_IMAGE_IMPLEMENTATION
# include "includes/stb_image.h"

# define FOV    90
# define WIDTH  480
# define HEIGHT 360
# define NEAR   0.1
# define FAR    100

#endif
