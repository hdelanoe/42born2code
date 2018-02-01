/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:46:55 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/01/31 14:46:58 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*add_new_sphere(t_object *object, t_sphere *new_sphere)
{
	t_sphere	*tmp;

	tmp = object->start_sphere;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_sphere;
		new_sphere->next = NULL;
	}
	else
		object->start_sphere = new_sphere;
	return (tmp);
}

t_cone		*add_new_cone(t_object *object, t_cone *new_cone)
{
	t_cone	*tmp;

	tmp = object->start_cone;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cone;
		new_cone->next = NULL;
	}
	else
		object->start_cone = new_cone;
	return (tmp);
}

t_cylinder	*add_new_cylinder(t_object *object, t_cylinder *new_cylinder)
{
	t_cylinder	*tmp;

	tmp = object->start_cylinder;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cylinder;
		new_cylinder->next = NULL;
	}
	else
		object->start_cylinder = new_cylinder;
	return (tmp);
}

t_plane		*add_new_plane(t_object *object, t_plane *new_plane)
{
	t_plane		*tmp;

	tmp = object->start_plane;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_plane;
		new_plane->next = NULL;
	}
	else
		object->start_plane = new_plane;
	return (tmp);
}

t_light		*add_new_light(t_object *object, t_light *new_light)
{
	t_light		*tmp;

	tmp = object->start_light;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_light;
		new_light->next = NULL;
	}
	else
		object->start_light = new_light;
	return (tmp);
}
