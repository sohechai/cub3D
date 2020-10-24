/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playermouv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:20:49 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/17 23:51:32 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		move_forward(t_cubed *st)
{
	if (st->map[(int)(st->posy + st->diry * st->movespeed)]
		[(int)(st->posx + st->dirx * st->movespeed)] == '1' ||
		st->map[(int)(st->posy + st->diry * st->movespeed)]
		[(int)(st->posx + st->dirx * st->movespeed)] == '2')
		return (1);
	st->posy += st->diry * st->movespeed;
	st->posx += st->dirx * st->movespeed;
	ft_draw(st, st->window, st->ray, st->img);
	return (1);
}

int		move_backward(t_cubed *st)
{
	if (st->map[(int)(st->posy - st->diry * st->movespeed)]
		[(int)(st->posx - st->dirx * st->movespeed)] == '1' ||
		st->map[(int)(st->posy - st->diry * st->movespeed)]
		[(int)(st->posx - st->dirx * st->movespeed)] == '2')
		return (1);
	st->posy -= st->diry * st->movespeed;
	st->posx -= st->dirx * st->movespeed;
	ft_draw(st, st->window, st->ray, st->img);
	return (1);
}

int		move_right(t_cubed *st)
{
	if (st->map[(int)(st->posy + st->planey * st->movespeed)]
		[(int)(st->posx + st->planex * st->movespeed)] == '1' ||
		st->map[(int)(st->posy + st->planey * st->movespeed)]
		[(int)(st->posx + st->planex * st->movespeed)] == '2')
		return (1);
	st->posy += st->planey * st->movespeed;
	st->posx += st->planex * st->movespeed;
	ft_draw(st, st->window, st->ray, st->img);
	return (1);
}

int		move_left(t_cubed *st)
{
	if (st->map[(int)(st->posy - st->planey * st->movespeed)]
		[(int)(st->posx - st->planex * st->movespeed)] == '1' ||
		st->map[(int)(st->posy - st->planey * st->movespeed)]
		[(int)(st->posx - st->planex * st->movespeed)] == '2')
		return (1);
	st->posy -= st->planey * st->movespeed;
	st->posx -= st->planex * st->movespeed;
	ft_draw(st, st->window, st->ray, st->img);
	return (1);
}
