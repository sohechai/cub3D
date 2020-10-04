/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openwindow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:46:08 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/04 20:26:11 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_keyclose(int keycode, t_cubed *st)
{
	if (keycode == 53)
	{
		mlx_destroy_window(st->mlx_ptr, st->win_ptr);
		mlx_destroy_image(st->mlx_ptr, st->img_ptr);
		exit(1);
	}
	return (1);
}

int				close_win(t_cubed *st)
{
	mlx_destroy_window(st->mlx, st->win);
	ft_putstr("Exiting");
	return (0);
}

int				ft_close(t_cubed *st)
{
	exit(1);
}

// int		vaultmovement(int key, t_cubed *st)
// {
// 	if (key == 126 || key == 13)
// 		st->upkey = 1;
// 	else if (key == 125 || key == 1)
// 		st->downkey = 1;
// 	else if (key == 123 || key == 0)
// 		st->leftkey = 1;
// 	else if (key == 124 || key == 2)
// 		st->rightkey = 1;
// 	keyhooks(key, st);
// 	return (0);
// }

// int		vaultmovementtoggle(int key, t_cubed *st)
// {
// 	if (key == 126 || key == 13)
// 		st->upkey = 0;
// 	else if (key == 125 || key == 1)
// 		st->downkey = 0;
// 	else if (key == 123 || key == 0)
// 		st->leftkey = 0;
// 	else if (key == 124 || key == 2)
// 		st->rightkey = 0;
// 	keyhooks(key, st);
// 	return (0);
// }

// int		repeat(t_cubed *st)
// {
// 	mlx_hook(st->win, 2, 0, vaultmovement, st);
// 	mlx_hook(st->win, 3, 0, vaultmovementtoggle, st);
// 	mlx_hook(st->win, 17, 0, close_win, st);
// 	return (0);
// }

int     ft_openwindow(t_cubed *st)
{
    if ((st->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((st->img_ptr = mlx_new_image(st->mlx_ptr, WIDTH, HEIGHT)) == NULL)
		return (EXIT_FAILURE);
    if ((st->win_ptr = mlx_new_window(st->mlx_ptr, WIDTH, HEIGHT, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	// ft_draw(st);
    // if (mlx_key_hook(st->win_ptr, ft_keyclose, &st))
    // if (mlx_hook(st->win_ptr, 17, 0, ft_close, &st))
    // mlx_loop(st->mlx_ptr);
	mlx_hook(st->win_ptr, 2, 0, ft_keyclose, st);
	mlx_hook(st->win_ptr, 17, 0, ft_close, st);
	mlx_loop(st->mlx_ptr);
	return (1);
}