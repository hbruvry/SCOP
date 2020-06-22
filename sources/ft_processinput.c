/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:47:20 by hbruvry           #+#    #+#             */
/*   Updated: 2020/03/02 15:47:24 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
*/

void	ft_processcamerainput(GLFWwindow *window)
{
	t_env			*e;
	t_vec3			vup;
	float			camspeed;

	e = ft_getenvironment();
	vup = ft_vec3set(0.f, 1.f, 0.f);
	camspeed = SPEED * e->time.delta;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos,
			ft_vec3scalar(e->cam.vfront, camspeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos,
			ft_vec3scalar(e->cam.vfront, camspeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos,
			ft_vec3scalar(ft_vec3norm(
			ft_vec3cross(e->cam.vfront, e->cam.vup)), camspeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos,
			ft_vec3scalar(ft_vec3norm(
			ft_vec3cross(e->cam.vfront, e->cam.vup)), camspeed));
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		e->cam.vpos = ft_vec3add(e->cam.vpos, ft_vec3scalar(vup, camspeed));
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		e->cam.vpos = ft_vec3sub(e->cam.vpos, ft_vec3scalar(vup, camspeed));
}

/*
** TODO
*/

void	ft_processreset(GLFWwindow *window)
{
	t_env			*e;

	e = ft_getenvironment();
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		e->cam.vpos = ft_vec3cpy(&(e->cam.vpos), e->camreset.vpos);
		e->cam.vfront = ft_vec3cpy(&(e->cam.vfront), e->camreset.vfront);
		e->cam.vtarget = ft_vec3cpy(&(e->cam.vtarget), e->camreset.vtarget);
		e->cam.target = e->camreset.target;
		e->cam.turnaround = e->camreset.turnaround;
		e->cam.fov = e->camreset.fov;
		e->cam.yaw = e->camreset.yaw;
		e->cam.pitch = e->camreset.pitch;
	}
	return ;
}

/*
** TODO
*/

void	ft_processtexturealpha(GLFWwindow *window)
{
	t_env			*e;
	static float	lastpress = 0.f;

	e = ft_getenvironment();
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS
		&& lastpress + 0.25f < e->time.currentframe)
	{
		e->obj.istextured = !e->obj.istextured;
		lastpress = e->time.currentframe;
	}
	if (e->obj.istextured == false && e->obj.texturealpha >= 0.f)
		e->obj.texturealpha -= 0.05f;
	else if (e->obj.istextured == true && e->obj.texturealpha <= 1.f)
		e->obj.texturealpha += 0.05f;
	return ;
}

/*
** TODO
*/

void	ft_processinput(GLFWwindow *window)
{
	t_env			*e;
	static float	lastpress = 0.f;

	e = ft_getenvironment();
	e->time.currentframe = glfwGetTime();
	e->time.delta = e->time.currentframe - e->time.lastframe;
	e->time.lastframe = e->time.currentframe;
	ft_processcamerainput(window);
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS
		&& lastpress + 0.25f < e->time.currentframe)
	{
		if (e->cam.target == false && e->cam.turnaround == false)
			e->cam.target = !e->cam.target;
		else if (e->cam.target == true && e->cam.turnaround == false)
			e->cam.turnaround = !e->cam.turnaround;
		else
		{
			e->cam.target = !e->cam.target;
			e->cam.turnaround = !e->cam.turnaround;
		}
		lastpress = e->time.currentframe;
	}
	ft_processtexturealpha(window);
	ft_processreset(window);
	return ;
}
