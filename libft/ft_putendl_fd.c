/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:21:16 by kasingh           #+#    #+#             */
/*   Updated: 2024/02/08 17:45:17 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* ft_putendl_fd: Affiche une chaîne suivie d'un saut de
ligne sur un descripteur de fichier */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	s = "bonjour";
// 	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	ft_putendl_fd(s, fd);
// 	close(fd);
// }
