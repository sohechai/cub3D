/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:16:56 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:50:59 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_freesprites(t_sprites **firsts)
{
	t_sprites *now;
	t_sprites *next;

	now = (*firsts);
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
	(*firsts) = NULL;
}

void		ft_freewindow(t_window *window)
{
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	free(window);
}

void		ft_freeimg(t_img *img, t_window *window)
{
	if (img->path)
		free(img->path);
	if (img->img_ptr)
		mlx_destroy_image(window->mlx_ptr, img->img_ptr);
	free(img);
}

void		ft_clearstruct(t_cubed *st)
{
	ft_freeimg(st->north, st->window);
	ft_freeimg(st->south, st->window);
	ft_freeimg(st->east, st->window);
	ft_freeimg(st->west, st->window);
	ft_freeimg(st->sprit, st->window);
	ft_freeimg(st->img, st->window);
	if (st->firstsprite)
		ft_freesprites(&st->firstsprite);
	free(st->firstsprite);
	ft_freewindow(st->window);
	free(st);
}
