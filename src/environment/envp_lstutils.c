/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_lstutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:15:38 by huates            #+#    #+#             */
/*   Updated: 2024/02/05 14:16:09 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_envp *ft_find_id(t_envp *envp, char *id)
{
    t_envp *temp;

    temp = envp;
    while (temp)
    {
        if (ft_strcmp(temp -> id, id) == 0)
            return (temp);
        temp = temp -> next;
    }
    return (NULL);
}