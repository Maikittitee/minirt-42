/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/13 00:15:31 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool render(void *img, int width, int height)
{
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);

for(int y = 0; y < height; ++y)
for(int x = 0; x < width; ++x)
{
	int color = get_color(x, y);
    int pixel = (y * line_bytes) + (x * 4);

	// buffer[pixel] = color;
	buffer[pixel + 3] = (color >> 24); // alpha
	buffer[pixel + 2] = (color >> 16) & 0xFF; //red
	buffer[pixel + 1] = (color >> 8) & 0xFF; // green
	buffer[pixel] = (color) & 0xFF; //blue
}
	return (True);
}

int	get_color(int x, int y)
{
	(void)x;
	(void)y;


	char r = x * 255.0 / WIN_WIDTH;
	char b= y * 255.0 / WIN_HEIGHT;
	// char g = (y) * 255.0 / sqrt(WIN_HEIGHT * WIN_HEIGHT + WIN_WIDTH * WIN_WIDTH);
	char g = 0x00;

	int color = (((char)r << 16) & (0xFF0000)) | (((char)g << 8) & (0x00FF00)) | (b & (0x0000FF));

	printf("%x\n", color);
	return (color);
	// return ((r << 16) | (g << 8) | (b));
	// return (0xABCDEF);	
	return (0xFF0000);
	
}