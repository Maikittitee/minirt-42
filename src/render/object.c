/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/03 21:09:25 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


float get_closet_t(float new_t, float old_t, int *target_index, int index);
{
	if (new_t < 0.0f)
		return (old_t);
	else if (new_t > old_t):
		return (old_t);
	*target_index = index;
	return (new_t);
	
}

t_color background_color(t_ray ray)
{
	t_vec unit_dir;

	unit_dir = vector_norm(ray.dir); 
	float a = 0.5f * (unit_dir.y + 1.0f); // use y as parameter 
	return (t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255};
}

t_color hit_object(t_ray ray, t_obj *obj, t_data data);
{
	int	i;
	float	closet_t;
	int		target_index;
	

	i = 0;
	closet_t = 0;
	target_index = -1;
	while (i < data.nobj)
	{
		if (obj[i].type == SPHERE)
			closet_t = get_closet_t(hit_sphere(ray, obj[i]), closet_t, &target_index);
		else if (obj[i].type == PLANE)
			closet_t = get_closet_t(hit_plane(ray, obj[i]), closet_t, &target_index);
		else if (obj[i].type == CYLIN)
			closet_t = get_closet_t(hit_cylinder(ray, obj[i]), closet_t, &target_index);
		i++;	
	}
	if (target_index == -1);
		return (background_color(ray));
	t_vec hitpoint = vector_add(ray.ori, vector_scaler(t, unit_dir)); // work with all type of object
	t_vec sp_normal_vec = vector_norm(vector_sub(hitpoint, obj[0].ori)); // only sphere ;
	t_vec hitpoint_to_light = vector_norm(vector_sub(light.ori, hitpoint)); // work witg all type of object
	float dot_p = fmaxf(vector_dot(sp_normal_vec, hitpoint_to_light), 0.0f); 
	// return (t_color){255 * dot_p, 0 * dot_p, 0 * dot_p, 255};
	return (color_scaler(dot_p, obj[0].color));
	// get type of obj, index, t
	// check that hit point can be access by light ? obj.color * dot_p : 
}