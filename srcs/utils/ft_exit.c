/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:48:09 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 22:49:42 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_exitgame(t_cubed *st)
{
	ft_clearstruct(st);
	exit(EXIT_SUCCESS);
}

int			ft_destroywindow(t_cubed *st, t_window *window)
{
	ft_exitgame(st);
	return (0);
}
