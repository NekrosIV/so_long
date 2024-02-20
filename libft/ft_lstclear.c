/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:05:06 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 16:13:39 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* t_lstclear.c : Supprime et libère la mémoire
	de tous les éléments de la liste, ainsi que
	le pointeur de liste initial. */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*del_elm;

	del_elm = *lst;
	while (del_elm)
	{
		next = del_elm->next;
		del(del_elm->content);
		free(del_elm);
		del_elm = next;
	}
	*lst = 0;
}
