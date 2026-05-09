/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:59:12 by tsito             #+#    #+#             */
/*   Updated: 2026/05/03 16:19:14 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_specifier(va_list *args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(*args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(*args, char *));
	else if (c == 'p')
		len = ft_print_ptr(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		len = ft_print_nbr(va_arg(*args, int));
	else if (c == 'u')
		len = ft_print_uint(va_arg(*args, unsigned int));
	else if (c == 'x')
		len = ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len = ft_print_char('%');
	else if (c == '\0')
		len = -1;
	else
		len = ft_print_char(c);
	return (len);
}

static int	print_format(va_list *args, const char *format)
{
	int	i;
	int	len;
	int	ret;

	i = 0;
	len = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = print_specifier(args, format[i + 1]);
			if (format[i + 1])
				i += 2;
			else
				i++;
		}
		else
			len = ft_print_char(format[i++]);
		if (len < 0)
			return (len);
		ret += len;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	ret = print_format(&args, format);
	va_end(args);
	return (ret);
}
