/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1check_input2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:21:22 by tson              #+#    #+#             */
/*   Updated: 2022/02/24 01:35:24 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	input_three_condition(char *str, t_info *p_info, int len)
{
	if (!(str[len - 1] >= 32 && str[len - 1] <= 126))
		return (0);
	p_info -> full = str[len - 1];
	if (!(str[len - 2] >= 32 && str[len - 2] <= 126))
		return (0);
	p_info -> obs = str[len - 2];
	if (!(str[len - 3] >= 32 && str[len - 3] <= 126))
		return (0);
	p_info -> empty = str[len - 3];
	return (1);
}

int	check_condition(char *str, t_info *p_info)
{
	int	idx;
	int	len;

	len = str_len(str);
	if (len < 4)
		return (0);
	if (input_three_condition(str, p_info, len) == 0)
		return (0);
	if (is_same_char(p_info -> full, p_info -> obs)
		|| is_same_char(p_info -> full, p_info -> empty)
		|| is_same_char(p_info -> obs, p_info -> empty))
		return (0);
	idx = 0;
	while (idx < len - 3)
	{
		if (!(str[idx] >= 48 && str[idx] <= 57))
			return (0);
		p_info -> len *= 10;
		p_info -> len += str[idx] - 48;
		idx++;
	}
	if (p_info -> len == 0)
		return (0);
	return (1);
}

int	check_first_line(char *str, t_info *p_info)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!((str[idx] == p_info -> empty) || (str[idx] == p_info -> obs)))
			return (0);
		idx++;
	}
	return (idx);
}

int	check_else_line(char *str, t_info *p_info)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!((str[idx] == p_info -> empty) || (str[idx] == p_info -> obs)))
			return (0);
		idx++;
	}
	if (idx != p_info -> wid)
		return (0);
	return (1);
}
