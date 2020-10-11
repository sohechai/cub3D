/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:57:15 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/11 23:51:22 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img		*ft_initimg(void)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->img_data = NULL;
	img->img_ptr = NULL;
	img->path = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->sizeline = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

t_window	*ft_initwindow(void)
{
	t_window *window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	window->width = 0;
	window->height = 0;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	return (window);
}

t_cubed     *ft_initstruct(void)
{
	t_cubed *st;

	if (!(st = (t_cubed *)malloc(sizeof(t_cubed))))
		return (NULL);
	// st->map_started = 0;
	// st->map_stopped = 0;
	// st->save = 0;
	st->c_color = 0;
	st->f_color = 0;
	// st->sprites_head = NULL;
	if (!(st->north = ft_initimg())
		|| !(st->south = ft_initimg())
		|| !(st->east = ft_initimg())
		|| !(st->west = ft_initimg())
		|| !(st->sprit = ft_initimg())
		|| !(st->img = ft_initimg())
		|| !(st->window = ft_initwindow()))
		return (NULL);
	return (st);
}