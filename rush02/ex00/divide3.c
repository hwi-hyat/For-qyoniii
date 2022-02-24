/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejeon <chaejeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:00:58 by chaejeon          #+#    #+#             */
/*   Updated: 2022/02/20 21:02:43 by chaejeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "h.h"

char	*trans_part(char *part, t_dict *diction, int num_row)
{
	char	*result;
	char	*dict_word_hund;
	char	*dict_word_ten;

	dict_word_hund = trans_hund(*part, diction);
	if (!dict_word_hund)
		return (0);
	dict_word_ten = trans_ten(part + 1, diction);
	if (!dict_word_ten)
		return (0);
	result = ft_dup_strcat_space(dict_word_hund, dict_word_ten);
	if (*dict_word_hund)
		free(dict_word_hund);
	if (part[1] != '1' && part[1] != '0')
		free(dict_word_ten);
	if (num_row != 0 && *result)
		return (strcat_digit(result, diction, num_row));
	return (result);
}

int	trans_num(char **devided, char **result, t_dict *diction, int num_row)
{
	int		cnt;
	char	*translated_part;

	cnt = 0;
	while (cnt < num_row)
	{
		translated_part = trans_part(devided[cnt], diction, cnt);
		if (!translated_part)
			return (0);
		result[cnt] = translated_part;
		cnt++;
	}
	return (1);
}

char	*trans_digit(int cnt, t_dict *diction)
{
	char	*dict_word_digit;
	char	*digit_arr;
	int		idx;

	idx = 0;
	digit_arr = (char *)malloc(3 * cnt + 2);
	digit_arr[3 * cnt + 1] = '\0';
	while (idx < 3 * cnt + 1)
		digit_arr[idx++] = '0';
	digit_arr[0] = '1';
	dict_word_digit = check_dict(digit_arr, diction);
	free(digit_arr);
	if (dict_word_digit == 0)
		return (0);
	return (dict_word_digit);
}

char	*strcat_digit(char *result_temp, t_dict *diction, int num_row)
{
	char	*dict_word_digit;
	char	*result;

	dict_word_digit = trans_digit(num_row, diction);
	if (!dict_word_digit)
		return (0);
	result = ft_dup_strcat_space(result_temp, dict_word_digit);
	free(result_temp);
	return (result);
}
