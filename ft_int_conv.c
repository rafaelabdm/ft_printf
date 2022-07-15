/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:18:40 by rabustam          #+#    #+#             */
/*   Updated: 2022/07/01 14:16:03 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_numbers(int n)
{
	size_t	count;

	count = 1;
	if (n <= -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n >= 0 && n <= 9)
		return (count);
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_int_converter(int n, int size)
{
	char			*res;
	long int		n_value;
	unsigned int	char_n;

	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	n_value = n;
	if (n_value < 0)
		n_value *= -1;
	while (size)
	{
		char_n = n_value;
		while (char_n > 9)
			char_n = char_n % 10;
		res[--size] = char_n + 48;
		n_value = n_value / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

int	ft_itoa(int n)
{
	char		*str;
	size_t		size;

	size = ft_count_numbers(n);
	str = ft_int_converter(n, size);
	size = ft_putstr(str);
	free(str);
	return ((int)size);
}
