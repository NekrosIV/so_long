/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:14:35 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:23:17 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enqueue(t_node **head, t_position pos)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_node->pos = pos;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

t_position	dequeue(t_node **head)
{
	t_node		*temp;
	t_position	pos;

	if (*head == NULL)
		exit(EXIT_FAILURE);
	temp = *head;
	pos = temp->pos;
	*head = (*head)->next;
	free(temp);
	return (pos);
}

bool	is_empty(const t_node *head)
{
	return (head == NULL);
}
