/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_computer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:08:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/11/21 12:38:22 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	print_display(char *cmd, char *prompt, char *ajust)
{
	ft_putstr("\n\n                  _________________");
	ft_putendl("______________________________");
	ft_putstr("                /                       ");
	ft_putendl("                         \\");
	ft_putstr("               |    ___________________");
	ft_putendl("______________________     |");
	ft_putstr("               |   |                  ");
	ft_putendl("                       |    |");
	ft_printf("               |   |  %-11s ", prompt);
	if (ft_strlen(cmd) && ft_strlen(cmd) < 26)
		ft_printf("%-*s%s |    |\n", 26, cmd, ajust);
	else
		ft_printf("%-*s%s |    |\n", 26, "./minishell", ajust);
	ft_printf("               |   |  %-11s _%s", prompt, ajust);
	ft_putendl("                          |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
}

void	print_display2(void)
{
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |   \033[92m155 151 156 151");
	ft_putendl(" 163 150 145 154 154\033[0m   |    |");
	ft_putstr("               |   |                     ");
	ft_putendl("                    |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |                    ");
	ft_putendl("                     |    |");
	ft_putstr("               |   |____________________");
	ft_putendl("_____________________|    |");
	ft_putstr("               |                        ");
	ft_putendl("                          |");
	ft_putstr("                \\________________________");
	ft_putendl("_________________________/");
}

void	print_key(void)
{
	ft_putstr("                       \\________________");
	ft_putendl("___________________/");
	ft_putstr("                    _____________________");
	ft_putendl("______________________");
	ft_putstr("                 _-'    .-.-.-.-.-.-.-.-.-.");
	ft_putendl("-.-.-.-.-.-.-.  --- `-_");
	ft_putstr("              _-'.-.-. .---.-.-.-.-.-.-.-.-.");
	ft_putendl("-.-.-.-.-.-.--.  .-.-.`-_");
	ft_putstr("           _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.");
	ft_putendl("-.-.-.-.-.-`__`. .-.-.-.`-_");
	ft_putstr("        _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-");
	ft_putendl(".-.-.-.-.-.-----. .-.-.-.-.`-_");
	ft_putstr("     _-'.-.-.-.-.-. .---.-. .-----------------");
	ft_putendl("--------. .-.---. .---.-.-.-.`-_");
	ft_putstr("    :------------------------------------------");
	ft_putendl("-------------------------------:");
	ft_putstr("    `---._.------------------------------------");
	ft_putendl("-------------------------._.---'\n\n\n");
}

char	*get_prompt(char **ajust)
{
	char	*prompt;
	char	*home_path;
	char	*pwd;

	*ajust = "";
	home_path = NULL;
	if (!(pwd = get_env("PWD=", g_env)) ||
			!(home_path = get_env("HOME=", g_env)))
	{
		prompt = "\033[96m>-<(((('>\033[0m";
		*ajust = "  ";
	}
	else if (ft_strstr(pwd, home_path))
		prompt = "\033[92m~~~{~{\033[91m@\033[0m ~ >";
	else
		prompt = "\033[95m(. Y .)\033[0m / >";
	return (prompt);
}

void	print_computer(char **argv)
{
	char	*prompt;
	char	cmd[BUF_SIZ];
	char	*ajust;
	int		i;

	ft_bzero(cmd, BUF_SIZ);
	i = 0;
	while (argv[++i])
	{
		ft_strcat(cmd, argv[i]);
		ft_strcat(cmd, " ");
	}
	prompt = get_prompt(&ajust);
	print_display(cmd, prompt, ajust);
	print_display2();
	print_key();
}
