/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:02:30 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/10/23 14:02:57 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	help(void)
{
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'a');
	ft_putstr("Include directory entries whose names begin with a dot (.).");
	ft_printf("\n\n\x1B[1m%8c%-7c{E}", '-', 'd');
	ft_putstr("Directories are listed as plain file.");
	ft_printf("\n\n\x1B[1m%8c%-7c{E}", '-', 'g');
	ft_putstr("Suppresse the owner name in the long format output.");
	ft_printf("\n\n\x1B[1m%8c%-7c{E}", '-', 'h');
	ft_putstr("When used with the \x1B[1m-h\x1B[0m, ");
	ft_putstr("use unit suffixes for sizes.\n\n");
	ft_printf("\x1B[1m%8c%-7c{E}List in long format.\n\n", '-', 'l');
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'n');
	ft_putstr("Dispay user and groups IDs numerically. ");
	ft_putstr("Turns on the \x1B[1m-l \x1B[0moption.\n\n");
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'o');
	ft_putstr("List in long format, but omit the group id.\n\n");
	ft_printf("\x1B[1m%8c%-7c{E}Reverse the order of the sort.\n\n", '-', 'r');
	ft_printf("\x1B[1m%8c%-7c{E}Sort by time modified.\n\n", '-', 't');
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'x');
	ft_putstr("Force multi-column output sorted across. ");
	ft_putstr("Disable the \x1B[1m-G \x1B[0moption.\n\n");
}

void	ft_help(void)
{
	ft_putstr("\x1B[1mNAME\n\x1B[0m");
	ft_printf("\x1B[1m%9s {E}-- list directory contents\n\n", "ft_ls");
	ft_putstr("\x1B[1mSYNOPSIS\n\x1B[0m");
	ft_printf("\x1B[1m%9s {E}[\x1B[1m-GRSadghlnortx{E}] [file ...]", "ft_ls");
	ft_putstr("\n\n\x1B[1mOPTION\n\x1B[0m");
	ft_printf("%8che following options are available:\n\n", 'T');
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'G');
	ft_putstr("Enable colorized output.\n\n");
	ft_printf("\x1B[1m%8c%-7c{E}", '-', 'R');
	ft_putstr("Recursively list subdirectories encountered.\n\n");
	ft_printf("\x1B[1m%8c%-7c{E}Sort files by size.\n\n", '-', 'S');
	help();
	exit(42);
}

void	ft_illegal(void)
{
	ft_putstr("ft_ls: illegal option -- -\n");
	ft_putstr("usage: ft_ls [-GRSadghlnortx] [file ...]\n");
	ft_putstr("       ft_ls --help\n");
	exit(42);
}
