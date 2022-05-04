/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2mystring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:07 by tson              #+#    #+#             */
/*   Updated: 2022/05/04 14:16:35 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	make_input_file(void)									//프로그램에 지도파일이 아무것도 안 들어왔을 때 직접 입력을 위해 임시파일을 만들어주는 함수
{
	int		fd;
	char	buf;

	fd = open("AJTCS", O_RDWR | O_CREAT | O_TRUNC, 0777);	//AJTCS라는 파일을 만들고 fd할당
	if (fd == -1)
		return (0);
	while (read(0, &buf, 1) != 0)							//입력종료(ctrl + d)가 들어올때까지 반복
		write(fd, &buf, 1);									//입력받은 내용을 파일에 저장
	close(fd);
	return (1);
}
