/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:20:15 by siykim            #+#    #+#             */
/*   Updated: 2022/02/12 19:57:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	len;

	i = argc - 1;
	while (i > 0)
	{
		len = 0;
		while (argv[i][len] != 0)
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
