/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myheader.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:05 by tson              #+#    #+#             */
/*   Updated: 2022/02/24 01:38:12 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYHEADER_H
# define MYHEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	char	empty;
	char	obs;
	char	full;
	int		wid;
	int		len;

}t_info;

typedef struct s_max
{
	int	start_x;
	int	start_y;
	int	max_size;
}t_max;

typedef struct s_coordinate
{
	int x;
	int y;
}t_co;

int		str_len(char *str);
int		is_same_char(char c1, char c2);
int		input_three_condition(char *str, t_info *p_info, int len);
int		check_condition(char *str, t_info *p_info);
int		check_first_line(char *str, t_info *p_info);
int		check_else_line(char *str, t_info *p_info);
int		check_str(char *str, int line_count, t_info *p_info);
int		check_map(int fd, t_info *p_info);
int		check_input(char *str, t_info *p_info);
int		make_input_file(void);
char	**map_mallocator(char *argv, t_info *info);
void	finder_main(char **map, t_info *map_info);
int		obs_chk(char c, t_info *map_info);
void	is_it_max(t_co co, int size, t_max *max_sq);
int		val_map_acc(t_co co, int size, t_info *map_info);
void	printer(char **map, t_info *map_info);

#endif
