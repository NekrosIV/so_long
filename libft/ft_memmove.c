/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:05:40 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:17:24 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_memmove: Copie une zone de mémoire, même si les zones se chevauchent. */
void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*c_dest;
	const char	*c_src;

	i = 0;
	c_dest = (char *)dest;
	c_src = (char *)src;
	if (src < dest)
	{
		i = size;
		while (i > 0)
		{
			c_dest[i - 1] = c_src[i - 1];
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}
