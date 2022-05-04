/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0map_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:35:39 by siykim            #+#    #+#             */
/*   Updated: 2022/05/04 14:27:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	first_line_skip(int fd)								//지도파일의 첫번째 줄은 지도에대한 정보이고 지도내용이 아니니 건너뛰는 함수
{
	char	temp;

	temp = 0;
	while (temp != '\n')
		read(fd, &temp, 1);
}

void	line_copy_map(int fd, char *map_row)				//지도파일의 지도를 한 줄씩 읽어 map에 저장하는 함수
{
	int		i;
	char	temp;

	i = 0;
	while (read(fd, &temp, 1))
	{
		if (temp == '\n')									//줄 끝에는 무조건 개행이 나오게되니 개행을 만나게되면 줄이 끝났다는 뜻
			break ;
		map_row[i] = temp;
		i++;
	}
	map_row[i] = 0;
}

int	copy_map(char **map, char *filename, int length)			//할당한 map에 지도파일안의 지도 내용들을 복사해오는 함수
{
	int		i;
	int		fd;

	fd = open(filename, O_RDWR);								//지도파일을 open함수를 이용해 fd할당
	if (fd < 0)												//open 오류났을 때 고려
		return (0);
	first_line_skip(fd);									//지도파일의 첫번째 줄은 지도에대한 정보이고 지도내용이 아니니 건너뜀
	i = 0;
	while (i < length)										//지도를 한 줄씩 복사 해 옴
	{
		line_copy_map(fd, map[i]);
		i++;
	}
	close(fd);
	return (1);
}

char	**malloc_err_free_map(char **map, int idx)					//동적할당을 진행하는 도중에 에러가 났을 때 그 지점까지 할당해놓은
{															//메모리를 할당해제해야함
	int	i;

	i = 0;
	while (i < idx)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

char	**map_malloc(char *filename, t_info *info)				//지도가 담긴 파일의 이름을 받아 동적할당을 사용해 지도를 저장하는 함수
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (info->tall + 1));	//tall만큼 이차원배열의 상위배열 할당
	if (map == NULL)
		return (0);
	while (i < (info->tall + 1))								//각각의 line을 저장해줄 이차원배열의 내부배열 할당
	{
		map[i] = (char *)malloc(sizeof(char) * (info->len + 1));
		if (map[i] == NULL)
			return (malloc_err_free_map(map, i));					//동적할당을 진행하는 도중에 에러가 났을 때 그 지점까지 할당해놓은
		i++;
	}
	if (copy_map(map, filename, info->tall) == 0)
		return (0);
	return (map);
}
