/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:05:49 by siykim            #+#    #+#             */
/*   Updated: 2022/02/16 15:28:09 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_it_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	base_check05(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (9 <= base[i] && base[i] <= 15))
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	translator05(char *num, char *base, int len)
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
				out += j;
			j++;
		}
		i++;
	}
	return (out);
}

int	ft_atoi05(char *str, int neg, char *base, int len)
{
	 int	i;
	char	*out;
	 int	num;

	i = 0;
	while ((9 <= str[i] && str[i] <= 15) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	out = &str[i];
	num = translator05(out, base, len);
	if (neg % 2 == 1)
		num *= -1;
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	neg;
	int	out;

	neg = 0;
	if (base_check05(base) == 0)
		return (0);
	len = 0;
	while (base[len] != 0)
		len++;
	if (len <= 1)
		return (0);
	out = ft_atoi05(str, neg, base, len);
	return (out);
}
