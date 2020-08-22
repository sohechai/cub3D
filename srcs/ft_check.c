/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 21:53:48 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/21 22:27:31 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_check_map_file(char **argv, t_cubed *st)
{
    int     i;

    i = 0;
    while(argv[1][i] != '.' && argv[1][i] != '\0')
        i++;
    if (ft_strncmp(argv[1] + i, ".cub", 4) != 0)
        ft_putstr("Error - Please enter a valid file ending by '.cub'\n");
}