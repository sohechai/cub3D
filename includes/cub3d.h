/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:12:59 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/13 16:07:59 by sofiahechai      ###   ########lyon.fr   */
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

typedef struct	s_ray
{
	int		x;
	int		y;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		textx;
	int		texty;

	double	camerax;
	double	perpwalldist;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	wallx;
	double	*z_buffer;

}				t_ray;

typedef struct	s_img
{
	void	*img_ptr;

	char	*img_data;
	char	*path;

	int		bpp;
	int		sizeline;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_window
{
	int		width;
	int		height;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_cubed
{
	t_color			*rgb;
	t_window		*window;
	t_ray			ray;

	t_img			*img;
	t_img			*north;
	t_img			*south;
	t_img			*east;
	t_img			*west;
	t_img			*sprit;

// parsing

	char			**worldmap;
	char			**checkdouble;
	char			**map;
	char			*finalmap;
	char			*mapfile;
	char			*tmp;
	char			*strcheck;
	char			*newstr;

	int				i;
	int				stepx;
	int				stepy;
	int				side;

// raycasting

	int				start;
	int				end;
	int				ceilingcol;
	int				floorcol;
	int				count;
	int				check;
	int				*tab;
	int				sizetab;
	int				longestline;
	int				lenuntiln;
	int				lenmax;
	int				nbofline;
	int				k;
	int				l;

// key

	int				esc_key;
	int				w_key;
	int				a_key;
	int				s_key;
	int				d_key;
	int				left_key;
	int				right_key;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			movespeed;
	double			rotspeed;

//a enlever et mettre dans ray

	double			spritex;
	double			spritey;
}				t_cubed;

t_cubed     *ft_initstruct(void);
t_img		*ft_initimg(void);
t_window	*ft_initwindow(void);

char		*ft_searchtexture(const char *s1, const char *s2, t_cubed *st);
char		*ft_searchtextureEOL(const char *s1, const char *s2, t_cubed *st);
char		*ft_searchdotcub(const char *s1, const char *s2);

static int	ft_key(int keycode, t_cubed *st);

int			main(int argc, char **argv);
int			main_loop(t_cubed *st, t_window *window, t_ray *ray);
int     	ft_openwindow(t_cubed *st, t_window *window, t_img *img);
int			ft_savecub(t_cubed *st, char *filemap);
int			ft_atoiwithst(const char *str, t_cubed *st);
int			ft_saveNO(t_cubed *st, t_img *texture);
int			ft_saveSO(t_cubed *st, t_img *texture);
int			ft_saveEA(t_cubed *st, t_img *texture);
int			ft_saveWE(t_cubed *st, t_img *texture);
int			ft_savesprite(t_cubed *st, t_img *texture);
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
int			ft_checkplayer(t_cubed *st);
int			ft_maperror(t_cubed *st);
int			ft_putxonmap(t_cubed *st, char *str);
int			ft_checkmapcar(t_cubed *st);
int			ft_draw(t_cubed *st, t_window *window, t_ray ray, t_img *img);
int			ft_destroywindow(t_cubed *st, t_window *window);

void		ft_exitgame(t_cubed *st);
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
void		ft_calculsprite(t_cubed *st, int i);
void		ft_calcultexture(t_cubed *st, t_ray *ray);
void        ft_setcolor(t_cubed *st, t_ray *ray, t_img *img);
void		ft_settextures(t_cubed *st);
void		ft_clearstruct(t_cubed *st);
void		key_manager(t_cubed *st);
int			move_forward(t_cubed *st);
int			move_backward(t_cubed *st);
int			move_right(t_cubed *st);
int			move_left(t_cubed *st);
void		rotate_left(t_cubed *st);
void		rotate_right(t_cubed *st);

#endif
