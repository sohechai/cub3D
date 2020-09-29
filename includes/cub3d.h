/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:59 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/09/29 00:31:01 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUF_SIZE 1000
# define HEIGHT 500
# define WIDTH 700
# define MAPH 10
# define MAPW 10
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef	union	u_color
{
	int			color;
	t_rgb		rgb;
}				t_color;

typedef struct	s_path
{
	char			*texno;
	char			*texso;
	char			*texea;
	char			*texwe;
	char			*texsprite;
}				t_path;

typedef struct	s_cubed
{
	t_color			colo[1];
	t_path			path[1];
	char			**worldmap;
	char			*mapfile;
	char			*tmp;
	char			*strcheck;
	char			*newstr;
	char			**checkdouble;

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
	int				i;
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

	int				start;
	int				end;
	int				width;
	int				height;
	int				ceilingcol;
	int				floorcol;
	int				count;
	int				check;
	int				*tab;
	int				sizetab;
	int				linenumber;
	int				longestline;
	int				lenuntiln;
	int				lenmax;
	int				nbofline;
	int				k;
	int				l;

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

char		*ft_searchtexture(const char *s1, const char *s2, t_cubed *st);
char		*ft_searchtextureEOL(const char *s1, const char *s2, t_cubed *st);
char		*ft_searchdotcub(const char *s1, const char *s2);

int			main(int argc, char **argv);
int     	ft_openwindow();
int			ft_savecub(t_cubed *st, char *filemap);
int			ft_atoiwithst(const char *str, t_cubed *st);
int			ft_saveNO(t_cubed *st);
int			ft_saveSO(t_cubed *st);
int			ft_saveEA(t_cubed *st);
int			ft_saveWE(t_cubed *st);
int			ft_savesprite(t_cubed *st);
int   		ft_save_ceilingcolor(t_cubed *st);
int   		ft_save_floorcolor(t_cubed *stk);
int	    	ft_saveres(t_cubed *st);
int			ft_reserror(t_cubed *st);
int			ft_savetexture(t_cubed *st);
int			ft_savecolor(t_cubed *st);
int   		ft_checkdouble(t_cubed *st);
int    		ft_gotomap(t_cubed *st);
int			ft_checktabcase(t_cubed *st);
int			ft_checkmaperror(t_cubed *st);
int			ft_maperror(t_cubed *st);
int			ft_putxonmap(t_cubed *st, char *str);
int			ft_checkmapcar(t_cubed *st);

void		ft_color(t_cubed *st);
void        ft_setdata(t_cubed *st);
void        ft_draw(t_cubed *st);
void    	ft_check_map_file(char **argv, t_cubed *st);
void		ft_jumpspaces(t_cubed *st);
void    	ft_errorpathNO(t_cubed *st);
void    	ft_errorpathSO(t_cubed *st);
void    	ft_errorpathEA(t_cubed *st);
void    	ft_errorpathWE(t_cubed *st);
void    	ft_errorpathsprite(t_cubed *st);
void		ft_error_rgbceiling(t_cubed *st);
void		ft_error_rgbfloor(t_cubed *st);


#endif
