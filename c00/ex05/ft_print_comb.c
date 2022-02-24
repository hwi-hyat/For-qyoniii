/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:11:45 by siykim            #+#    #+#             */
/*   Updated: 2022/02/03 14:15:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	output[5];

	output[0] = 48;
	output[3] = ',';
	output[4] = ' ';
	while (output[0] <= 54)
	{
		output[1] = output[0] + 1;
		while (output[1] <= 56)
		{
			output[2] = output[1] + 1;
			while (output[2] <= 57)
			{
				write(1, &output, 5);
				output[2]++;
			}
			output[1]++;
		}
		output[0]++;
	}
	write(1, "789", 3);
}
