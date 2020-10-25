/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstruct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:27:24 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:52:10 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_sprites	*ft_initsprites(t_sprite *sprite, double distance)
{
	t_sprites	*sprites;

	if (!(sprites = (t_sprites *)malloc(sizeof(t_sprites))))
		return (NULL);
	sprites->sprite = sprite;
	sprites->distance = distance;
	sprites->next = NULL;
	sprites->drawstart_x = 0;
	sprites->drawstart_y = 0;
	sprites->drawend_x = 0;
	sprites->drawend_y = 0;
	sprites->spritex = 0;
	sprites->spritey = 0;
	sprites->invdet = 0;
	sprites->transformx = 0;
	sprites->transformy = 0;
	sprites->spritescreenx = 0;
	sprites->spriteheight = 0;
	sprites->spritewidth = 0;
	sprites->x = 0;
	sprites->y = 0;
	sprites->textx = 0;
	sprites->texty = 0;
	return (sprites);
}
