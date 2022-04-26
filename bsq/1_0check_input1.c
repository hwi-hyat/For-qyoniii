/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0check_input1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:28:26 by tson              #+#    #+#             */
/*   Updated: 2022/02/24 01:49:48 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	check_str(char *str, int line_count, t_info *p_info)
{
	if (line_count == 0)
	{
		if (check_condition(str, p_info) == 0)
			return (0);
	}
	else if (line_count == 1)
	{
		p_info -> wid = check_first_line(str, p_info);
		if (p_info -> wid == 0)
			return (0);
	}
	else
	{
		if (check_else_line(str, p_info) == 0)
			return (0);
	}
	return (1);
}

int	check_map(int fd, t_info *p_info)
{
	char	checked_str[100000];
	char	buf;
	int		idx;
	int		count;

	count = 0;
	while (read(fd, &buf, 1) > 0)
	{
		idx = 0;
		while (buf != '\n')
		{
			checked_str[idx] = buf;
			idx++;
			if (read(fd, &buf, 1) <= 0)
				return (0);
		}
		checked_str[idx] = '\0';
		if (check_str(checked_str, count, p_info) == 0)
			return (0);
		count++;
	}
	if ((count - 1) != p_info -> len)
		return (0);
	return (1);
}

int	check_input(char *str, t_info *p_info)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	if (check_map(fd, p_info) == 0)
		return (0);
	close(fd);
	return (1);
}
