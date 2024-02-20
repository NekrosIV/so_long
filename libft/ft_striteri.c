/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:42:51 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 11:35:30 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_striteri: Applique une fonction à chaque caractère d'une chaîne
	avec son indice.*/
// #include <stdio.h>
// void	add_five(unsigned int index, char *c)
// {
// 	unsigned int	i;
// 	*c += 5;
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char str[] = "Bonjour";

// 	printf("Avant : %s\n", str);
// 	ft_striteri(str, &add_five);
// 	printf("Après : %s\n", str);
// }