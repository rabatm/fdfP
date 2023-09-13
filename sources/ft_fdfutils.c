#include "../includes/fdf.h"

// Prints map matrix for debug purposes
void	print_matrix(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->m_height)
	{
		j = 0;
		ft_printf("%d", data->z_matrix[i][j++]);
		while (j < data->m_width)
		{
			printf("% 3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// Count words to see number of value per line.
int	ft_count_words(char *str)
{
	int i;
	int	is_word;
	int	cnt;

	cnt = 0;
	is_word = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			cnt++;
		}
	}
	return (cnt);
}
