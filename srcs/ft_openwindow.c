/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openwindow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:46:08 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 19:45:20 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_keymanagement(t_cubed *st)
{
	if (st->a_key == 1)
		move_left(st);
	else if (st->s_key == 1)
		move_backward(st);
	else if (st->d_key == 1)
		move_right(st);
	else if (st->w_key == 1)
		move_forward(st);
	else if (st->left_key == 1)
		rotate_left(st);
	else if (st->right_key == 1)
		rotate_right(st);
	if (st->esc_key == 1)
		ft_exitgame(st);
}

static	int		ft_keyon(int keycode, t_cubed *st)
{
	if (keycode == 53) // ESC
		ft_exitgame(st);
	else if (keycode == 0) // A
		move_left(st);
	else if (keycode == 1) // S
		move_backward(st);
	else if (keycode == 2) // D
		move_right(st);
	else if (keycode == 13) // W
		move_forward(st);
	else if (keycode == 123) // left arr
		rotate_left(st);
	else if (keycode == 124) // right arr
		rotate_right(st);
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

int     ft_openwindow(t_cubed *st, t_window *window, t_img *img)
{
    if ((st->window->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((st->window->win_ptr = mlx_new_window(st->window->mlx_ptr, st->window->width, st->window->height, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	ft_settextures(st);
	if ((st->img->img_ptr = mlx_new_image(st->window->mlx_ptr, st->window->width, st->window->height)) == NULL)
		return (EXIT_FAILURE);
	st->img->img_data = (int *)mlx_get_data_addr(st->img->img_ptr,
	&st->img->bpp, &st->img->sizeline, &st->img->endian);
    // st->img->img_data = mlx_get_data_addr(st->img->img_ptr,
	// 	&(st->img->bpp), &(st->img->sizeline), &(st->img->endian));
	ft_draw(st, st->window, st->ray, img);
	// TODO revoir en dessous
	mlx_hook(st->window->win_ptr, 2, 0, ft_keyon, st);
	// mlx_hook(st->window->win_ptr, 3, 1, ft_keyoff, st);
	mlx_hook(st->window->win_ptr, 17, 0, ft_destroywindow, st);
	// mlx_loop_hook(st->window->mlx_ptr, main_loop, st);
	mlx_loop(st->window->mlx_ptr);
	return (1);
}

