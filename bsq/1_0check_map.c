/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:28:26 by tson              #+#    #+#             */
/*   Updated: 2022/05/05 02:43:05 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ajtcsheader.h"

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

int	check_map(int fd, t_info *info, char *temp_line)
//지도를 한줄한줄 읽어들여서 유효성검사 및 info의 값들 판단
{
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

int	len_check(char *filename)
/*
	이 함수는 temp_line[100000] 고칠려고 만든 함수야
	파일에서 지도안에 가로길이중에 제일 긴 길이를 구하는 함수인데 제일 긴 길이를 구해서 동적할당하면
	아무리 긴 줄이라도 읽어들여서 유효성검사 할 수 있거든
	할당해제도 free로 해놔서 문제없이 잘 동작할거야 내가 테스트 해 본 경우에 메모리누수는 없었어
*/
{
	int		fd;
	int		len;
	int		lenmax;
	char	buf;

	len = 0;
	fd = open(filename, O_RDONLY);		//파일을 열고
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) > 0)		//한 글자씩 계속 읽어들이는데
	{
		if (buf == '\n')				//개행을 만나면 거기까지가 한 줄
		{
			if (len > lenmax)			//개행을 만날때까지 길이를 재주는데 한줄한줄 지나갈때마다 최대값이 얼마인지 구해
				lenmax = len;
			len = 0;
			continue;
		}
		len++;
	}
	return (lenmax);					//그래서 그 최대값을 반환해줄거야
}

int	check_input(char *filename, t_info *info)				//입력받은 파일을 열고 파일디스크럽터를 할당해줌
{
	int		fd;
	char	*temp_line;

	temp_line = (char *)malloc(sizeof(char) * (len_check(filename) + 1));
	//파일 안의 지도에서 가장 긴 가로길이를 구해서 그 길이의 한 줄도 들어갈만큼 동적할당. temp_line[100000] 없애려고 만든거야
	if (temp_line == NULL)
		return (0);
	fd = open(filename, O_RDONLY);							//지도파일을 열어서 파일디스크립터 할당
	if (fd == -1 || check_map(fd, info, temp_line) == 0)	//fd할당 실패하거나 유효성검사에서 틀린게 발견되면 동적할당 해제해주고 오류 리턴
	{
		free(temp_line);
		return (0);
	}
	close(fd);											//지도파일 닫기
	free(temp_line);									//잘 됐으면 동적할당 해제하고 1리턴해서 진행
	return (1);
}
