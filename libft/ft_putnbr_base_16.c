/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:40:52 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/18 12:35:40 by kasingh          ###   ########.fr       */
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
