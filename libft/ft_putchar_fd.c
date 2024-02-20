/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:09:05 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:39:34 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putstr_fd: Affiche une chaîne sur un descripteur de fichier */
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	ft_putchar_fd('p', fd);
// 	ft_putchar_fd('\n', fd);
// 	close(fd);
// }