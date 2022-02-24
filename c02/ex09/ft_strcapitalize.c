/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:08:30 by siykim            #+#    #+#             */
/*   Updated: 2022/02/12 02:18:51 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_it_alphanumeric(char c)
{
	if (47 < c && c < 58)
		return (1);
	else if (64 < c && c < 91)
		return (1);
	else if (96 < c && c < 123)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (str[i] != 0)
	{
		if (first == 1)
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				str[i] -= 32;
				first = 0;
			}
			else if (is_it_alphanumeric(str[i]))
				first = 0;
		}
		else if (first == 0 && 'A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		else if (is_it_alphanumeric(str[i]) == 0)
			first = 1;
		i++;
	}
	return (str);
}
