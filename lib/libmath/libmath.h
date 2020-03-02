/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:21:12 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:21:15 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBMATH_H
# define __LIBMATH_H

# include <math.h>
# include <stdio.h>

# define AXIS_X 0
# define AXIS_Y 1
# define AXIS_Z 2
# define IDENTITY 0x7FFFFFFF

typedef struct		s_vec3
{
	float	v[3];
}					t_vec3;

typedef struct		s_mat4
{
	float	m[16];
}					t_mat4;

t_vec3				ft_vec3set(float x, float y, float z);
t_vec3				ft_vec3cpy(t_vec3 *vdst, t_vec3 vsrc);
t_vec3				ft_vec3add(t_vec3 vdst, t_vec3 vsrc);
t_vec3				ft_vec3sub(t_vec3 vdst, t_vec3 vsrc);
t_vec3				ft_vec3scalar(t_vec3 vec, float f);
float				ft_vec3magnitude(t_vec3 vec);
t_vec3				ft_vec3norm(t_vec3 vec);
t_vec3				ft_vec3cross(t_vec3 vdst, t_vec3 vsrc);
float				ft_vec3dot(t_vec3 vdst, t_vec3 vsrc);
void				ft_vec3print(t_vec3 vec);
void				ft_mat4set(t_mat4 *mat, float f);
t_mat4				ft_mat4cpy(t_mat4 *mdst, t_mat4 msrc);
t_mat4				ft_mat4add(t_mat4 mdst, t_mat4 msrc);
t_mat4				ft_mat4sub(t_mat4 mdst, t_mat4 msrc);
t_mat4				ft_mat4mul(t_mat4 mdst, t_mat4 msrc);
t_mat4				ft_mat4scalar(t_mat4 mat, float scale);
t_mat4				ft_mat4scale(t_mat4 mat, t_vec3 vscale);
t_mat4				ft_mat4rotate(t_mat4 mat, t_vec3 vrot);
t_mat4				ft_mat4translate(t_mat4 mat, t_vec3 vtrans);
t_mat4				ft_mat4transform(t_mat4 mat,
									t_vec3 vscale, t_vec3 vrot, t_vec3 vtrans);
t_mat4				ft_mat4transpose(t_mat4 mat);
void				ft_mat4print(t_mat4 mat);
t_vec3				ft_vec3appmat4(t_vec3 vec, t_mat4 mat);

#endif
