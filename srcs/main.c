/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/15 23:17:38 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main_loop(t_cubed *st, t_window *window, t_ray *ray)
{
	ft_keymanagement(st);
	mlx_clear_window(st->window->mlx_ptr, st->window->win_ptr);
	ft_draw(st, window, *ray, st->img);
	return (0);
}

int     main(int argc, char **argv)
{
	t_cubed		*st;
	if(!(st = ft_initstruct()))
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Failed to allocate memory for structure\n");
		st->check = 1;
		exit(EXIT_FAILURE);
	}
	if (argc > 3 || argc < 2)
	{
		st->check = 1;
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- Please add a map file\n");
		exit (EXIT_FAILURE);
		return (0);
	}
	if (argc == 2 && ft_searchdotcub(argv[1], ".cub") != NULL)
		ft_savecub(st, argv[1]);
	else
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n- Map must end by '.cub'\n");
		return (0);
	}
	if (st->check == 0)
    	ft_openwindow(st, st->window, st->img);
    return (EXIT_SUCCESS);
}
