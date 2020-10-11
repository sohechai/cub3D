/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/12 01:33:23 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main_loop(t_cubed *st, t_window *window, t_ray *ray)
{
	// key_manager(st);
	mlx_clear_window(st->window->mlx_ptr, st->window->win_ptr);
	ft_draw(st, window, *ray);
	return (0);
}

int     main(int argc, char **argv)
{
	t_cubed		*st;
	if (!(st = ft_initstruct()))
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Failed to allocate memory for structure\n");
		st->check = 1;
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n- Please add a map file\n");
	}
	else if (argc == 2 && ft_searchdotcub(argv[1], ".cub") != NULL)
		ft_savecub(st, argv[1]);
	else
	{
		st->check = 1;
		ft_putstr("\e[41mError\e[00m\n\n- Map must end by '.cub'\n");
	}
	if (st->check == 0)
    	ft_openwindow(st, st->window);
    return (EXIT_SUCCESS);
}
