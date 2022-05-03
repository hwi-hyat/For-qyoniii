/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0map_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:35:39 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 21:42:13 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	first_column_skipper(int fd)
{
	char	temp;

	temp = 0;
	while (temp != '\n')
		read(fd, &temp, 1);
}

void	row_parcer(int fd, char *map_row)
{
	int		i;
	char	temp;

	i = 0;
	while (read(fd, &temp, 1))
	{
		if (temp == '\n')
			break ;
		map_row[i] = temp;
		i++;
	}
	map_row[i] = 0;
}

int	parcer(char **map, char *argv, int length)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
		return (0);
	first_column_skipper(fd);
	i = 0;
	while (i < length)
	{
		row_parcer(fd, map[i]);
		i++;
	}
	close(fd);
	return (1);
}

char	**map_mallocator(char *argv, t_info *info)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (info->tall + 1));
	if (map == NULL)
		return (0);
	while (i < (info->tall + 1))
	{
		map[i] = (char *)malloc(sizeof(char) * (info->len + 1));
		if (map[i] == NULL)
			return (0);											//널가드 수정필요
		i++;
	}
	if (parcer(map, argv, info->tall) == 0)
		return (0);
	return (map);
}
