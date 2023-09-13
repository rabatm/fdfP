/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:38:15 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/13 13:45:49 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX1(a, b) (a > b ? a : b)

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
//	int	z;
//	int	z1;

//	z = data->z_matrix[(int)y][(int)x];
//	z1 = data->z_matrix[(int)y1][(int)x1];

	// Zoom

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// Color
	//data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	// Isometric
//	isometric(&x, &y, z, data);
//	isometric(&x1, &y1, z1, data);
	// Shift
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->m_height)
	{
		x = 0;
		while (x < data->m_width)
		{
			if (x < data->m_width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->m_height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
