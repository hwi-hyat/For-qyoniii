/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:39:44 by siykim            #+#    #+#             */
/*   Updated: 2022/02/05 17:39:45 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	comparer(int i, int *tab)
{
	int	temp;
	int	j;
	int	l;

	l = i;
	temp = tab[i];
	j = 0;
	while (j < i)
	{
		if (temp < tab[j])
		{
			while (l > j)
			{
				tab[l] = tab[l - 1];
				l--;
			}
			tab[j] = temp;
			break ;
		}
		j++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		comparer(i, tab);
		i++;
	}
}
