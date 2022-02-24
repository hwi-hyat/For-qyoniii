/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:09:20 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 01:09:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	out;

	i = 0;
	out = 1;
	if (power < 0)
		return (0);
	while (i < power)
	{
		out *= nb;
		i++;
	}
	return (out);
}
