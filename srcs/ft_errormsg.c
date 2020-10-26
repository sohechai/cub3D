/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:43:00 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_errorpathsprite(t_cubed *st)
{
	ft_putstr("\e[41mError\e[00m\n\n");
	ft_putstr("Wrong path file :\n\n");
	ft_putstr("\033[31m- to the sprite texture\033[00m\n\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("S ./path_to_the_sprite_texture.xpm\n\n");
}

void	ft_errorpathno(t_cubed *st)
{
	ft_putstr("\e[41mError\e[00m\n\n");
	ft_putstr("Wrong path file :\n\n");
	ft_putstr("\033[31m- to the north texture\033[00m\n\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("NO ./path_to_the_north_texture.xpm\n\n");
}

void	ft_errorpathso(t_cubed *st)
{
	ft_putstr("\e[41mError\e[00m\n\n");
	ft_putstr("Wrong path file :\n\n");
	ft_putstr("\033[31m- to the south texture\033[00m\n\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("SO ./path_to_the_south_texture.xpm\n");
	ft_putstr("... :\n\n");
}

void	ft_errorpathea(t_cubed *st)
{
	ft_putstr("\e[41mError\e[00m\n\n");
	ft_putstr("Wrong path file :\n\n");
	ft_putstr("\033[31m- to the east texture\033[00m\n\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("EA ./path_to_the_east_texture.xpm\n\n");
}

void	ft_errorpathwe(t_cubed *st)
{
	ft_putstr("\e[41mError\e[00m\n\n");
	ft_putstr("Wrong path file :\n\n");
	ft_putstr("\033[31m- to the west texture\033[00m\n\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("WE ./path_to_the_west_texture.xpm\n\n");
}
