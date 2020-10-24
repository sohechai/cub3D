/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:49:40 by sofiahechai       #+#    #+#             */
/*   Updated: 2020/10/24 20:59:12 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_file(t_img *img, int fd)
{
	int	file_size;
	int	pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset + img->width * img->height * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

void	ft_image(t_cubed *st, t_img *img, int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = st->window->width * st->window->height;
	write(fd, &header_size, 4);
	write(fd, &st->window->width, 4);
	write(fd, &st->window->height, 4);
	write(fd, &plane, 2);
	write(fd, &img->bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	ft_bitmaponimage(t_cubed *st, t_img *img, int fd)
{
	int	x;
	int y;
	int	r;
	int	g;
	int	b;

	y = st->window->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < st->window->width)
		{
			r = img->img_data[y * img->sizeline + x * img->bpp / 8];
			g = img->img_data[y * img->sizeline + x * img->bpp / 8 + 1];
			b = img->img_data[y * img->sizeline + x * img->bpp / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
}

void		ft_saveimage(t_cubed *st)
{
	int	fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR)) < 0)
	{
        ft_putstr("\e[41mError\e[00m\n\n");
		ft_putstr("- Impossible to create the bitmap file\n\n");
        ft_exitgame(st);
    }
	ft_file(st->img, fd);
	ft_image(st, st->img, fd);
	ft_bitmaponimage(st, st->img, fd);
	close(fd);
}