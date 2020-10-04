/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:59 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/04 20:29:51 by sofiahechai      ###   ########lyon.fr   */
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

typedef struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

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
	t_sprite		sprite[1];
	char			**worldmap;
	char			**checkdouble;
	char			**map;
	char			*finalmap;
	char			*mapfile;
	char			*tmp;
	char			*strcheck;
	char			*newstr;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx;
	void			*win;
	void			*img_ptr;

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
	int				*spriteorder;
	int				sl;
	int				nsprite;
	int				screenshot;

	int				colori;
	int				colorsky;
	int				colorfloor;

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

	int				drawstarty;
	int				drawstartx;
	int				drawendx;
	int				drawendy;
	int				spritescreenx;
	int				spriteh;
	int				spritew;
	int				textx;
	int				texty;

	void			*imgsp;
	int				*imgspd;
	int				spwidth;
	int				spheight;

	void			*imgno;
	int				*imgnod;
	int				nowidth;
	int				noheight;

	void			*imgso;
	int				*imgsouth;
	int				sowidth;
	int				soheight;

	void			*imgea;
	int				*imgead;
	int				eawidth;
	int				eaheight;

	void			*imgwe;
	int				*imgwed;
	int				wewidth;
	int				weheight;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
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
	double			invdet;
	double			transx;
	double			transy;

	double			spritex;
	double			spritey;

	double			wallx;
	double			step;
	double			textpos;
	double			*spdist;
	double			*zbuffer;

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
int			ft_draw(t_cubed *st);

void		ft_color(t_cubed *st);
void        ft_setdata(t_cubed *st);
void    	ft_check_map_file(char **argv, t_cubed *st);
void		ft_jumpspaces(t_cubed *st);
void    	ft_errorpathNO(t_cubed *st);
void    	ft_errorpathSO(t_cubed *st);
void    	ft_errorpathEA(t_cubed *st);
void    	ft_errorpathWE(t_cubed *st);
void    	ft_errorpathsprite(t_cubed *st);
void		ft_error_rgbceiling(t_cubed *st);
void		ft_error_rgbfloor(t_cubed *st);
void		ft_calcultexture(t_cubed *st);
void		ft_calculsprite(t_cubed *st, int i);

#endif
