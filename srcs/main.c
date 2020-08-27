/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:06:33 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/27 23:01:26 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     main(int argc, char **argv)
{
	t_cubed st[1];
	ft_savecub(st);
	printf("%s\n", ft_substr("salutation skafj kadjg kdsjfgkljhsdfg", 10, 3));

	// if (argc < 2)
	// {
	// 	ft_putstr("Error - Please add a map ending by '.cub'\n");
	// 	return (0);
	// }
	// else if (argc == 2)
	// {
	// 	ft_check_map_file(argv, st);
	// }
    // ft_openwindow(st);
    return (0);
}
