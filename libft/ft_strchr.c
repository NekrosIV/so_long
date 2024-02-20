/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:06:09 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:45:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strchr: Cherche la première occurrence d'un caractère dans une chaîne. */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	return (0);
}
