/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:39:58 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 14:44:58 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/environment.h"

void ft_free_envp(t_envp *head)
{
    t_envp *temp;

    temp = head;
    while (temp != NULL)
    {
        if (temp -> id)
            free(temp -> id);
        if (temp -> value)
            free(temp -> value);
        temp = temp -> next;
    }
}