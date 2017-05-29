/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 10:59:34 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/28 19:10:52 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ABS(Value) (((Value) < 0) ? - (Value) : (Value))
# define ZR e.fract.zr
# define ZI e.fract.zi
# define X e.plan.x
# define Y e.plan.y
# define I e.plan.i
# define SL e.win.winx
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct	s_win
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoomx;
	double	zoomy;
	int		winx;
	int		winy;
	void	*mlx;
	void	*win;
	int		iter;
	int		event;
	int		mask;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
}				t_win;
typedef struct	s_img
{
	void	*ptr;
	char	*str;
	int		bpp;
	int		s_l;
	int		endian;
	int		i;
	int		intensity;
}				t_img;
typedef struct	s_pxl
{
	long x;
	long y;
}				t_pxl;
typedef struct	s_fract
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
}				t_fract;
typedef	struct	s_plan
{
	int		x;
	int		y;
	int		i;
	double	tmp;
}				t_plan;
typedef struct	s_key
{
	int	r;
	int	g;
	int	b;
	int	plus;
	int lock;
}				t_key;
typedef struct	s_env
{
	t_win	win;
	t_img	img;
	t_fract	fract;
	t_plan	plan;
	t_key	key;
	char	*arg;
}				t_env;
void			ft_fractal(char *arg, t_env e);
t_win			init_mandel(char *arg);
void			ft_mandel(t_env e);
t_win			init_julia(char *arg);
void			ft_julia(t_env e);
void			ft_burnin(t_env e);
void			ft_voodoo(t_env e);
void			ft_glynn(t_env e);
void			ft_dend(t_env e);
t_img			ft_image(t_win win);
void			draw_img(t_env e);
int				ft_rgb(int iteri, int max_iter);
int				ft_curs(int x, int y, t_env *e);
int				ft_mouse(int button, int x, int y, t_env *e);
t_key			ft_init_key();
int				ft_key(int keycode, t_env *e);
void			ft_comp_mand(char *arg, t_env e);
void			translate(int keycode, t_env *e);
#endif
