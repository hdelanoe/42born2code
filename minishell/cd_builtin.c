/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:02:58 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 12:59:15 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	set_l(t_cd *cd)
{
	char	**path;
	int		len;
	int		i;

	if (ft_strcmp(cd->cwd, "/"))
		ft_strcat(cd->cwd, "/");
	ft_strcat(cd->cwd, cd->curpath);
	if (cd->curpath[0] == '/' || cd->curpath[0] == '~')
		ft_strcpy(cd->cwd, cd->curpath);
	path = ft_strsplit(cd->cwd, '/');
	len = set_path(path);
	i = -1;
	ft_bzero(cd->cwd, BUF_SIZ);
	while (++i < len)
	{
		if (path[i])
		{
			ft_strcat(cd->cwd, "/");
			ft_strcat(cd->cwd, path[i]);
		}
	}
	if (!cd->cwd[0])
		cd->cwd[0] = '/';
	ft_freearr(&path);
}

void	change_dir(t_cd *cd, char ***env)
{
	set_env("OLDPWD=", cd->cwd, 1, env);
	if (cd->print)
	{
		if (ft_strstr(cd->curpath, cd->home_path))
		{
			write(1, "~", 1);
			ft_putendl(&cd->curpath[ft_strlen(cd->home_path)]);
		}
		else
			ft_putendl(cd->curpath);
	}
	chdir(cd->curpath);
	if (!cd->p)
		set_l(cd);
	else
		getcwd(cd->cwd, PATH_MAX);
	set_env("PWD=", cd->cwd, 1, env);
}

void	get_dir(t_cd *cd, char ***env)
{
	DIR *dir;

	dir = NULL;
	if (!(ft_strcmp(cd->curpath, "~")) || !cd->curpath)
	{
		write(1, "cd: HOME not set\n", 17);
		return ;
	}
	ft_strcpy(cd->cwd, get_env("PWD=", (*env)));
	if (access(cd->curpath, F_OK) == -1)
		ft_printf("cd: no such file or directory: %s\n", cd->curpath);
	else if (access(cd->curpath, R_OK) == -1)
		ft_printf("cd: permission denied: %s\n", cd->curpath);
	else if (!(dir = opendir(cd->curpath)))
		ft_printf("cd: not a directory: %s\n", cd->curpath);
	else if (!access(cd->curpath, F_OK))
		change_dir(cd, env);
	if (dir)
		closedir(dir);
}

void	lauch_cd(t_cd *cd, char **args, char ***env)
{
	cd->print = 0;
	if (!args[0])
		cd->curpath = cd->home_path;
	else if (args[1])
	{
		if (args[2])
			write(1, "cd: too many arguments\n", 23);
		else
			ft_printf("cd: string not in pwd: %s\n", args[0]);
		return ;
	}
	else
	{
		if (!ft_strcmp(args[0], "-"))
		{
			cd->print = 1;
			if (!(cd->curpath = get_env("OLDPWD=", *env)))
			{
				write(1, "cd: OLDPWD not set\n", 19);
			}
		}
		else
			cd->curpath = args[0];
	}
	get_dir(cd, env);
}

void	cd_builtin(char **args, char ***env)
{
	int		i;
	t_cd	cd;

	cd.p = 0;
	ft_bzero(cd.cwd, PATH_MAX);
	cd.home_path = get_env("HOME=", *env);
	i = 1;
	if (args[i])
	{
		while (args[i] && args[i][0] == '-' && args[i][1] && !args[i][2])
		{
			if (!(ft_strcmp(args[i], "-P")))
				cd.p = 1;
			if (!(ft_strcmp(args[i], "-L")))
				cd.p = 0;
			i++;
		}
	}
	lauch_cd(&cd, &args[i], env);
}
