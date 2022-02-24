/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:07:09 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:07:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	up(char c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		str [i] = up(str[i]);
		i++;
	}
	return (str);
}
