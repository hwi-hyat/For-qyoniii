/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:16:44 by tson              #+#    #+#             */
/*   Updated: 2022/05/03 23:05:54 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	init_info(t_info *p_info)			//구조체 info안의 값들을 초기화 해 줌
{
	p_info -> empty = '\0';
	p_info -> fill = '\0';
	p_info -> obs = '\0';
	p_info -> len = 0;
	p_info -> tall = 0;
}

void	free_map(char **map, t_info *info)	//동적할당 해 놓은 지도(map)을 할당해제하는 함수
{
	int	i;

	i = 0;
	while (i <= info->tall)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_error_msg(void)				//에러가 발생했을 때 에러메세지를 출력하는 함수
{
	write(2, "map error\n", 10);
	exit(0);
}

void	find_and_print(char *filename, t_info *info)	//파일 이름을 넘겨주면 해당하는 파일에서 지도를 불러오고 가장 큰 사각형을 찾아 저장하는 함수
{
	char	**map;

	map = map_mallocator(filename, info);
	if (map == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	finder_main(map, info);
	free_map(map, info);
}

int	main(int argc, char *argv[])
{
	int		argv_idx;
	t_info	info;

	init_info(&info);
	if (argc == 1)										//지도 파일이 주어지지 않았을때
	{
		if (make_input_file() == 0)
			print_error_msg();
		if (check_input("AJTCS", &info) == 0)
			print_error_msg();
		find_and_print("AJTCS", &info);
	}
	argv_idx = 1;
	while (argv_idx < argc)								//지도 파일이 주어졌을때
	{
		init_info(&info);
		if (check_input(argv[argv_idx], &info) == 0)
			write(2, "map error\n", 10);
		else
			find_and_print(argv[argv_idx], &info);
		if (argv_idx < argc - 1)						//지도가 여러개 들어왔을때 각각의 출력결과 사이에 개행출력
			write(1, "\n", 1);
		argv_idx++;
	}
	return (0);
}
