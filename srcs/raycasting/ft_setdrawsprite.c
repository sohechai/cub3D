/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setdrawsprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:37:47 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:46:50 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_putspritetexture(t_cubed *st, t_sprites *sprite)
{
	int	index;
	int index_sprite;

	index = sprite->y * st->img->sizeline
	+ sprite->x * st->img->bpp / 8;
	index_sprite = sprite->texty * st->sprit->sizeline + sprite->textx
	* st->sprit->bpp / 8;
	st->img->img_data[index] = st->sprit->img_data[index_sprite];
	st->img->img_data[index + 1] =
	st->sprit->img_data[index_sprite + 1];
	st->img->img_data[index + 2] =
	st->sprit->img_data[index_sprite + 2];
}

void		ft_putsprite1(t_cubed *st, t_window *window, t_sprites *sprite)
{
	size_t	d;
	int		color;
	int		index;

	d = sprite->y * st->sprit->sizeline - window->height
	* st->sprit->sizeline / 2 + sprite->spriteheight
	* st->sprit->sizeline / 2;
	sprite->texty = (int)(d * st->sprit->height / sprite->spriteheight
	/ st->sprit->sizeline);
	index = sprite->texty * st->sprit->sizeline
	+ sprite->textx * st->sprit->bpp / 8;
	color = st->sprit->img_data[index]
	+ st->sprit->img_data[index + 1]
	+ st->sprit->img_data[index + 2];
	if (color != 0)
		ft_putspritetexture(st, sprite);
}

void		ft_putsprite(t_cubed *st, t_sprites *now,
						t_window *window, t_ray *ray)
{
	now->x = now->drawstart_x;
	while (now->x < now->drawend_x)
	{
		if (now->transformy > 0 && now->transformy < ray->z_buffer[now->x])
		{
			now->y = now->drawstart_y;
			now->textx = (int)(st->sprit->sizeline * (now->x -
					(-now->spritewidth / 2 + now->spritescreenx)) *
					st->sprit->width / now->spritewidth) / st->sprit->sizeline;
			while (now->y < now->drawend_y)
			{
				ft_putsprite1(st, window, now);
				now->y++;
			}
		}
		now->x++;
	}
}

void		ft_sizesprite(t_sprites *now, t_window *window)
{
	now->spriteheight = abs((int)(window->height / now->transformy));
	now->drawstart_y = -now->spriteheight / 2 + window->height / 2;
	if (now->drawstart_y < 0)
		now->drawstart_y = 0;
	now->drawend_y = now->spriteheight / 2 + window->height / 2;
	if (now->drawend_y >= window->height)
		now->drawend_y = window->height - 1;
	now->spritewidth = abs((int)(window->height / now->transformy));
	now->drawstart_x = -now->spritewidth / 2
	+ now->spritescreenx;
	if (now->drawstart_x < 0)
		now->drawstart_x = 0;
	now->drawend_x = now->spritewidth / 2 + now->spritescreenx;
	if (now->drawend_x >= window->width)
		now->drawend_x = window->width - 1;
}

void		ft_setsprite(t_cubed *st, t_window *window, t_sprites *now)
{
	now->spritex = now->sprite->x - (st->posx - 0.5);
	now->spritey = now->sprite->y - (st->posy - 0.5);
	now->invdet = 1.0 / (st->planex * st->diry - st->planey * st->dirx);
	now->transformx = now->invdet *
						(st->diry * now->spritex - st->dirx * now->spritey);
	now->transformy = now->invdet *
						(st->planex * now->spritey - st->planey * now->spritex);
	now->spritescreenx = (int)((window->width / 2) *
						(1 + now->transformx / now->transformy));
}
