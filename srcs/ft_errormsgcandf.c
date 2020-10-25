/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsgcandf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 00:07:37 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 23:27:39 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_error_rgbceiling(t_cubed *st)
{
	ft_putstr("\033[31m- Wrong data for rgb ceiling\033[00m\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("C 225,30,0\n\n");
}

void		ft_error_rgbfloor(t_cubed *st)
{
	ft_putstr("\033[31m- Wrong data for rgb floor\033[00m\n");
	ft_putstr("Please follow this exemple :\n");
	ft_putstr("F 220,100,0\n\n");
}
