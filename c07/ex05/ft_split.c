/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:26 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 12:20:31 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_counter(char *str, char *charset)
{
	int	i;
	int	flag;
	int	cnt;

	i = 0;
	flag = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		if (sep(str[i], charset) == 0)
			flag = 1;
		if (flag && (sep(str[i + 1], charset) == 1 || str[i + 1] == 0))
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

int	len_cnt(char *str, char *charset)
{
	int	i;

	i = 0;
	while (sep(str[i], charset) == 0 && str[i] != 0)
		i++;
	return (i);
}

void	filler05(char *out, char *str, char *charset)
{
	int	i;

	i = 0;
	while (sep(str[i], charset) != 1 && str[i] != 0)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	int		wi;
	char	**out;

	i = 0;
	wi = 0;
	words = word_counter(str, charset);
	out = (char **)malloc(sizeof(char *) * (words + 1));
	while (str[i] != 0)
	{
		if (sep(str[i], charset) == 0)
		{
			out[wi] = (char *)malloc(sizeof(char) * (len_cnt(&str[i], charset) + 1));
			filler05(out[wi], &str[i], charset);
			wi++;
			i += len_cnt(&str[i], charset);
		}
		i++;
	}
	out[wi] = NULL;
	return (out);
}
