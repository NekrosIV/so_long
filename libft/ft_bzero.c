/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:04 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:04:29 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_bzero: Met à zéro une zone de mémoire */
void	ft_bzero(void *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char d[] = "bonjour";
// 	int i = 0;

// 	printf("%s\n", d);
// 	ft_bzero(d, 8);
// 	printf("[%s]\n", d);
// }