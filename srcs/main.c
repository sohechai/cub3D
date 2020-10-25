/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_sortmain(int argc, char **argv, t_cubed *st)
{
	if (argc == 2 && ft_searchdotcub(argv[1], ".cub") != NULL)
		ft_savecub(st, argv[1]);
	else if (argc == 2 && ft_searchdotcub(argv[1], ".cub") == NULL)
	{
		st->check = 1;
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- Map must end by '.cub'\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 3 && ft_searchdotcub(argv[1], ".cub") != NULL &&
			ft_strncmp(argv[2], "--save", 6) == 0)
	{
		ft_savecub(st, argv[1]);
		st->screen = 1;
	}
	else
	{
		st->check = 1;
		ft_clearstruct(st);
		ft_putstr("\e[41mError\e[00m\n\n- 3rd argument must be '--save'");
		ft_putstr("to make a screenshot of the game\n\n");
		exit(EXIT_FAILURE);
	}
}

int			main(int argc, char **argv)
{
	t_cubed		*st;

	if (!(st = ft_initstruct()))
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
		exit(EXIT_FAILURE);
	}
	ft_sortmain(argc, argv, st);
	if (st->check == 0)
		ft_openwindow(st, st->window, st->img);
	return (EXIT_SUCCESS);
}
