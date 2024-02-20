/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:34:06 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:59:33 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_strnstr: Cherche la première occurrence d'une
	sous-chaîne dans une chaîne limitée */
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)(str + j));
	while (str[i] && i < n)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] == str[i + j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)(str + i));
				j++;
			}
		}
		i++;
	}
	return (0);
}
