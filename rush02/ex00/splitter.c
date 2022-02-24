/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:03:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/02/20 20:39:27 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include <stdlib.h>

int	check_dicterr(char *str);
int	sort_space(char *str);
int	save_key(char *str, t_dict *p);
int	save_val(char *str, t_dict *p);

int	fft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

void	next_struct(int *n, int *flag)
{
	(*n)++;
	*flag = 0;
}

void	malloc_p(t_dict *p, char *str, int n)
{
	p[n].key = (char *)malloc(sizeof(char) * (fft_strlen(str) + 1));
	p[n].value = (char *)malloc(sizeof(char) * \
			(fft_strlen(str) + 1));
}

int	splitter(char *str, t_dict *p)
{
	int		i;
	int		n;
	int		flag;

	i = 0;
	n = 0;
	flag = 0;
	if (check_dicterr(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
		{	
			flag = 1;
			malloc_p(p, &str[i], n);
			i += save_key(&str[i], &p[n]);
		}
		if (str[i] == ':')
			i += save_val(&str[i + 1], &p[n]);
		if (str[i] == '\n' && flag == 1)
			next_struct(&n, &flag);
		i++;
	}
	return (1);
}
