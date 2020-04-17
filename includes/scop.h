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

# define WIDTH	480
# define HEIGHT	360
# define FRAGPATH "./shaders/fragmentshadercolor.fs"
# define VERTPATH "./shaders/vertexshadermodel.vs"

# define FOV	90
# define NEAR	0.1
# define FAR	100
# define SPEED	5
# define SENSI	0.025

typedef enum {true, false} bool;

typedef struct	s_ogl
{
	GLFWwindow	*window;
	GLuint		vertexarrayid;
	GLuint		texturebuffer;
	GLuint		textureid;
	GLuint		shaderprogramid;
	GLuint		vertexbuffer;
	GLuint		colorbuffer;
	GLuint		uvbuffer;
	GLuint		elementbuffer;
}				t_ogl;

typedef struct	s_cam
{
	t_vec3		vpos;
	t_vec3		vfront;
	t_vec3		vup;
	t_vec3		vright;
	t_vec3		vdir;
	t_vec3		vtarget;
	bool		target;
	float		fov;
	float		yaw;
	float		pitch;
	bool		firstmouse;
	float		lastx;
	float		lasty;
}				t_cam;

typedef struct	s_time
{
	float		currentframe;
	float		lastframe;
	float		delta;
}				t_time;

typedef struct	s_obj
{
	GLfloat		*vertexbufferdata;
	GLfloat		*colorbufferdata;
	GLfloat		*uvbufferdata;
	GLuint		*indicebufferdata;
	int			vcount;
	int			fcount;
	int			elementlength;
}				t_obj;

typedef struct	s_env
{
	t_cam		cam;
	t_cam		camreset;
	t_obj		obj;
	t_time		time;
}				t_env;

t_ogl			*ft_getopengl(void);
t_env			*ft_getenvironment(void);
int				ft_setshaderprogram(GLuint *shaderprogramid);
int				ft_setbmptexture(GLuint *texturebuffer);
int				ft_parseobject(t_obj *obj);
void			ft_mousecallback(GLFWwindow *window, double posx, double posy);
void			ft_scrollcallback(GLFWwindow *window, double offsetx, double offsety);
void			ft_processinput(GLFWwindow *window);
void			ft_updatecamera(t_cam *cam);
void			ft_setpvmmatrices(t_cam cam, GLuint *shaderprogramid);
void			ft_drawscop(t_ogl *o, t_env *e);

#endif