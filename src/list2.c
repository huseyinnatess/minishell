/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:48:08 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/17 18:43:37 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Takes as a parameter a node and frees the memory of the node’s content using
// the function 'del' given as a parameter and free the node. The memory of
// 'nxt' and 'pre' must not be freed.
void	lst_delone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->val);
	free(lst);
}

// Removes and frees the given 'to_rm' node from the list, using the function 
// 'del' and free(3). 
void	lst_rm_one(t_list **lst, t_list *to_rm, void (*del)(void *))
{
	if (*lst == to_rm)
		*lst = (*lst)->nxt;
	lst_link(to_rm->pre, to_rm->nxt);
	lst_delone(to_rm, del);
}

// Removes and frees 'n' list nodes starting from 'to_rm', using the function 
// 'del' and free(3). 
void	lst_rm_many(t_list **lst, t_list *to_rm, size_t n, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (!*lst & !to_rm)
		return ;
	if (*lst == to_rm)
		*lst = lst_move(*lst, n);
	prev = to_rm->pre;
	next = to_rm;
	while (n-- > 0 && next)
	{
		to_rm = next;
		next = next->nxt;
		lst_delone(to_rm, del);
	}
	lst_link(prev, next);
}

// Returns the n-th node moving forward from 'node'.
// If 'n' is negative, moves backwards.
t_list	*lst_move(t_list *node, int n)
{
	while (n != 0)
	{
		if (!node)
			return (NULL);
		if (n > 0)
		{
			node = node->nxt;
			--n;
		}
		else
		{
			node = node->pre;
			++n;
		}
	}
	return (node);
}

// Counts and returns the amount of nodes in a list.
size_t	lst_size(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->nxt;
		size++;
	}
	return (size);
}