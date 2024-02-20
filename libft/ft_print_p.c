/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:26:00 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/18 12:32:36 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(unsigned long int n)
{
	unsigned long int	p;
	int					len;

	len = 0;
	p = n;
	if (p == 0)
	{
		len = ft_print_str("(nil)");
		return (len);
	}
	len = ft_print_str("0x");
	len = ft_putnbr_base_16(p, "0123456789abcdef", len);
	return (len);
}
