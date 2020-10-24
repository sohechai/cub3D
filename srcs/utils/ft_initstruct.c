/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:57:15 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/17 19:58:45 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img		*ft_initimg(void)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = NULL;
	img->img_data = NULL;
	img->path = NULL;
	img->bpp = 0;
	img->sizeline = 0;
	img->endian = 0;
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

void		ft_initst_02(t_cubed *st)
{
	st->worldmap = NULL;
	st->checkdouble = NULL;
	st->map = NULL;
	st->finalmap = NULL;
	st->mapfile = NULL;
	st->tmp = NULL;
	st->strcheck = NULL;
	st->newstr = NULL;
	st->i = 0;
	st->stepx = 0;
	st->stepy = 0;
	st->side = 0;
	st->start = 0;
	st->end = 0;
	st->ceilingcol = 0;
	st->floorcol = 0;
	st->count = 0;
	st->check = 0;
	st->tab = 0;
	st->sizetab = 0;
	st->longestline = 0;
	st->lenuntiln = 0;
	st->lenmax = 0;
	st->nbofline = 0;
	st->k = 0;
}

void		ft_initst_01(t_cubed *st)
{
	ft_initst_02(st);
	st->l = 0;
	st->esc_key = 0;
	st->w_key = 0;
	st->a_key = 0;
	st->s_key = 0;
	st->d_key = 0;
	st->left_key = 0;
	st->right_key = 0;
	st->posx = 0;
	st->posy = 0;
	st-> dirx = 0;
	st->diry = 0;
	st->planex = 0;
	st->planey = 0;
	st->movespeed = 0.25;
	st->rotspeed = 0.15;
	st->rgb->rgb.r = 0;
	st->rgb->rgb.g = 0;
	st->rgb->rgb.b = 0;
}

t_cubed     *ft_initstruct(void)
{
	t_cubed *st;

	if (!(st = malloc(sizeof(t_cubed) * 1)))
		return (NULL);
	if (!(st->rgb = malloc(sizeof(t_color) * 1)))
		return (NULL);
	st->firstsprite = NULL;
	ft_initst_01(st);
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