/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:08:19 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 01:08:22 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	out;

	out = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		out *= nb;
		nb -= 1;
	}
	return (out);
}
