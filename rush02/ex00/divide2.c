/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejeon <chaejeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:01:07 by chaejeon          #+#    #+#             */
/*   Updated: 2022/02/20 21:01:54 by chaejeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "h.h"

void	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

void	print_result(char **result, int num_row)
{
	while (num_row > 0)
	{
		print_str(result[num_row - 1]);
		if (*result[num_row - 1] && num_row != 1)
			write(1, " ", 1);
		num_row--;
	}
}

void	print_number(char *number, t_dict *diction)
{
	char	**divided;
	char	**result;
	int		num_row;
	int		idx;

	num_row = arr_big_len(number);
	divided = divide_arg(number, num_row, ft_strlen(number));
	result = (char **)malloc(sizeof(char *) * (num_row));
	if (!trans_num(divided, result, diction, num_row))
		print_dict_error();
	else
		print_result(result, num_row);
	write(1, "\n", 1);
	idx = 0;
	while (idx < num_row)
		free(result[idx++]);
	free(result);
}

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*check_dict(char *key, t_dict *diction)
{
	while ((diction -> key) != 0)
	{
		if (!ft_strcmp(diction -> key, key))
			return (diction -> value);
		diction++;
	}
	return (0);
}
