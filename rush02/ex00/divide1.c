/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejeon <chaejeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:13:37 by chaejeon          #+#    #+#             */
/*   Updated: 2022/02/20 21:00:31 by chaejeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char	*trans_one(char part_one, t_dict *diction)
{
	char	one_num[2];

	if (part_one == '0')
		return ("");
	one_num[0] = part_one;
	one_num[1] = '\0';
	return (check_dict(one_num, diction));
}

char	*trans_ten_ty(char *part, t_dict *diction)
{
	char	ten_num[3];
	char	*dict_word_ten;
	char	*dict_word_one;
	char	*result;

	ten_num[0] = part[0];
	ten_num[1] = '0';
	ten_num[2] = '\0';
	dict_word_ten = check_dict(ten_num, diction);
	if (!dict_word_ten)
		return (0);
	dict_word_one = trans_one(part[1], diction);
	if (!dict_word_one)
		return (0);
	result = ft_dup_strcat_space(dict_word_ten, dict_word_one);
	return (result);
}

char	*trans_ten_en(char *part, t_dict *diction)
{
	char	ten_num[3];
	char	*dict_word;

	ten_num[0] = part[0];
	ten_num[1] = part[1];
	ten_num[2] = '\0';
	dict_word = check_dict(ten_num, diction);
	if (!dict_word)
		return (0);
	return (dict_word);
}

char	*trans_ten(char *part, t_dict *diction)
{
	char	*dict_word;

	if (part[0] == '1')
		dict_word = trans_ten_en(part, diction);
	else if (part[0] == '0')
		dict_word = trans_one(part[1], diction);
	else
		dict_word = trans_ten_ty(part, diction);
	if (!dict_word)
		return (0);
	return (dict_word);
}

char	*trans_hund(char part_hund, t_dict *diction)
{
	char	*dict_word_num;
	char	*dict_word_100;
	char	hund_num[2];
	char	*result;

	if (part_hund == '0')
		result = "";
	else
	{
		hund_num[0] = part_hund;
		hund_num[1] = '\0';
		dict_word_num = check_dict(hund_num, diction);
		if (!dict_word_num)
			return (0);
		dict_word_100 = check_dict("100", diction);
		if (!dict_word_100)
			return (0);
		result = ft_dup_strcat_space(dict_word_num, dict_word_100);
	}
	return (result);
}
