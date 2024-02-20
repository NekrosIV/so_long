/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:56:32 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 11:21:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/* ft_lstnew.c : Alloue et renvoie un nouvel élément
	de liste initialisé avec la valeur passée en paramètre,
	et son pointeur suivant initialisé à NULL.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == 0)
		return (0);
	new_elem->content = content;
	new_elem->next = 0;
	return (new_elem);
}
