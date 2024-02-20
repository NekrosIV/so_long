/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:03:20 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/25 17:06:36 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_16(unsigned long int n, char *base, int len)
{
	if (n >= 16)
	{
		len = ft_putnbr_base_16(n / 16, base, len);
		len = ft_putnbr_base_16(n % 16, base, len);
	}
	else
	{
		len = len + ft_print_char(base[n]);
	}
	return (len);
}

int	ft_check_format(char c, va_list arg)
{
	int		len;
	char	*x;
	char	*bigx;

	len = 0;
	x = "0123456789abcdef";
	bigx = "0123456789ABCDEF";
	if (c == 'c')
		len = len + ft_print_char(va_arg(arg, int));
	else if (c == 's')
		len = len + ft_print_str(va_arg(arg, char *));
	else if (c == 'p')
		len = len + ft_print_p(va_arg(arg, unsigned long int));
	else if (c == 'i' || c == 'd')
		len = len + ft_print_int(va_arg(arg, int));
	else if (c == 'u')
		len = len + ft_print_unsigned_int(va_arg(arg, unsigned int), 0);
	else if (c == 'x')
		len = len + ft_putnbr_base_16(va_arg(arg, unsigned int), x, 0);
	else if (c == 'X')
		len = len + ft_putnbr_base_16(va_arg(arg, unsigned int), bigx, 0);
	else if (c == '%')
		len = len + ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (format == 0)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_check_format(format[++i], arg);
		}
		else
			len = len + ft_print_char(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
// #include "ft_printf.h"
// #include <stdio.h>
// #define TEST "[%x]\n", "oui"

// int	main(void)
// {
// 	int i = ft_printf(TEST);
// 	int j = ft_printf(TEST);

// 	printf("i = %d\nj = %d\n", i, j);
// 	return (0);
// }