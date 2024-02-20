/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:42:50 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:13:58 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	*ft_int_min(char *result, int n, int digit)
{
	int	i;
	int	s;

	i = digit;
	s = 1;
	while (i > s)
	{
		result[--i] = (n % 10 * -1) + '0';
		n = n / 10;
	}
	result[--i] = '-';
	result[digit] = '\0';
	return (result);
}

static void	*ft_new_str(char *result, int n, int digit)
{
	int	i;
	int	s;

	s = 0;
	i = digit;
	if (n < 0)
	{
		n = n * -1;
		s++;
		result[0] = '-';
	}
	while (s < i)
	{
		result[--i] = n % 10 + '0';
		n = n / 10;
	}
	result[digit] = '\0';
	return (result);
}

/* ft_itoa: Convertit un entier en chaîne de caractères */
char	*ft_itoa(int n)
{
	char	*result;
	int		digit;

	digit = ft_count_digit(n);
	result = malloc((digit + 1) * sizeof(char));
	if (result == 0)
		return (0);
	if (n == -2147483648)
		return (ft_int_min(result, n, digit));
	return (ft_new_str(result, n, digit));
}

// #include <stdio.h>
// int	main(void)
// {
// 	int i = -9853443;
// 	printf("i = %s\n", ft_itoa(i));
// }