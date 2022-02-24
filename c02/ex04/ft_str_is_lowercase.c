/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:04:08 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:04:11 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lwr(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			return (1);
		else if (lwr(str[i]) == 0)
			return (0);
		i++;
	}
}
