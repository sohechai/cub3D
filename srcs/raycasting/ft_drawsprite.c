/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:38:43 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/16 00:06:41 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
// a copier dans ft_free

void	free_sprites(t_sprites **firsts)
{
	t_sprites *now;
	t_sprites *next;

	now = (*firsts);
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
	(*firsts) = NULL;
}

static void	texture_put(t_cubed *st, t_sprites *sprite)
{
	int	index;
	int index_sprite;

	printf("allo7\n");
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

void		sprite_put(t_cubed *st, t_window *window, t_sprites *sprite)
{
	int	d;
	int	color;
	int	index;

	printf("allo6\n");
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
		texture_put(st, sprite);
}

void		set_sprite_on_img(t_cubed *st, t_sprites *now,
			t_window *window, t_ray *ray)
{
	printf("allo2\n");
	now->x = now->drawstart_x;
	printf("%d et %d\n", now->x, now->drawend_x);
	while (now->x < now->drawend_x)
	{
		printf("allo3\n");
		if (now->transformy > 0 && now->transformy < ray->z_buffer[now->x])
		{
			printf("allo4\n");
			now->y = now->drawstart_y;
			now->textx = (int)(st->sprit->sizeline
			* (now->x - (-now->spritewidth / 2
			+ now->spritescreenx)) * st->sprit->width
			/ now->spritewidth) / st->sprit->sizeline;
			while (now->y < now->drawend_y)
			{
				printf("allo5\n");
				sprite_put(st, window, now);
				now->y++;
			}
		}
		now->x++;
	}
}

void		size_sprite(t_sprites *now, t_window *window)
{
	printf("allo1\n");
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

void		projection_sprite(t_cubed *st, t_window *window, t_sprites *now)
{
	now->spritex = now->sprite->x - (st->posx - 0.5);
	now->spritey = now->sprite->y - (st->posy - 0.5);
	now->invdet = 1.0 / (st->planex * st->diry - st->planey * st->dirx);
	now->transformx = now->invdet * (st->diry * now->spritex - st->dirx * now->spritey);
	now->transformy = now->invdet * (st->planex * now->spritey - st->planey * now->spritex);
	now->spritescreenx = (int)((window->width / 2) * (1 + now->transformx / now->transformy));
}

void		ft_drawsprite(t_cubed *st, t_window *window, t_ray *ray)
{
	t_sprites	*now;

	now = st->firstsprite;
	while (now != NULL)
	{
		printf("donnée = %d et %d\n", now->spritex, now->spritey);
		projection_sprite(window, now, st);
		size_sprite(now, window);
		set_sprite_on_img(st, now, window, ray);
		now = now->next;
	}
	free_sprites(&st->firstsprite);
}