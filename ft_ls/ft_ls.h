/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:52:00 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 13:56:54 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <locale.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/printf.h"

typedef struct	s_way
{
	char			*dir;
	int				type;
	int				perm;
	struct stat		stat;
	struct passwd	*pwd;
	struct group	*grp;
	char			*date;
	char			link[1024];
	struct s_way	*next;
}				t_way;
typedef struct	s_sort
{
	t_way	*begin;
	t_way	*tmp;
	t_way	*new;
}				t_sort;
typedef struct	s_entry
{
	DIR				*dir;
	struct dirent	*dirent;
	char			*path;
	char			*file;
	int				empty;
	int				type;
	int				perm;
	int				block;
	int				biggest;
	int				sz_l;
	int				sz_u;
	int				sz_g;
	int				sz_b;
	int				sz_uid;
	int				sz_gid;
	int				free_path;
	char			link[1024];
	t_way			*way;
	struct s_entry	*next;
}				t_entry;
typedef struct	s_env_ls
{
	DIR				*dir;
	struct dirent	*dirent;
	struct winsize	ws;
	struct stat		stat;
	int				flag[13];
	int				last_sort;
	int				last_format;
	int				one;
	t_way			*way;
	t_entry			*list;
	t_entry			*lst_tmp;
}				t_env_ls;
void			ft_init_env(t_env_ls *e);
int				ft_flag(t_env_ls *e, char **argv);
void			ft_help(void);
void			ft_illegal(void);
t_entry			*ft_newelem(void);
void			ft_listadd(t_entry **current, t_entry *new);
void			ft_init_list(t_entry *list, char *path);
t_way			*ft_init_way(t_entry **list, char *file);
void			ft_init_size(t_entry **list, t_way *way);
t_way			*ft_sort(t_env_ls *e, t_entry **list, t_way **current);
t_way			*ft_newway(t_env_ls *e, t_entry **list, char *file);
t_entry			*ft_ls(t_env_ls *e, t_entry *list, char *path);
void			ft_reverse(t_way **begin);
char			*ft_mode(t_way *list);
void			ft_print(t_env_ls *e);
void			ft_free_ptr(t_way *ptr);
void			ft_error(void);
void			ft_reverse_arg(t_env_ls *e, char **tab);
void			ft_swap(char **a, char **b);
int				ft_block(t_env_ls *e, int a);
#endif
