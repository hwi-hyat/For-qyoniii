/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2mystring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:07 by tson              #+#    #+#             */
/*   Updated: 2022/02/24 00:38:30 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	str_len(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

int	is_same_char(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

int	make_input_file(void)
{
	int		fd;
	char	buf;

	fd = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (0);
	while (read(0, &buf, 1) != 0)
		write(fd, &buf, 1);
	close(fd);
	return (1);
}
