/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:32:13 by sohechai          #+#    #+#             */
/*   Updated: 2020/08/21 18:45:47 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void        ft_draw1(t_cubed *st)
{
    st->camerax = 2 * st->x / (double)st->w - 1;
	st->rayposx = st->posx;
	st->rayposy = st->posy;
	st->raydirx = st->dirx + st->planex * st->camerax;
	st->raydiry = st->diry + st->planey * st->camerax;
	st->mapx = (int)st->rayposx;
	st->mapy = (int)st->rayposy;
	st->deltadistx = sqrt(1 + (st->raydiry * st->raydiry) / (st->raydirx * st->raydirx));
	st->deltadisty = sqrt(1 + (st->raydirx * st->raydirx) / (st->raydiry * st->raydiry));
	st->hit = 0;
}

void        ft_draw2(t_cubed *st)
{
    if (st->raydirx < 0)
	{
		st->stepx = -1;
		st->sidedistx = (st->rayposx - st->mapx) * st->deltadistx;
	}
	else
	{
		st->stepx = 1;
		st->sidedistx = (st->mapx + 1.0 - st->rayposx) * st->deltadistx;
	}
	if (st->raydiry < 0)
	{
		st->stepy = -1;
		st->sidedisty = (st->rayposy - st->mapy) * st->deltadisty;
	}
	else
	{
		st->stepy = 1;
		st->sidedisty = (st->mapy + 1.0 - st->rayposy) * st->deltadisty;
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
		if (st->worldmap[st->mapx][st->mapy] == '1') //modification == de 1 au lieu de != 0
			st->hit = 1;
		// if (st->worldmap[st->mapx][st->mapy] == '0') // TODO sprite ?
		// {
		// 	st->spy = st->mapy;
		// 	st->spx = st->mapx;
		// }
	}
		if (st->side == 1)
			st->perpwalldist = (st->mapx - st->rayposx + (1 - st->stepx) / 2) / st->raydirx;
		else
			st->perpwalldist = (st->mapy - st->rayposy + (1 - st->stepy) / 2) / st->raydiry;
		st->lineheight = (int)(st->h / st->perpwalldist);
		st->drawstart = -st->lineheight / 2 + st->h / 2;
}

// void        ft_draw5(t_cubed *st, int i)
// {
// 	if (st->side == 0)
// 		st->texy = st->stepy > 0 ? ((int)st->texpos & st->noheight - 1) :
// 		((int)st->texpos & st->suheight - 1);
// 	else if (st->side == 1)
// 		st->texy = st->stepx < 0 ? ((int)st->texpos & st->eaheight - 1) :
// 		((int)st->texpos & st->weheight - 1);
// 	if (st->side == 0)
// 		st->colori = st->stepy > 0 ? st->imgnod[st->noheight * st->texy +
// 		st->texx] : st->imgsud[st->suheight * st->texy + st->texx];
// 	else if (st->side == 1)
// 		st->colori = st->stepx < 0 ? st->imgead[st->eaheight * st->texy +
// 		st->texx] : st->imgwed[st->weheight * st->texy + st->texx];
// 	st->texpos += st->step;
// }

void        ft_draw4(t_cubed *st, int i)
{
	//g->drawstart = -(g->lineheight) / 2 + g->h / 2;
	if (st->drawstart < 0)
		st->drawstart = 0;
	st->drawend = st->lineheight / 2 + st->h / 2;
	if (st->drawend >= st->h)
		st->drawend = st->h - 1;
	// a partir d'ici revoir setup couleur
	ft_color(st);
	while (st->drawstart <= st->drawend)
	{
		//ft_draw5(st);
		st->imgdata[st->drawstart++ * st->w + i] = st->color;
	}
	// if (st->side == 1)
	// 	st->color = st->color / 2;
	// novatempus(st, st->x);
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

void        ft_draw(t_cubed *st)
{
	int		i;

	i = -1;
	ft_setdata(st);
    while (++i < st->w)
	{
		ft_draw1(st);
		ft_draw2(st);
		ft_draw3(st);
		ft_draw4(st, i);
	}
}

