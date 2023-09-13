#include "../includes/fdf.h"

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int	fd;
	char	*line;
	int temp_size;

	line = "";
	data->map = "";
	temp_size = 0;
	data->m_width = 0;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, O_RDONLY);
		if (!line)
			break;
		data->map = ft_strjoin(data->map, line);
		data->m_height++;
		temp_size = ft_strlen(line);
		if (temp_size > data->m_width)
			data->m_width = temp_size;
		free(line);
	}
	close(fd);
}

t_fdf	*ft_init_struct(char *mapfile)
{
	t_fdf	*data;
	data = malloc(sizeof(t_fdf));
	ft_get_map(data, mapfile);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");

	return (data);
}