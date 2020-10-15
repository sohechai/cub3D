/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculsprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:14:38 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/16 00:04:28 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	sorted_insert(t_sprites **firsts, t_sprites *newone)
{
	t_sprites *now;

	if ((*firsts) == NULL || (*firsts)->distance <= newone->distance)
	{
		newone->next = (*firsts);
		(*firsts) = newone;
	}
	else
	{
		now = (*firsts);
		while (now->next != NULL && now->next->distance >= newone->distance)
		{
			now = now->next;
		}
		newone->next = now->next;
		now->next = newone;
	}
}

void		ft_createnewsprite(t_cubed *st, t_ray *ray)
{
	t_sprite	*new;
	t_sprites	*new_sprite;
	t_sprites	*now;
	double		distance;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return ;
	new->x = ray->mapx;
	new->y = ray->mapy;
	now = st->firstsprite;
	while (now != NULL)
	{
		if (now->sprite->x == new->x && now->sprite->y == new->y)
		{
			free(new);
			return ;
		}
		now = now->next;
	}
	distance = (st->posx - new->x) * (st->posx - new->x) + (st->posy - new->y) * (st->posy - new->y);
	new_sprite = ft_initsprites(new, distance);
	sorted_insert(&(st->firstsprite), new_sprite);
}