/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:14:58 by kasingh           #+#    #+#             */
/*   Updated: 2024/02/15 18:01:35 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_join_and_free(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup_gnl(s2));
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_new_line(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	cpy = malloc((i + 1) * sizeof(char));
	if (cpy == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*result(char *storage, int bytes_read)
{
	char	*line;

	line = ft_new_line(storage);
	free(storage);
	if (!line)
	{
		free(line);
		return (0);
	}
	if (bytes_read == 0 && ft_strlen(line) < 1)
	{
		free(line);
		return (0);
	}
	return (line);
}

void	ft_new_strcpy(char *s1)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			break ;
		i++;
	}
	i++;
	j = 0;
	while (s1[i])
	{
		s1[j] = s1[i];
		i++;
		j++;
	}
	s1[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*storage;
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bytes_read = 1;
	storage = NULL;
	if (ft_strchr_gnl(buffer, '\n') != 0)
	{
		storage = ft_strdup_gnl(ft_strchr_gnl(buffer, '\n') + 1);
		ft_new_strcpy(buffer);
	}
	while (!ft_strchr_gnl(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		buffer[bytes_read] = '\0';
		storage = ft_join_and_free(storage, buffer);
	}
	return (result(storage, bytes_read));
}

// int	main(void)
// {
// 	int fd;
// 	ssize_t bytesRead;
// 	char *result;
// 	fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
// 	// fd = 1000;
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		result = get_next_line(fd);
// 		printf("s = {%s}\n", result);
// 		if (result <= 0)
// 		{
// 			free(result);
// 			break ;
// 		}
// 		free(result);
// 	}
// 	// Ferme le fichier
// 	close(fd);
// }