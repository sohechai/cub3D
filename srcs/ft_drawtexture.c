/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:56:39 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/04 20:28:29 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_calculnorth(t_cubed *st)
{
	if (st->side == 0 && st->stepy > 0)
	{
		if (st->side == 1)
			st->wallx = st->posy + st->perpwalldist * st->raydiry;
		else
			st->wallx = st->posx + st->perpwalldist * st->raydirx;
		st->wallx -= floor((st->wallx));
		st->textx = (int)(st->wallx * (double)st->nowidth);
		if (st->side == 0 && st->raydiry > 0)
			st->textx = st->nowidth - st->textx - 1;
		if (st->side == 1 && st->raydirx < 0)
			st->textx = st->nowidth - st->textx - 1;
		st->step = 1.0 * st->noheight / st->lineheight;
		st->textpos = (st->drawstart - st->h / 2 + st->lineheight / 2) * st->step;
	}
}

void		ft_calculsouth(t_cubed *st)
{
	if (st->side == 0 && st->stepy <= 0)
	{
		if (st->side == 1)
			st->wallx = st->posy + st->perpwalldist * st->raydiry;
		else
			st->wallx = st->posx + st->perpwalldist * st->raydirx;
		st->wallx -= floor((st->wallx));
		st->textx = (int)(st->wallx * (double)st->sowidth);
		if (st->side == 0 && st->raydiry > 0)
			st->textx = st->sowidth - st->textx - 1;
		if (st->side == 1 && st->raydirx < 0)
			st->textx = st->sowidth - st->textx - 1;
		st->step = 1.0 * st->soheight / st->lineheight;
		st->textpos = (st->drawstart - st->h / 2 + st->lineheight / 2) * st->step;
	}
}

void		ft_calculeast(t_cubed *st)
{
	if (st->side == 1 && st->stepx < 0)
	{
		if (st->side == 1)
			st->wallx = st->posy + st->perpwalldist * st->raydiry;
		else
			st->wallx = st->posx + st->perpwalldist * st->raydirx;
		st->wallx -= floor((st->wallx));
		st->textx = (int)(st->wallx * (double)st->eawidth);
		if (st->side == 0 && st->raydiry > 0)
			st->textx = st->eawidth - st->textx - 1;
		if (st->side == 1 && st->raydirx < 0)
			st->textx = st->eawidth - st->textx - 1;
		st->step = 1.0 * st->eaheight / st->lineheight;
		st->textpos = (st->drawstart - st->h / 2 + st->lineheight / 2) * st->step;
	}
}

void		ft_calculwest(t_cubed *st)
{
	if (st->side == 1 && st->stepx >= 0)
	{
		if (st->side == 1)
			st->wallx = st->posy + st->perpwalldist * st->raydiry;
		else
			st->wallx = st->posx + st->perpwalldist * st->raydirx;
		st->wallx -= floor((st->wallx));
		st->textx = (int)(st->wallx * (double)st->wewidth);
		if (st->side == 0 && st->raydiry > 0)
			st->textx = st->wewidth - st->textx - 1;
		if (st->side == 1 && st->raydirx > 0)
			st->textx = st->wewidth - st->textx - 1;
		st->step = 1.0 * st->weheight / st->lineheight;
		st->textpos = (st->drawstart - st->h / 2 + st->lineheight / 2) * st->step;
	}
}

void		ft_calcultexture(t_cubed *st)
{
	ft_calculnorth(st);
	ft_calculsouth(st);
	ft_calculeast(st);
	ft_calculwest(st);
}