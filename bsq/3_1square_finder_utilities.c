/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_finder_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:12:26 by siykim            #+#    #+#             */
/*   Updated: 2022/02/24 00:12:26 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	is_it_max(t_start co, int size, t_max *max)					//전달받은 사각형의 정보를 토대로 지금까지 봤던 사각형중 최대크기의 사각형인지 판단하고 저장하는 함수
{
	if (size > max->max_size)
	{
		max->max_y = co.y;
		max->max_x = co.x;
		max->max_size = size;
	}
}

int	val_map_acc(t_start co, int size, t_info *map_info)						//그려내는 사각형이 지도를 벗어나는지 확인해주는 함수
{
	if ((co.y + size) == map_info->tall || (co.x + size) == map_info->len)
		return (2);
	else if ((co.y + size) < map_info->tall || (co.x + size) < map_info->len)
		return (1);
	return (0);

	//반환값 2: 사각형이 지도의 경계까지 찼을 때
	//반환값 1: 사각형이 지도의 안에 있을 때
	//반환값 0: 사각형이 지도를 벗어났을 때
}

void	printer(char **map, t_info *map_info)				//사각형이 채워진 map을 출력하는 함수
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->tall)
	{
		j = 0;
		while (j < map_info->len)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
