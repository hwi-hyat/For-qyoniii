/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:58:38 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 21:58:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int	find_zero(char *arr)
{
	while (*arr)
		if (*arr++ != '0')
			return (0);
	return (1);
}

void	check_zero(char *arr, t_dict *p)
{
	char	*zero;

	if (find_zero(arr))
	{
		zero = check_dict("0", p);
		if (zero == 0)
			write(1, "Dict Error\n", 11);
		else
		{
			write(1, zero, ft_strlen(zero));
			write(1, "\n", 1);
		}
	}
	else
		print_number(arr, p);
}
