/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0check_input1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:28:26 by tson              #+#    #+#             */
/*   Updated: 2022/05/03 22:54:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	check_str(char *str, int line_count, t_info *info)
{
	if (line_count == 0)
	{
		if (check_condition(str, info) == 0)
			return (0);
	}
	else if (line_count == 1)						//tall의 첫번째 줄에서는 info->len의 길이를 측정
	{
		info->len = check_tall_line(str, info);
		if (info->len == 0)
			return (0);
	}
	else											//tall의 그 이후 줄에서는 재놓은 info->len의 길이와 같은지 판단
	{
		if (check_tall_line(str, info) != info->len)
			return (0);
	}
	return (1);
}

int	check_map(int fd, t_info *info)
//지도를 한줄한줄 읽어들여서 유효성검사 및 info의 값들 판단
{
	char	temp_line[1000000];				//고쳐보기
	char	buf;
	int		idx;
	int		count;							//tall이랑 비교

	count = 0;
	while (read(fd, &buf, 1) > 0)			//반복문을 이용해서 계속해서 버퍼에 파일내용을 한 바이트씩 읽어줌, 끝까지 다 읽으면 read함수가 0을 리턴, 반복문 종료.
	{
		idx = 0;
		while (buf != '\n')					//파일의 한 줄의 끝까지 읽어들임
		{
			temp_line[idx] = buf;
			idx++;
			if (read(fd, &buf, 1) <= 0)
				return (0);
		}
		temp_line[idx] = '\0';
		if (check_str(temp_line, count, info) == 0)
			return (0);
		count++;
	}
	if ((count - 1) != info->tall)						//first line(ex 30.ox)까지 세주었으니 그만큼 하나 빼줌
		return (0);
	return (1);
}

int	check_input(char *str, t_info *info)				//입력받은 파일을 열고 파일디스크럽터를 할당해줌
{
	int		fd;

	fd = open(str, O_RDONLY);							//지도파일을 열어서 파일디스크립터 할당
	if (fd == -1)
		return (0);
	if (check_map(fd, info) == 0)
		return (0);
	close(fd);											//지도파일 닫기
	return (1);
}
