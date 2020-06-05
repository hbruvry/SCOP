/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawscop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:53:18 by hbruvry           #+#    #+#             */
/*   Updated: 2020/02/28 18:21:46 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scop.h"

/*
** TODO
** glVertexAttribPointer(0, size, type, normalizedn stride, arraybufferoffset);
*/

void	ft_drawvertexbuffer(int fcount)
{
	t_ogl	*o;

	o = ft_getopengl();
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, o->vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, o->normalbuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, o->uvbuffer);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o->elementbuffer);
	glDrawElements(GL_TRIANGLES, fcount, GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	return ;
}

/*
** TODO
*/

void	ft_drawscop(t_ogl *o, t_env *e)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ft_processinput(o->window);
	ft_updatecamera(&(e->cam));
	ft_setpvmmatrices(e->cam, &(o->shaderprogramid));
	glUseProgram(o->shaderprogramid);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, o->texturebuffer);
	glUniform1i(o->textureid, 0);
	ft_drawvertexbuffer(e->obj.fcount);
	glfwSwapBuffers(o->window);
	glfwPollEvents();
	return ;
}
