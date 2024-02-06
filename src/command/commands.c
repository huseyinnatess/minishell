/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:55:52 by huates            #+#    #+#             */
/*   Updated: 2024/02/06 13:52:55 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
    1. ft_count_commands fonksiyonu ile komut sayısını buluyor.
    2. ft_write_syntax_errors fonksiyonu ile varsa syntax hatalarını yazdırıyor.
*/
int ft_commands(t_minishell *data)
{
    data -> nbr_of_cmds = ft_count_commands(data -> raw_cmd);
    if (ft_write_syntax_errors(data))
        return (0);
    while (ft_strchr_variable(data -> raw_cmd))  
        data -> raw_cmd = ft_parse_variables(data);
    if (ft_isallspace(data -> raw_cmd))
    {
        free(data -> raw_cmd);
        data -> raw_cmd = NULL;
        return (0);
    }
    if (data -> nbr_of_cmds == 1)
    {
        ft_init_data_one_cmd(data);
    }
    return (0);
}