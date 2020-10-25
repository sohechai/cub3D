/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:57:19 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:44:12 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_putpixel(t_img *img, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->img_data[y * img->sizeline + x * img->bpp / 8] = r;
	img->img_data[y * img->sizeline + x * img->bpp / 8 + 1] = g;
	img->img_data[y * img->sizeline + x * img->bpp / 8 + 2] = b;
}

void		ft_setcolor(t_cubed *st, t_ray *ray, t_img *img)
{
	int		x;

	x = 0;
	while (x < ray->drawstart)
	{
		ft_putpixel(st->img, ray->x, x, st->ceilingcol);
		x++;
	}
	x = ray->drawend + 1;
	while (x < st->window->height)
	{
		ft_putpixel(st->img, ray->x, x, st->floorcol);
		x++;
	}
}
