/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:32:13 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/04 20:31:04 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void        ft_draw1(t_cubed *st, int i)
{
    st->camerax = 2 * i / (double)st->w - 1;
	st->raydirx = st->dirx + st->planex * st->camerax;
	st->raydiry = st->diry + st->planey * st->camerax;
	st->mapx = (int)st->posx;
	st->mapy = (int)st->posy;
	st->deltadistx = sqrt((double)1 + (st->raydiry * st->raydiry) / (st->raydirx * st->raydirx));
	st->deltadisty = sqrt((double)1 + (st->raydirx * st->raydirx) / (st->raydiry * st->raydiry));
}

void        ft_draw2(t_cubed *st)
{
    if (st->raydirx < 0)
	{
		st->stepx = -1;
		st->sidedistx = (st->posx - st->mapx) * st->deltadistx;
	}
	else
	{
		st->stepx = 1;
		st->sidedistx = (st->mapx + 1.0 - st->posx) * st->deltadistx;
	}
	if (st->raydiry < 0)
	{
		st->stepy = -1;
		st->sidedisty = (st->posy - st->mapy) * st->deltadisty;
	}
	else
	{
		st->stepy = 1;
		st->sidedisty = (st->mapy + 1.0 - st->posy) * st->deltadisty;
	}
}

void        ft_draw3(t_cubed *st)
{
	st->hit = 0;
	st->side = 0;
	while (st->hit == 0)
	{
		if (st->sidedistx < st->sidedisty)
		{
			st->sidedistx += st->deltadistx;
			st->mapx += st->stepx;
			st->side = 1;
		}
		else
		{
			st->sidedisty += st->deltadisty;
			st->mapy += st->stepy;
			st->side = 0;
		}
		if (st->map[st->mapx][st->mapy] == '1')
			st->hit = 1;
		if (st->map[st->mapx][st->mapy] == '2')
		{
			st->spritex = st->mapx;
			st->spritey = st->mapy;
		}
	}
		if (st->side == 1)
			st->perpwalldist = (st->mapx - st->posx + (1 - st->stepx) / 2) / st->raydirx;
		else
			st->perpwalldist = (st->mapy - st->posy + (1 - st->stepy) / 2) / st->raydiry;
		st->lineheight = (int)(st->h / st->perpwalldist);
		st->drawstart = -st->lineheight / 2 + st->h / 2;
}

void        ft_draw4(t_cubed *st, int i)
{
	//g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (st->drawstart < 0)
		st->drawstart = 0;
	st->drawend = st->lineheight / 2 + st->h / 2;
	if (st->drawend >= st->h)
		st->drawend = st->h - 1;
	ft_calcultexture(st);
	while (st->drawstart <= st->drawend)
	{
		ft_draw(st);
		st->imgdata[st->drawstart++ * st->w + i] = st->colori;
	}
}

void        ft_setdata(t_cubed *st)
{
    st->posx = 6;
	st->posy = 8;
	st->dirx = -1;
	st->diry = 0;
	st->planex = 0;
	st->planey = 0.66;
	st->time = 0;
	st->oldtime = 0;
	st->w = 700;
	st->h = 500;
	st->upkey = 0;
	st->downkey = 0;
	st->leftkey = 0;
	st->rightkey = 0;
	st->rotspeed = .2;
	st->movespeed = .2;
}

void	ft_drawskyfloor(t_cubed *st)
{
	int		i;
	int		j;

	j = 0;
	while (j < st->h / 2)
	{
		i = -1;
		while (++i < st->w)
			st->imgdata[j * st->w + i] = st->colorsky;
		j++;
	}
	while (j < st->h)
	{
		i = -1;
		while (++i < st->w)
			st->imgdata[j * st->w + i] = st->colorfloor;
		j++;
	}
}

int        ft_draw(t_cubed *st)
{
	int		i;

	i = -1;
	ft_setdata(st);
	ft_drawskyfloor(st);
    while (++i < st->w)
	{
		ft_draw1(st, i);
		ft_draw2(st);
		ft_draw3(st);
		ft_draw4(st, i);
	}
	i = -1;
	while (++i < st->nsprite)
	{
		ft_calculsprite(st, i);
		ft_draw_sprite(st);
	}
	//TODO screenshot
	// if (st->screenshot == 1)
	// 	ft_save_bitmap("bitmap.bmp", st);
	mlx_put_image_to_window(st->mlx_ptr,
	st->win_ptr, st->img_ptr, 0, 0);
	return (1);
}

