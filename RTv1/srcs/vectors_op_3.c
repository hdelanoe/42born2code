/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_op_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:50:26 by hdelanoe          #+#    #+#             */
/*   Updated: 2018/01/31 14:50:27 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	v_v_subs(t_vector *a, t_vector *b)
{
	t_vector	r;

	r.x = a->x - b->x;
	r.y = a->y - b->y;
	r.z = a->z - b->z;
	return (r);
}

t_vector	v_v_mult(t_vector *a, t_vector *b)
{
	t_vector	r;

	r.x = (a->y * b->z) - (a->z * b->y);
	r.y = (a->z * b->x) - (a->x * b->z);
	r.z = (a->x * b->y) - (a->y * b->x);
	return (r);
}
