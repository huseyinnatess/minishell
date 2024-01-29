/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:38:40 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 14:33:50 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char **ft_malloc_envp_array(char *envp[])
{
    int i;
    char **array;

    i = -1;
    array = malloc(sizeof(char *) * (ft_array_size(envp) + 1));
    while (envp[++i])
        array[i] = ft_strdup(envp[i]);
    array[i] = NULL;
    return (array);
}

// envp yi linked list e çeviriyor
int init_envp(t_minishell *data, char *envp[])
{
    int i;
    int count;
    char **split;
    t_envp *temp;

    i = 0;
    count = ft_array_size(envp);
    if (!count)
        return (write(2, "Error: init_env\n", 16));
    data -> lstenv = NULL;
    data -> env = ft_malloc_envp_array(envp);
    if (!data -> env)
        return (write(2, "Error: init_env\n", 16));
    while (i < count)
    {
        split = ft_split_envp(envp[i]);
        temp = ft_envpnew(split[0], split[1]);
        if (temp)
            ft_envpadd_back(&data -> lstenv, temp);
        ft_array_free(split, ft_array_size(split));
        i++;
    }
    return (0);
}