/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:32:41 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:44:26 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_raycasting(t_cubed *st, t_window *window, t_ray *ray, t_img *img)
{
	ft_draw1(st, window, ray);
	ft_draw2(st, ray);
	ft_draw3(st, ray);
	ft_draw4(st, ray, window, img);
}
