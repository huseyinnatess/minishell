/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:11:28 by huates            #+#    #+#             */
/*   Updated: 2024/02/05 14:12:48 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Gelen variable'ın envp'de olup olmadığını kontrol ediyor.
int ft_isvariable(t_envp *envp, char *variable)
{
    t_envp *temp;

    temp = envp;
    while (temp)
    {
        if (ft_strcmp(temp -> id, variable) == 0)
            return (1);
        temp = temp -> next;
    }
    return (0);
}