/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:16:44 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:18:08 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_memset: Remplit une zone de mémoire avec un octet particulier */
void	*ft_memset(void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(char *)(s + i) = (char)c;
		i++;
	}
	return (s);
}
