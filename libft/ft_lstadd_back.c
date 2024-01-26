/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:16 by huates            #+#    #+#             */
/*   Updated: 2023/10/18 15:29:12 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (list->next)
	{
		list = list->next;
	}
	list->next = new;
}
