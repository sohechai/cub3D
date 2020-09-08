/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:43:00 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/03 23:32:17 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_errorpathsprite(t_cubed *st)
{
    ft_putstr("\033[31m- Wrong path to the sprite texture\033[00m\n\n");
    ft_putstr("Please follow this exemple :\n");
    ft_putstr("./path_to_the_sprite_texture.xpm\n\n");
    // free(st->path->texsprite);
}

void    ft_errorpathNO(t_cubed *st)
{
    ft_putstr("\033[31m- Wrong path to the north texture\033[00m\n\n");
    ft_putstr("Please follow this exemple :\n");
    ft_putstr("./path_to_the_north_texture.xpm\n\n");
    // free(st->path->texno);
}

void    ft_errorpathSO(t_cubed *st)
{
    ft_putstr("\033[31m- Wrong path to the south texture\033[00m\n\n");
    ft_putstr("Please follow this exemple :\n");
    ft_putstr("./path_to_the_south_texture.xpm\n");
    ft_putstr("... :\n\n");
    // free(st->path->texso);
}

void    ft_errorpathEA(t_cubed *st)
{
    ft_putstr("\033[31m- Wrong path to the east texture\033[00m\n\n");
    ft_putstr("Please follow this exemple :\n");
    ft_putstr("./path_to_the_east_texture.xpm\n\n");
    // free(st->path->texea);
}

void    ft_errorpathWE(t_cubed *st)
{
    ft_putstr("\033[31m- Wrong path to the west texture\033[00m\n\n");
    ft_putstr("Please follow this exemple :\n");
    ft_putstr("./path_to_the_west_texture.xpm\n\n");
    // free(st->path->texwe);
}