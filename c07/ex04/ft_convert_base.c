/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:14 by siykim            #+#    #+#             */
/*   Updated: 2022/02/22 19:34:25 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	str_len(char *str);
int	base_check(char *base);
int	is_it_base(char c, char *base);

int	translator_from(char *num, char *base, int len)
{
	int	i;
	int	j;
	int	out;

	i = 0;
	out = 0;
	while (is_it_base(num[i], base) != 0)
	{
		out *= len;
		j = 0;
		while (j < len)
		{
			if (num[i] == base[j])
			{
				out += j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (out);
}

int	ruler(int nbr, char *base, int neg)
{
	int	i;
	int	len;

	i = 0;
	len = str_len(base);
	while (1)
	{
		if (nbr == 0 && nbr % len == 0)
		{
			if (neg == -1)
				i++;
			break ;
		}
		nbr /= len;
		i++;
	}
	return (i - 1);
}

char	*translator_to(int nbr, char *base, int neg)
{
	int		i;
	int		len;
	char	*mal;

	i = ruler(nbr, base, neg);
	mal = (char *)malloc(sizeof(char) * (i + 2));
	mal[i + 1] = 0;
	len = str_len(base);
	while (i >= 0)
	{
		if (nbr == 0 && nbr % len == 0)
		{
			if (neg == -1)
			{
				mal[i] = '-';
				i--;
			}
			break ;
		}
		mal[i] = base[nbr % len];
		nbr /= len;
		i--;
	}
	return (mal);
}

int	ft_atoi(char *str, char *base, int len, int *neg)
{
	int		i;
	char	*out;
	int		num;

	i = 0;
	while ((9 <= str[i] && str[i] <= 15) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*neg *= -1;
		i++;
	}
	out = &str[i];
	num = translator_from(out, base, len);
	return (num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n_from;
	int		n_to;
	int		num;
	int		neg;
	char	*out;

	neg = 1;
	n_from = base_check(base_from);
	n_to = base_check(base_to);
	if (n_from < 2 || n_to < 2)
		return (0);
	num = ft_atoi(nbr, base_from, n_from, &neg);
	if (num == 0)
	{
		out = (char *)malloc(sizeof(char) * 2);
		out[0] = base_to[0];
		out[1] = 0;
		return (out);
	}
	out = translator_to(num, base_to, neg);
	return (out);
}
