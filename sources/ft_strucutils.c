#include "../includes/fdf.h"

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int	fd;
	char	*line;
	char	*tmp;
	int temp_size;

	line = "";
	temp_size = 0;
	tmp = "";
	data->m_width = 0;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break;
		tmp = data->map;
		ft_printf("%s\n%s", line, tmp);
		data->map = ft_strjoin_free(tmp ,line);
		data->m_height++;
		temp_size = ft_strlen(line);
		if (temp_size > data->m_width)
			data->m_width = temp_size;
		free(line);
	}
	ft_printf("%s\n, width : %i, height : %i\n", data->map, data->m_width, data->m_height);
	close(fd);
}

t_fdf	*ft_init_struct(char *mapfile)
{
	t_fdf	*data;
	data = malloc(sizeof(t_fdf));
	ft_get_map(data, mapfile);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	data->image = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	return (data);
}
