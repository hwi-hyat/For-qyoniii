/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:02:51 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:02:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alp(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			return (1);
		else if (alp(str[i]) == 0)
			return (0);
		i++;
	}
}
