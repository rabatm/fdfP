/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:18:10 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:21 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define    ERR_ARG "Erreur : nombre d'arguments incorrect ! usage : ./fdf <mapfile>.fdf"
# define    ERR_FILE "Erreur : fichier incorrect ! usage : ./fdf <mapfile>.fdf"
# define    WIN_H   1080
# define    WIN_W   1920
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/libft/libft.h"
# include "../includes/mlx.h"
# include "./minilibx_linux/mlx_int.h"

typedef struct s_fdf	t_fdf;
typedef struct s_pt		t_pt;

typedef struct s_fdf
{
	char	*map;
    int	m_width;
    int	m_height;
    int	zoom;
    int	shift_x;
    int	shift_y;
    void    *mlx_ptr;
    void    *win_ptr;
	void	*image;
    t_pt	**z_matrix;
}   t_fdf;

typedef struct s_pt
{
	int	z;
	int	color;
}	t_pt;

void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
t_fdf   *ft_init_struct(char *map_file_name);
void	ft_get_map(t_fdf *data, char *mapfile);
int		handle_inputs(int key, t_fdf *data);
void	print_matrix(t_fdf *data);

#endif
