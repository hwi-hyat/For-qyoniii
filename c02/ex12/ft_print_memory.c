/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:11:47 by siykim            #+#    #+#             */
/*   Updated: 2022/02/12 03:24:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	char_hex_converter(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	char_out(void *addr, int size)
{
	unsigned char	*c;
	int				i;

	i = 0;
	while (i < size)
	{
		c = addr + i;
		if (*c < 32 || 126 < *c)
			write(1, ".", 1);
		else
			write(1, c, 1);
		i++;
	}
}

void	hex_char_out(void *addr, int size)
{
	int				i;
	unsigned char	*c;

	i = 0;
	while (i < size)
	{
		c = addr + i;
		if (i % 2 == 0)
			write(1, " ", 1);
		char_hex_converter(*c);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
	char_out(addr, size);
}

void	hexadecimal_out(void *addr, int size)
{
	unsigned long long	i_addr;
	char				out[17];
	char				*hex;
	 int				i;

	i = 15;
	hex = "0123456789abcdef";
	i_addr = (unsigned long long)addr;
	while (i >= 0)
	{
		out[i] = 0;
		out[i] = hex[i_addr % 16];
		i_addr /= 16;
		i--;
	}
	write(1, out, 16);
	write(1, ":", 1);
	hex_char_out(addr, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		if (size - i < 16 && i % 16 == 0)
		{
			hexadecimal_out(addr + i, size - i);
			write(1, "\n", 1);
			break ;
		}
		else if (i % 16 == 0)
		{
			hexadecimal_out(addr + i, 16);
			write(1, "\n", 1);
		}
		i++;
	}
	return (addr);
}
