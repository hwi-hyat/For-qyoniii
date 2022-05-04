/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0check_input1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:28:26 by tson              #+#    #+#             */
/*   Updated: 2022/05/04 16:23:48 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	check_str(char *str, int line_count, t_info *info)
{
	if (line_count == 0)							//파일의 첫번째 줄에서는 지도에 대한 정보가 있고 그 내용을 저장
	{
		if (check_condition(str, info) == 0)
			return (0);
	}
	else if (line_count == 1)						//tall의 첫번째 줄에서는 info->len의 길이를 측정
	{
		info->len = check_tall_line(str, info);		//유효성검사 후 tall의 값을 반환받아 저장
		if (info->len == 0)
			return (0);
	}
	else											//tall의 첫번째 이후 줄의 길이가 재놓은 info->len의 길이와 같은지 판단
	{												//다른게 있음 오류
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
	while (read(fd, &buf, 1) > 0)			//끝까지 다 읽으면 read함수가 0을 리턴, 반복문 종료.
	{
		idx = 0;
		while (buf != '\n')					//파일의 한 줄의 끝까지 읽어들임
		{
			temp_line[idx] = buf;			//temp_line에 한 줄의 내용을 저장
			idx++;
			if (read(fd, &buf, 1) <= 0)
				return (0);
		}
		temp_line[idx] = '\0';				//끝에 널문자 넣어줌
		if (check_str(temp_line, count, info) == 0)			//복사해온 한 줄을 검사
			return (0);
		count++;											//한 줄씩 넘어갈때마다 카운트, 줄 수 세줌(파일의 첫 줄(ex "30.ox") 포함)
	}
	if ((count - 1) != info->tall)							//파일의 첫 줄(ex "30.ox")까지 세주었으니 그만큼 하나 빼줌
		return (0);
	return (1);
}

int	check_input(char *filename, t_info *info)				//입력받은 파일을 열고 파일디스크럽터를 할당해줌
{
	int		fd;

	fd = open(filename, O_RDONLY);							//지도파일을 열어서 파일디스크립터 할당
	if (fd == -1)
		return (0);
	if (check_map(fd, info) == 0)
		return (0);
	close(fd);											//지도파일 닫기
	return (1);
}
