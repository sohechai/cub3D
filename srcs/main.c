/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/03 23:16:41 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     main(int argc, char **argv)
{
	t_cubed st[1];
	if (argc < 2)
		ft_putstr("\e[41mError\e[00m\n\n- Please add a map file\n");
	else if (argc == 2 && ft_searchdotcub(argv[1], ".cub") != NULL)
		ft_savecub(st, argv[1]);
	else
		ft_putstr("\e[41mError\e[00m\n\n- Map must end by '.cub'\n");
    //ft_openwindow(st);
    return (0);
}
