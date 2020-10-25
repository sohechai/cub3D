/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:32:13 by sohechai          #+#    #+#             */
/*   Updated: 2020/10/24 22:33:28 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_draw1(t_cubed *st, t_window *window, t_ray *ray)
{
	ray->camerax = 2 * ray->x / (double)st->window->width - 1;
	ray->raydirx = st->dirx + st->planex * ray->camerax;
	ray->raydiry = st->diry + st->planey * ray->camerax;
	if (ray->raydiry == 0)
		ray->deltadistx = 0;
	else if (ray->raydirx == 0)
		ray->deltadistx = 1;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (ray->raydirx == 0)
		ray->deltadisty = 0;
	else if (ray->raydiry == 0)
		ray->deltadisty = 1;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
	ray->mapx = (int)st->posx;
	ray->mapy = (int)st->posy;
	ray->lineheight = 0;
	ray->y = 0;
}

void		ft_draw2(t_cubed *st, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (st->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - st->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (st->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - st->posy) * ray->deltadisty;
	}
	ray->hit = 0;
}

void		ft_draw3(t_cubed *st, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->stepx == -1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->stepy == -1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (st->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
		else if (st->map[ray->mapy][ray->mapx] == '2')
			ft_createnewsprite(st, ray);
	}
}

void		ft_draw4(t_cubed *st, t_ray *ray, t_window *window, t_img *img)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = (ray->mapx - st->posx +
		(1 - ray->stepx) / 2) / ray->raydirx;
	else if (ray->side == 2 || ray->side == 3)
		ray->perpwalldist = (ray->mapy - st->posy +
		(1 - ray->stepy) / 2) / ray->raydiry;
	ray->lineheight = (int)(window->height / ray->perpwalldist);
	ray->z_buffer[ray->x] = ray->perpwalldist;
	ray->drawstart = -ray->lineheight / 2 + window->height / 2;
	ray->drawend = ray->lineheight / 2 + window->height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= window->height)
		ray->drawend = window->height - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wallx = st->posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = st->posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx);
	ft_calcultexture(st, ray);
	ft_setcolor(st, ray, img);
}

int			ft_draw(t_cubed *st, t_window *window, t_ray ray, t_img *img)
{
	ray.x = 0;
	if (!(ray.z_buffer = (double *)malloc(sizeof(double) * window->width)))
	{
		ft_clearstruct(st);
		ft_putstr("Error\n\n- Impossible to allocate memory for the z_buffer");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ray.z_buffer, sizeof(double) * window->width);
	while (ray.x < st->window->width)
	{
		ft_raycasting(st, window, &ray, img);
		ray.x++;
	}
	if (st->firstsprite != NULL)
		ft_drawsprite(st, window, &ray);
	free(ray.z_buffer);
	if (st->screen == 1)
	{
		ft_saveimage(st);
		ft_exitgame(st);
	}
	else
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		st->img->img_ptr, 0, 0);
	return (1);
}
