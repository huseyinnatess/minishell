/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:55:52 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 18:33:32 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_commands(t_minishell *data)
{
    data -> nbr_of_cmds = ft_count_commands(data -> raw_cmd);
    (void) data;
    return (0);
}