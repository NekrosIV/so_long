/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:20:50 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/20 09:36:10 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_sep(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static void	*ft_new_str(const char *s1, char const *set, int len_flage,
		char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && ft_is_sep(s1[i], set))
		i++;
	while (s1[i] && i < len_flage + 1)
		result[j++] = s1[i++];
	result[j] = '\0';
	return (result);
}

/* ft_strtrim: Supprime les sep au début et à la fin d'une chaîne.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		j;
	int		len_flage;
	int		size_malloc;

	len_flage = 0;
	size_malloc = 0;
	j = 0;
	while (s1[len_flage] && ft_is_sep(s1[len_flage++], set))
		j++;
	len_flage = ft_strlen(s1);
	while (len_flage != 0 && ft_is_sep(s1[--len_flage], set) == 1)
		j++;
	if ((int)ft_strlen(s1) - j > 0)
		size_malloc = ft_strlen(s1) - j;
	result = malloc((size_malloc + 1) * sizeof(char));
	if (result == 0)
		return (0);
	return (ft_new_str(s1, set, len_flage, result));
}
