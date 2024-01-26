/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/26 20:39:31 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	gen_ray(int x, int y, t_data *data)
{
	t_ray ray;

	(void)x;
	(void)y;
	ray.ori = data->cam.ori;
	// printf("cam dir: %f %f %f\n", data->cam.ray_dir.i, data->cam.ray_dir.j, data->cam.ray_dir.k);
	ray.dir = vector_add(data->cam.dir, vector_scaler((x / WIN_WIDTH), data->cam.axis.hori));
	ray.dir = vector_sub(ray.dir, vector_scaler((y / WIN_HEIGHT), data->cam.axis.vert));
	// printf(">%f %f %f\n", ray.dir.i, ray.dir.j, ray.dir.k);
	return (ray);

	
}

void	init_camera(t_cam *cam)
{
	cam->ori = (t_vec){0, 0, 0};
	cam->axis.dir = (t_vec){0, 0, -1};
	cam->fov = 70;
	cam->axis.vert = (t_vec){0, 1.0f, 0};
	cam->axis.hori = vector_cross(cam->axis.vert, cam->dir);
	cam->ver_width = 2 * tan(cam->fov * PI / 360);
	cam->ver_height = WIN_HEIGHT/WIN_WIDTH * cam->ver_width;
	cam->dir = cam->axis.dir;
	cam->dir = vector_sub(cam->normal_vec, vector_scaler(0.5, cam->axis.hori));
	cam->dir = vector_add(cam->dir, vector_scaler(0.5, cam->axis.vert));
	
	
}

t_bool render(t_data *data, t_img *img, char **buffer)
{
	// char *buffer;
	// t_img img;
	t_ray ray;
	t_color color;
	int	x;
	int y;

	y = 0;
	// init_camera(&data->cam)
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			ray = gen_ray(x, y, data);
			color = per_pixel(ray, data->obj); // color = per_pixel(ray);
			// put_color_to_img(per_pixel(x, y),buffer, img, (t_vec){x, y, 0});
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}



t_color	per_pixel(t_ray ray, t_obj *obj)
{
	(void)obj;
	(void)ray;
	printf("%f %f %f\n", ray.dir.i, ray.dir.j, ray.dir.k);
	return (t_color){255, 0, 255, 255};
	

}