/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 20:33:09 by sofiahechai      ###   ########lyon.fr   */
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
	if (argc < 2 || argc > 3)
	{
		st->check = 1;
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- Please add a map file\n");
		exit (EXIT_FAILURE);
	}
	else if (argc == 2 && ft_searchdotcub(argv[1], ".cub") != NULL)
	{
		dprintf(1, "coucou1\n");
		ft_savecub(st, argv[1]);
	}
	else if (argc == 2 && ft_searchdotcub(argv[1], ".cub") == NULL)
	{
		st->check = 1;
		printf("coucou2\n");
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- Map must end by '.cub'\n");
		exit (EXIT_FAILURE);
	}
	// else if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0 &&
	// 		ft_searchdotcub(argv[1], ".cub") != NULL)
	// {
	// 	//ft_savecub(st, argv[1]);
	// 	printf("save file\n");
	// 	exit (EXIT_FAILURE);
	// }
	else
	{
		st->check = 1;
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- 3rd argument must be --save'");
		ft_putstr("to make a screen of the game");
		exit (EXIT_FAILURE);
	}
	if (st->check == 0)
    {
		printf("%d\n", ft_strncmp(argv[2], "--save", 6));
		ft_openwindow(st, st->window, st->img);
	}
    return (EXIT_SUCCESS);
}
