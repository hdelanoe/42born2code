/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:06:08 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/04/10 17:19:52 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	void	*buffer;
	int		fd;

	if (argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		else if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
	close(fd);
	return (0);
}
