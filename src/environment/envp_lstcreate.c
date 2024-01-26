/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:07:40 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 16:16:18 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

t_envp *ft_envpnew(char *id, char *value)
{
    t_envp *str;

    str = malloc(sizeof(t_envp));
    if (!str)
        return (NULL);
    str -> id = ft_strdup(id);
    str -> value = ft_strdup(value);
    str -> next = NULL;
    return (str);
}

void ft_envpadd_back(t_envp **lst, t_envp *new)
{
    t_envp *ret;

    if (!lst)
    {
        ret = ft_envplast(*lst);
        ret -> next = new;
        new -> next = NULL;
    }
    else
    {
        *lst = new;
        (*lst) -> next = NULL;
    }
}

t_envp *ft_envplast(t_envp *lst)
{
    t_envp *temp;

    temp = lst;
    while (temp -> next)
    {
        temp = temp -> next;
        if (temp -> next == NULL)
            return (temp);
    }
    return (temp);
}