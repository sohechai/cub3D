/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openwindow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:46:08 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_key(int keycode, t_cubed *st)
{
	if (keycode == 65307)
		ft_exitgame(st);
	else if (keycode == 97)
		move_left(st);
	else if (keycode == 115)
		move_backward(st);
	else if (keycode == 100)
		move_right(st);
	else if (keycode == 119)
		move_forward(st);
	else if (keycode == 65361)
		rotate_left(st);
	else if (keycode == 65363)
		rotate_right(st);
	return (1);
}

int				ft_openwindow(t_cubed *st, t_window *window, t_img *img)
{
	if ((st->window->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((st->window->win_ptr = mlx_new_window(st->window->mlx_ptr,
		st->window->width, st->window->height, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	ft_settextures(st);
	if ((st->img->img_ptr = mlx_new_image(st->window->mlx_ptr,
		st->window->width, st->window->height)) == NULL)
		return (EXIT_FAILURE);
	st->img->img_data = (int *)mlx_get_data_addr(st->img->img_ptr,
	&st->img->bpp, &st->img->sizeline, &st->img->endian);
	ft_draw(st, st->window, st->ray, img);
	mlx_hook(st->window->win_ptr, 2, 1L << 0, ft_key, st);
	mlx_hook(st->window->win_ptr, 17, 1L << 17, ft_destroywindow, st);
	mlx_loop(st->window->mlx_ptr);
	return (1);
}
