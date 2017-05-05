/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 16:28:17 by hdelanoe          #+#    #+#             */
/*   Updated: 2017/05/04 23:45:18 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <fcntl.h>
# include <unistd.h>
# include "./Libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
