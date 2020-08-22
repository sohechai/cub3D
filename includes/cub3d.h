/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:59 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/08/21 22:00:18 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUF_SIZE 4096
# define HEIGHT 500
# define WIDTH 700
# define MAPH 10
# define MAPW 10
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_cubed
{
	char			*worldmap[MAPH];
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx;
	void			*win;
	void			*img;
	int				x;
	int				y;
	int				w;
	int				d;
	int				h;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	int				*imgdata;
	int				sl;
	int				upkey;
	int				downkey;
	int				leftkey;
	int				rightkey;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	double			time;
	double			oldtime;
	double			movespeed;
	double			rotspeed;
	unsigned char	chan[3];
}				t_cubed;

int     	ft_openwindow();
void		ft_color(t_cubed *st);
void        ft_setdata(t_cubed *st);
void        ft_draw(t_cubed *st);
void    	ft_check_map_file(char **argv, t_cubed *st);

#endif
