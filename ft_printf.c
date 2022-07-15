/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:10:09 by rabustam          #+#    #+#             */
/*   Updated: 2022/07/04 20:05:09 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list ptr, const char format);

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		size;
	int		i;

	va_start(ptr, format);
	i = 0;
	size = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_format(ptr, format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (size);
}

static int	ft_format(va_list ptr, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(ptr, int));
	else if (format == 's')
		len = ft_putstr(va_arg(ptr, char *));
	else if (format == 'p')
		len = ft_ptr_conv(va_arg(ptr, unsigned long));
	else if (format == 'd')
		len = ft_itoa(va_arg(ptr, int));
	else if (format == 'i')
		len = ft_itoa(va_arg(ptr, int));
	else if (format == 'u')
		len = ft_unsigned_itoa(va_arg(ptr, int));
	else if (format == 'x')
		len = ft_itoa_base((unsigned int)va_arg(ptr, int), 16, 'l');
	else if (format == 'X')
		len = ft_itoa_base((unsigned int)va_arg(ptr, int), 16, 'u');
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}
