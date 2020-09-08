/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:09:20 by sohechai          #+#    #+#             */
/*   Updated: 2020/09/02 17:57:27 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// unsigned int	colormagic(int i, double x, double y)
// {
// 	unsigned int	color;
// 	double			magic;
// 	double			i2;
//     t_cubed         st;

// 	magic = sqrt(x * x + y * y);
// 	i2 = i + 1 - (log(2) / magic) / log(2);
// 	st.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
// 	st.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
// 	st.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
// 	color = (st.chan[0] << 16) + (st.chan[1] << 8) + (st.chan[2] + 255);
// 	return (color);
// }

// void			novatempus(t_cubed *st, int x)
// {
// 	int		initioy;
// 	int		mori;
// 	int		initio;

// 	mori = st->drawend;
// 	if (mori > HEIGHT)
// 		mori = HEIGHT - 1;
// 	initioy = st->drawstart;
// 	if (initioy < 0)
// 		initioy = 0;
// 	initio = -1;
// 	while (++initio < (HEIGHT / 2))
// 		st->imgpoke[x + (initio * st->sl / 4)] = 0xC00000AA;
// 	while (++initioy < mori)
// 		st->imgpoke[x + (initioy * st->sl / 4)] = colormagic(st->color, x, initioy);
// 	initio = mori - 1;
// 	while (++initio < (HEIGHT - 1))
// 		st->imgpoke[x + (initio * st->sl / 4)] = 0xC00000AA;
// }

void	ft_color(t_cubed *st)
{
	if (st->side == 1 && st->stepx < 0)
		st->color = 0x00FFFF;
	if (st->side == 1 && st->stepx >= 0)
		st->color = 0x0000FF;
	if (st->side == 0 && st->stepy <= 0)
		st->color = 0x9400D3;
	if (st->side == 0 && st->stepy > 0)
		st->color = 0xFF8C00;
}