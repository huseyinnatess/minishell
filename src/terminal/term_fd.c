/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:59:08 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 14:00:59 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int init_term_fd(t_minishell *data)
{
    data -> std_in = dup(STDIN_FILENO);
    data -> std_out = dup(STDOUT_FILENO);
    if (data -> std_in == -1 || data -> std_out == -1)
    {
        perror("Error: dup");
        return (1);
    }
    return (0);
}