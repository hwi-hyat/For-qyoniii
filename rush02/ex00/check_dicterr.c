/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dicterr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:50:00 by jinypark          #+#    #+#             */
/*   Updated: 2022/02/20 20:08:50 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_phase_one(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ':' && str[i] != ' ')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	while (str[i] != ':')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (i + 1);
}

int	check_phase_two(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		if (str[i] == ' ')
		{
			while (str[i] != '\n')
			{
				if (str[i] != ' ')
					return (0);
				i++;
			}
			return (i + 1);
		}
		else if (str[i] < 32 || str[i] >= 127)
			return (0);
		i++;
	}
	return (i + 1);
}

int	check_dicterr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}	
		if (check_phase_one(&str[i]) == 0)
			return (0);
		else
			i += check_phase_one(&str[i]);
		if (check_phase_two(&str[i]) == 0)
			return (0);
		else
			i += check_phase_two(&str[i]);
	}
	return (1);
}
