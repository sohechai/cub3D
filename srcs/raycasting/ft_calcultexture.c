/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcultexture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:46:53 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/13 15:57:43 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_settexture(t_cubed *st, t_img *texture, t_ray *ray)
{
	unsigned int	d;

	d = ray->y * texture->sizeline - st->window->height
		* texture->sizeline / 2 + ray->lineheight * texture->sizeline / 2;
	ray->texty = ((d * texture->height) / ray->lineheight)
		/ texture->sizeline;
	st->img->img_data[ray->y * st->img->sizeline
		+ ray->x * st->img->bpp / 8] =
		texture->img_data[ray->texty * texture->sizeline
		+ ray->textx * (texture->bpp / 8)];
	st->img->img_data[ray->y * st->img->sizeline
		+ ray->x * st->img->bpp / 8 + 1] =
		texture->img_data[ray->texty * texture->sizeline
		+ ray->textx * (texture->bpp / 8) + 1];
	st->img->img_data[ray->y * st->img->sizeline
		+ ray->x * st->img->bpp / 8 + 2] =
		texture->img_data[ray->texty * texture->sizeline
		+ ray->textx * (texture->bpp / 8) + 2];
	ray->y++;
}

void		ft_calcultexture(t_cubed *st, t_ray *ray)
{
	int		textx;
	t_img	*texture;

	texture = st->west;
	if (ray->side == 1)
		texture = st->east;
	else if (ray->side == 2)
		texture = st->north;
	else if (ray->side == 3)
		texture = st->south;
	textx = (int)(ray->wallx * (double)texture->width);
	if ((ray->side == 0 || ray->side == 1) && ray->raydirx > 0)
		textx = texture->width - textx - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->raydiry < 0)
		textx = texture->width - textx - 1;
	ray->textx = textx;
	ray->y = ray->drawstart;
	while (ray->y <= ray->drawend)
	{
		ft_settexture(st, texture, ray);
		// st->img->img_data[ray->drawstart++ * ray->x + ray->x] = st->img->colori;
	}
}
