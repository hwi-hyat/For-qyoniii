/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:21:41 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 21:21:43 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	initialized_arr(char **arr, int num_row)
{
	int		big_idx;
	int		small_idx;

	big_idx = 0;
	while (big_idx < num_row)
	{
		small_idx = 0;
		arr[big_idx] = (char *)malloc(sizeof(char) * 3);
		while (small_idx < 3)
		{
			arr[big_idx][small_idx] = '0';
			small_idx++;
		}
		big_idx++;
	}
}

char	**divide_arg(char *number, int num_row, int number_len)
{
	int		big_idx;
	int		small_idx;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (num_row));
	initialized_arr(arr, num_row);
	big_idx = 0;
	while (big_idx < num_row)
	{
		small_idx = 2;
		while (small_idx >= 0 && number[number_len - 1])
		{
			if (arr[big_idx][small_idx])
				arr[big_idx][small_idx] = number[number_len - 1];
			small_idx--;
			number_len--;
		}
		big_idx++;
	}
	return (arr);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str2)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
