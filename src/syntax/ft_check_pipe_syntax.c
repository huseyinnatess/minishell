/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:17 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 14:40:48 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Pipe karakterinin başta veya sonda olup olmadığını kontrol ediyor.
int ft_check_pipe_sytax(t_minishell *data)
{
    if (data -> raw_cmd[0] == '|')
    {
        ft_putstr_fd("minishell: parse error near `|'\n", 2);
        return (1);
    }
    if (data -> raw_cmd[ft_strlen(data -> raw_cmd) - 1] == '|')
    {
       ft_putstr_fd("pipe>\n", 2);
        return (1);
    }
    return (0);
}