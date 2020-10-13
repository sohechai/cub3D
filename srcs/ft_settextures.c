/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settextures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:20:27 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/13 00:26:42 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_cubed *st, t_img *texture)
{
	if (!(texture->img_ptr = mlx_xpm_file_to_image(st->window->mlx_ptr,
		texture->path, &texture->width, &texture->height)))
	{
		ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Failed loading texture\n");
		exit(EXIT_FAILURE);
	}
	texture->img_data =
		mlx_get_data_addr(texture->img_ptr, &(texture->bpp),
		&(texture->sizeline), &(texture->endian));
}

void		ft_settextures(t_cubed *st)
{
	set_texture(st, st->north);
	set_texture(st, st->south);
	set_texture(st, st->east);
	set_texture(st, st->west);
	// if (st->sp_texture->path)
		// set_texture(st, st->sprit);
}