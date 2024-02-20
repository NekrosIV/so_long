/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:29:07 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/18 12:32:43 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_int(unsigned int n, int len)
{
	if (n >= 10)
	{
		len = ft_print_unsigned_int(n / 10, len);
		len = ft_print_unsigned_int(n % 10, len);
	}
	else
	{
		len = len + ft_print_char(n + '0');
	}
	return (len);
}
