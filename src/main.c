/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:55:15 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/14 22:22:53 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "ktunchar's MiniRT");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);

	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 2, 1, ft_exit, data);
	mlx_loop(data->mlx);
	
}