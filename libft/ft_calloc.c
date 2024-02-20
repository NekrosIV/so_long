/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:23:47 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 16:42:13 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/* ft_calloc: Alloue et initialise une zone de mémoire */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0)
	{
		if (nmemb > INT_MAX / size)
			return (0);
	}
	p = malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *s;
// 	s = ft_calloc(INT_MAX + 6, sizeof(char));
// 	printf("s = (%s)", s);
// }