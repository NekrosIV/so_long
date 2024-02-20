/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:16:47 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:48:57 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* ft_strdup: Duplique une chaîne de caractères */
char	*ft_strdup(const char *src)
{
	int		size_src;
	int		i;
	char	*cpy;

	i = 0;
	size_src = ft_strlen((char *)src);
	cpy = malloc((size_src + 1) * sizeof(char));
	if (cpy == 0)
		return (0);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
