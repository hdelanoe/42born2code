/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:56:22 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 13:00:35 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define A ft_printf("lol\n");
# define ENV_LEN 1024
# define BUF_SIZ 4096
# define PATH_MAX 4096
# define _POSIX_SOURCE
# include <termios.h>
# include <term.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/printf.h"

char			**g_env;
typedef struct	s_cd
{
	int		p;
	int		print;
	char	*home_path;
	char	*curpath;
	char	cwd[PATH_MAX];

}				t_cd;
typedef struct	s_env_flag
{
	char	altpath[BUF_SIZ];
	char	unset[BUF_SIZ];
	int		v;
}				t_env_flag;
void			display_prompt(void);
void			mini_signal(int i);
void			init_path(char **cmd, char ***env);
void			lauch_command(char **cmd, char ***env);
void			cd_builtin(char **args, char ***env);
void			echo_builtin(char **args);
void			setenv_builtin(char **cmd, char ***env);
void			unsetenv_builtin(char **cmd, char ***env);
void			env_builtin(char **cmd, char ***env);
int				check_flag(char **cmd, t_env_flag *flag, char ***env, int i);
void			exit_shell(int flag);
void			handle_int(int sign);
void			cmd_handle_int(int sign);
int				parse_builtin(char *cmd);
char			*get_env(char *name, char **env);
void			set_env(char *name, char *value, int overwrite, char ***env);
void			unset_env(char *name, char ***env);
int				set_path(char **path);
void			print_computer(char **argv);
void			get_home_path(char **cmd);
void			check_multi(char ***cmd);
void			get_term(void);
#endif
