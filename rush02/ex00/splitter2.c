/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:34:59 by jinypark          #+#    #+#             */
/*   Updated: 2022/02/20 20:37:51 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "h.h"

int	sort_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	save_key(char *str, t_dict *p)
{
	int		i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		p->key[i] = str[i];
		i++;
	}
	if (i != 0)
		p->key[i] = '\0';
	else
		p->key[i] = 'n';
	return (i);
}

int	save_val(char *str, t_dict *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i += sort_space(&str[i]);
	while (str[i] != '\n' && str[i] != ' ')
	{
		p->value[j] = str[i];
		i++;
		j++;
	}
	if (i != 0)
		p->value[j] = '\0';
	i += sort_space(&str[i]);
	return (i);
}
