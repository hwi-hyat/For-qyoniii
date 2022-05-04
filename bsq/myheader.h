/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myheader.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:05 by tson              #+#    #+#             */
/*   Updated: 2022/05/04 14:39:21 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYHEADER_H
# define MYHEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_start
{
	int x;
	int y;
}t_start;

typedef struct s_max			//가장 큰 정사각형의 정보를 저장하는 구조체, 가장 왼쪽 위 시작좌표와 크기를 저장
{
	int	max_x;				//시작좌표의 x좌표
	int	max_y;				//시작좌표의 y좌표
	int	max_size;				//가장 큰 사각형의 한 변의 길이
}t_max;

typedef struct s_info			//지도의 기본적인 정보들을 저장해놓는 구조체
{
	char	empty;				//빈칸을 어떤 문자로 나타냈는지
	char	obs;				//장애물을 어떤 문자로 나타냈는지
	char	fill;				//가장 큰 정사각형을 표현 할 때 어떤 문자로 나타냈는지
	int		len;				//입력받은 지도의 너비
	int		tall;				//입력받은 지도의 길이
}t_info;

int		ft_strlen(char *str);
int		fill_obs_empty_ok(char *str, t_info *p_info, int len);
int		check_condition(char *str, t_info *p_info);
int		check_tall_line(char *str, t_info *p_info);
int		check_str(char *str, int line_count, t_info *p_info);
int		check_map(int fd, t_info *p_info);
int		check_input(char *filename, t_info *p_info);
int		make_input_file(void);
char	**map_malloc(char *filename, t_info *info);
void	finder_main(char **map, t_info *map_info);
int		obs_chk(char c, t_info *map_info);
void	is_it_max(t_start co, int size, t_max *max_sq);
int		val_map_acc(t_start co, int size, t_info *map_info);
void	printer(char **map, t_info *map_info);

#endif
