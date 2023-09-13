#include "../includes/fdf.h"

void ft_zerostruc(t_fdf *data)
{
    data->m_width = 0;
    data->m_height = 0;
    data->zoom = 0;
    data->shift_x = 0;
    data->shift_y = 0;
	data->map = "";

}

int	ft_countword(char *line)
{
	int	is_word;
	int	cnt;
	int	i;
	char	*str;

	cnt = 0;
	is_word = 0;
	i = 0;
	str = line;
	while (line[i])
	{
		if (line[i] == '\t', line[i] == ' ')
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int	fd;
	int	currentlinesize;
	char	*line;
	char	*tmp;
	int		line_size;

	line = "";
	line_size = 0;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break;
		line_size = ft_strlen(line);
		tmp = data->map; 	
		currentlinesize = ft_countword(line);
		data->map = ft_strjoin(line, tmp);
		if (data->m_width < currentlinesize)
			data->m_width = currentlinesize;
		data->m_height++;
		free(line);
	}
	ft_printf("%d m_height \n", data->m_width);
	ft_printf("%d height \n", data->m_height);
	ft_printf(" %s",data->map);
	close(fd);
}

void	*ft_init_matrix(t_fdf *data)
{
	t_pt	**zmatrix;
	int	w;
	int	h;

	data->z_matrix = malloc((sizeof(t_fdf) * data->m_height) + 1);
}

t_fdf	*ft_init_struct(char *mapfile)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	ft_zerostruc(data);
	ft_get_map(data, mapfile);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	data->image = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	return (data);
}

t_fdf	*ft_destroy_struct(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->z_matrix);
	free(data->mlx_ptr);
	free(data);
}