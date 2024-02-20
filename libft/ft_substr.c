/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:45:33 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 11:01:05 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*ft_substr: Extrait une sous-chaîne d'une chaîne */
char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	if (start < (unsigned int)ft_strlen(src))
	{
		size = ft_strlen(src) - start;
		if (size > len)
			size = len;
	}
	result = malloc((size + 1) * sizeof(char));
	if (result == 0)
		return (0);
	while (src[i] && i < start)
		i++;
	while (src[i] && j < len)
		result[j++] = src[i++];
	result[j] = '\0';
	return (result);
}
