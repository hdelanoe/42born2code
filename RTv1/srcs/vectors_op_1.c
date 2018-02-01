/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_op_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:50:09 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/01/31 14:50:10 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	v_double_add(t_vector *a, double b)
{
	t_vector	r;

	r.x = a->x + b;
	r.y = a->y + b;
	r.z = a->z + b;
	return (r);
}

t_vector	v_double_subs(t_vector *a, double b)
{
	t_vector	r;

	r.x = a->x - b;
	r.y = a->y - b;
	r.z = a->z - b;
	return (r);
}

t_vector	v_double_mult(t_vector *a, double b)
{
	t_vector	r;

	r.x = a->x * b;
	r.y = a->y * b;
	r.z = a->z * b;
	return (r);
}

t_vector	v_double_div(t_vector *a, double b)
{
	t_vector	r;

	r.x = a->x / b;
	r.y = a->y / b;
	r.z = a->z / b;
	return (r);
}
