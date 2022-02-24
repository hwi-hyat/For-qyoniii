/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:00 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 21:23:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct dict
{
	char	*key;
	char	*value;
}t_dict;

int		splitter(char *str, t_dict *p);
void	print_number(char *number, t_dict *diction);
char	*dict_director(int argc, char *argv[], int *keys);
char	*parse_length_check(int *keys, char *dict_dir);
char	*parse_duplicate(int *keys, char *dict_dir, char *dict);
int		ft_strlen(char *str);
char	*ft_dup_strcat_space(char *dest, char *src);
int		arr_big_len(char *str);
void	initialized_arr(char **arr, int num_row);
char	**divide_arg(char *number, int num_row, int number_len);
int		ft_strcmp(char *str1, char *str2);
int		check_phase_one(char *str);
int		check_phase_two(char *str);
int		check_dicterr(char *str);
int		zero_finder(t_dict *p);
char	*check_dict(char *key, t_dict *diction);
void	print_str(char *str);
int		trans_num(char **devided, char **result, t_dict *diction, int num_row);
char	*trans_hund(char part_hund, t_dict *diction);
char	*trans_ten(char *part, t_dict *diction);
char	*strcat_digit(char *result_temp, t_dict *diction, int num_row);
int		find_zero(char *arr);
void	check_zero(char *arr, t_dict *p);

#endif
