/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:44:40 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 09:36:23 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_atoi: Convertit une chaîne en un entier */

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	nbr;

	i = 0;
	nbr = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("nbr = %d\n", ft_atoi("      -2564"));
// }