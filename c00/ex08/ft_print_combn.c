/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:57:58 by siykim            #+#    #+#             */
/*   Updated: 2022/02/03 17:58:01 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	counter(char out[10], int n, int i, int jaritsoo)
{
	while (out[i] <= 58 - n)
	{
		if (n != 1)
		{
			out[i + 1] = out[i] + 1;
			counter(out, n - 1, i + 1, jaritsoo);
		}
		else
		{
			write(1, out, jaritsoo);
			if (out[0] != 58 - jaritsoo)
				write(1, ", ", 2);
		}
		out[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	out[10];

	out[0] = 48;
	counter(out, n, 0, n);
}
