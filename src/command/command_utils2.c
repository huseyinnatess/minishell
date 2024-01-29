/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:58:00 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 14:13:24 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Tırnak içinde olmayam pipe var ise syntax error veriyor.
void ft_write_syntax_error(char *raw_cmd, int i)
{
    if (raw_cmd[i + 1] == '|')
    {
        ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
    }
}