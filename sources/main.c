/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:05:44 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/13 13:46:28 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int argc, char *argv[])
{
	t_fdf	*data;
	
	if (argc != 2 || argc == 1)
	{
		print_err(ERR_ARG,0);
		return(1);
	}
	data = ft_init_struct(argv[1]);
	print_matrix(data);
	mlx_hook(data->win_ptr, 2, 1L<<0, handle_inputs, (void *)data);
	draw(data);
    mlx_loop(data->mlx_ptr);
//	ft_free_struct(data);
	return(0);
}
