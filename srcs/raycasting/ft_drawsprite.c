/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:38:43 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:40:49 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_drawsprite(t_cubed *st, t_window *window, t_ray *ray)
{
	t_sprites	*now;
	int			i;

	now = st->firstsprite;
	i = 0;
	while (now != NULL)
	{
		ft_setsprite(st, window, now);
		ft_sizesprite(now, window);
		ft_putsprite(st, now, window, ray);
		now = now->next;
	}
	ft_freesprites(&st->firstsprite);
}
