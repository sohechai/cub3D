/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:57:03 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/04 20:23:29 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// TODO norme

void	ft_draw_sprite(t_cubed *st)
{
	int		i;

	while (st->drawstartx < st->drawendx && st->drawstartx < st->w)
	{
		i = st->drawstarty;
		st->textx = (int)(256 * (st->drawstartx -
		(-st->spritew / 2 + st->spritescreenx)) * st->spwidth / st->spritew) / 256;
		if (st->textx < 0)
            st->textx = 0;
        if (st->texty < 0)
            st->texty = 0;
		if (st->drawstartx < st->w && st->transy > 0 &&
		st->drawstartx > 0 && st->transy < st->zbuffer[st->drawstartx])
		{
			while (++i < st->drawendy && i < st->h)
			{
				st->d = i * 256 - st->h * 128 + st->spriteh * 128;
				st->texty = (int)((st->d * st->spheight) / st->spriteh) / 256;
				if (st->textx < 0)
                    st->textx = 0;
                if (st->texty < 0)
                    st->texty = 0;
				if (st->spwidth * st->texty + st->textx < st->spwidth * st->spheight)
					st->colori = st->imgspd[st->spwidth * st->texty + st->textx];
				if ((st->colori & 0xffffff) != 0 && st->w
				* st->h > i * st->w + st->drawstartx)
					st->imgdata[i * st->w + st->drawstartx] = st->colori;
			}
		}
		st->drawstartx++;
	}
}

void	ft_calculsortdist(t_cubed *st)
{
	int			i;
	int			j;
	int			tmp;
	double		tmp1;

	j = 0;
	i = -1;
	while (++i < st->nsprite)
	{
		j = i - 1;
		while (++j < st->nsprite)
		{
			if (st->spdist[i] < st->spdist[j])
			{
				tmp = st->spriteorder[i];
				st->spriteorder[i] = st->spriteorder[j];
				st->spriteorder[j] = tmp;
				tmp1 = st->spdist[i];
				st->spdist[i] = st->spdist[j];
				st->spdist[j] = tmp1;
				i = -1;
				j = st->nsprite;
			}
		}
	}
}

void	ft_calculspritedist(t_cubed *st)
{
	int		i;

	i = 0;
	while (i < st->nsprite)
	{
		st->spriteorder[i] = i;
		st->spdist[i] = ((st->posx - st->sprite[i].x) * (st->posx - st->sprite[i].x)
		+ (st->posy - st->sprite[i].y) * (st->posy - st->sprite[i].y));
		i++;
	}
	ft_calculsortdist(st);
}

void	ft_calculsprite(t_cubed *st, int i)
{
	ft_calculspritedist(st);
	st->spritex = st->sprite[st->spriteorder[i]].x - st->posx;
	st->spritey = st->sprite[st->spriteorder[i]].y - st->posy;
	st->invdet = 1.0 / (st->planex * st->diry - st->dirx * st->planey);
	st->transx = st->invdet * (st->diry * st->spritex - st->dirx * st->spritey);
	st->transy = st->invdet * (-st->planey * st->spritex + st->planex * st->spritey);
	st->spritescreenx = (int)((st->w / 2) * (1 + st->transx / st->transy));
	st->spriteh = abs((int)(st->h / st->transy));
	st->drawstarty = -st->spriteh / 2 + st->h / 2;
	if (st->drawstarty < 0)
		st->drawstarty = 0;
	st->drawendy = st->spriteh / 2 + st->h / 2;
	if (st->drawstarty >= st->h)
		st->drawstarty = st->h - 1;
	st->spritew = abs((int)(st->h / (st->transy)));
	st->drawstartx = -st->spritew / 2 + st->spritescreenx;
	if (st->drawstartx < 0)
		st->drawstartx = 0;
	st->drawendx = st->spritew / 2 + st->spritescreenx;
	if (st->drawendx >= st->w)
		st->drawendx = st->w - 1;
}