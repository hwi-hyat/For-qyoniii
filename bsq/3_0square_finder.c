/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0square_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:09:24 by siykim            #+#    #+#             */
/*   Updated: 2022/05/04 14:25:22 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	sq_check(char **map, t_info *info, t_max *max_sq, t_start co)		//인자로 전달받은 시작점에서 사각형의 크기를 점점 늘려보며 최대로 가능한 크기를 찾고, 그게 최댓값인지 찾는 함수
{
	int	i;
	int	size;

	size = 1;
	while (val_map_acc(co, size, info))										//사각형이 지도를 벗어날 수 없으니 판단해줌
	{
		i = 0;
		while (i < size)
		{
			if (map[co.y + size - 1][co.x + i] == info->obs
				|| map[co.y + i][co.x + size - 1] == info->obs)
			{
				is_it_max(co, size - 1, max_sq);
				return ;
			}
			i++;
		}
		if (val_map_acc(co, size, info) == 2)								//만약 사각형이 지도의 경계까지 채워졌다면 더이상 커질 수 없으니 최댓값인지 판단 후 종료
		{
			is_it_max(co, size, max_sq);
			return ;
		}
		size++;
	}
}

void	finder(char **map, t_info *info, t_max *max_sq)						//(0,0)부터 시작해 한 칸씩 옮겨가면서 해당하는 점을 확인하는 함수
{
	t_start	co;

	co.y = 0;
	while (co.y < (info->tall - max_sq->max_size))
	{
		co.x = 0;
		while (co.x < (info->len - max_sq->max_size))
		{
			sq_check(map, info, max_sq, co);
			co.x++;
		}
		co.y++;
	}
	return ;
}

void	square_filler(char **map, t_max *max_sq, t_info *info)				//찾아낸 최대 사각형의 정보를 가지고 map안에 사각형을 그려넣는 함수
{
	int	i;
	int	j;

	i = 0;
	while (i < max_sq->max_size)
	{
		j = 0;
		while (j < max_sq->max_size)
		{
			map[max_sq->max_y + i][max_sq->max_x + j] = info->fill;
			j++;
		}
		i++;
	}
}

void	finder_main(char **map, t_info *info)
{	
	t_max	max_sq;

	max_sq.max_x = 0;
	max_sq.max_y = 0;
	max_sq.max_size = 0;						//제일 큰 사각형의 시작점위치와 크기를 저장해주는 구조체를 선언하고 초기화해주는 작업
	finder(map, info, &max_sq);
	square_filler(map, &max_sq, info);
	printer(map, info);
}
