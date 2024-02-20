/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:31:25 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/13 13:54:59 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count_word(char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (0);
}

static char	**ft_new_word(char const *str, char c, char **result)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[k])
	{
		if (str[k] != c)
		{
			j = 0;
			result[i] = malloc(ft_word_len((char *)(str + k), c) * sizeof(char)
					+ 1);
			if (result[i] == 0)
				return (ft_free(result, i));
			while (str[k] != '\0' && str[k] != c)
				result[i][j++] = str[k++];
			result[i++][j] = '\0';
		}
		else
			k++;
	}
	result[i] = 0;
	return (result);
}

/* ft_split: Divise une chaîne en mots */
char	**ft_split(char const *str, char c)
{
	char	**result;

	result = malloc((ft_count_word((char *)str, c) + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	result = ft_new_word(str, c, result);
	return (result);
}
