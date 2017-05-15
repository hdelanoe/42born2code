/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 05:52:02 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/15 18:32:47 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct	s_map
{
	double	x;
	double	y;
	double	z;
	double	xp;
	double	yp;
}				t_map;
typedef struct	s_size
{
	double	x;
	double	y;
	double	z;
	int		scalex;
	int		scaley;
	int		scalez;
	int		initx;
	int		inity;
}				t_size;
typedef	struct	s_bresenham
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	dx;
	double	dy;
	double	incx;
	double	incy;
	double	e;
	int		plusx;
	int		plusy;
}				t_bres;
typedef struct	s_mlx_ptr
{
	void	*mlx;
	void	*win;
}				t_mlx_ptr;
typedef struct	s_key_struct
{
	int			erase;
	t_map		**map;
	t_size		*size;
	t_mlx_ptr	ptr;
}				t_key_struct;
t_map			**ft_parser(char **argv, t_size *size);
void			ft_tracer(t_map **map, t_size *size);
void			proj_iso(t_map **map, t_size *size, t_mlx_ptr ptr, int erase);
void			ft_algo(t_map **map, t_size *size, t_mlx_ptr ptr, int erase);
void			algo_bresenham(t_map point1, t_map point2, t_key_struct key);
void			put_pixel(t_bres algo, t_key_struct key,
				t_map point1, t_map point2);
int				ft_key(int keycode, void *param);
void			ft_error(int i);

#endif
