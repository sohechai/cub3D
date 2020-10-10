/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openwindow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:46:08 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/11 01:26:09 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_keyclose(int keycode, t_cubed *st)
{
	if (keycode == 53)
	{
		ft_exitgame(st);
	}
	return (1);
}

// int				close_win(t_cubed *st)
// {
// 	mlx_destroy_window(st->mlx, st->win);
// 	ft_putstr("Exiting");
// 	return (0);
// }

// int				ft_close(t_cubed *st)
// {
// 	exit(1);
// }

int     ft_openwindow(t_cubed *st)
{
    if ((st->window->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((st->window->win_ptr = mlx_new_window(st->window->mlx_ptr, st->window->width, st->window->height, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	ft_settextures(st);
	ft_draw(st, st->window, st->ray);
	if ((st->img->img_ptr = mlx_new_image(st->window->mlx_ptr, st->window->width, st->window->height)) == NULL)
		return (EXIT_FAILURE);
    st->img->img_data = mlx_get_data_addr(st->img->img_ptr,
		&(st->img->bpp), &(st->img->sizeline), &(st->img->endian));
	// TODO revoir en dessous
	mlx_hook(st->window->win_ptr, 2, 0, ft_keyclose, st);
	// mlx_hook(st->window->win_ptr, KEY_RELEASE, 1L << 1, key_release, game);
	mlx_hook(st->window->win_ptr, 17, 0, ft_destroywindow, st);
	mlx_loop_hook(st->window->mlx_ptr, main_loop, st);
	mlx_loop(st->window->mlx_ptr);
	return (1);
}