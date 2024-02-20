/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:17:05 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 14:57:44 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_strlcat: Concatène deux chaînes avec une limite de taille */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_d;
	size_t	size_c;
	size_t	i;

	size_d = 0;
	size_c = 0;
	i = 0;
	while (dest[size_d] && size_d < size)
		size_d++;
	while (src[size_c])
		size_c++;
	if (size_d >= size)
		return (size + size_c);
	while (src[i] && size_d + i < size - 1)
	{
		dest[size_d + i] = src[i];
		i++;
	}
	dest[size_d + i] = '\0';
	return (size_d + size_c);
}
