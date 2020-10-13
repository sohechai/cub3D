/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playerrotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:00:17 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/13 15:47:01 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_cubed *st)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = st->dirx;
	st->dirx = cos(-(st->rotspeed)) * st->dirx - sin(-(st->rotspeed)) * st->diry;
	st->diry = sin(-(st->rotspeed)) * old_dirx + cos(-(st->rotspeed)) * st->diry;
	old_planex = st->planex;
	st->planex = cos(-(st->rotspeed)) * st->planex - sin(-(st->rotspeed)) * st->planey;
	st->planey = sin(-(st->rotspeed)) * old_planex + cos(-(st->rotspeed)) * st->planey;
	ft_draw(st, st->window, st->ray, st->img);
}

void	rotate_right(t_cubed *st)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = st->dirx;
	st->dirx = cos(st->rotspeed) * st->dirx - sin(st->rotspeed) * st->diry;
	st->diry = sin(st->rotspeed) * old_dirx + cos(st->rotspeed) * st->diry;
	old_planex = st->planex;
	st->planex = cos(st->rotspeed) * st->planex - sin(st->rotspeed) * st->planey;
	st->planey = sin(st->rotspeed) * old_planex + cos(st->rotspeed) * st->planey;
	ft_draw(st, st->window, st->ray, st->img);
}