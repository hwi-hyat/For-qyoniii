/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:15 by siykim            #+#    #+#             */
/*   Updated: 2022/02/03 15:13:19 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	add_one1(char sip, char il, char out[7])
{
	il++;
	if (il == 58)
	{
		il = 48;
		sip++;
	}
	out[0] = sip;
	out[1] = il;
}

void	add_one2(char sip, char il, char out[7])
{
	il++;
	if (il == 58)
	{
		il = 48;
		sip++;
	}
	out[3] = sip;
	out[4] = il;
}

void	ft_print_comb2(void)
{
	char	out[7];

	out[2] = ' ';
	out[5] = ',';
	out[6] = ' ';
	out[0] = 48;
	out[1] = 48;
	while (1)
	{
		add_one2(out[0], out[1], out);
		while (out[3] < 58)
		{
			write(1, &out, 7);
			add_one2(out[3], out[4], out);
		}
		add_one1(out[0], out[1], out);
		if (out[0] == '9' && out [1] == '8')
			break ;
	}
	write(1, "98 99", 5);
}
