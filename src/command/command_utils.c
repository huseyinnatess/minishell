/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:57:39 by huates            #+#    #+#             */
/*   Updated: 2024/02/06 13:49:03 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Gelen komutları sayıp tırnak içinde olmayan pipe'ları kontrol ediyor.
// Bu fonksiyon çalıştı ise minimum 1 komut vardır.
int ft_count_commands(char *raw_cmd)
{
    int i;
    int nbr_cmd;
    int len_command;
    t_quote quotations;

    i = -1;
    quotations.simple = 0;
    quotations.dbl = 0;
    nbr_cmd = 1;
    len_command = ft_strlen(raw_cmd);
    while (i++ < len_command)
    {
        if (raw_cmd[i] == '\"' || raw_cmd[i] == '\'')
            ft_get_qauotes_values(raw_cmd[i], &quotations);
        if (raw_cmd[i] == '|' && quotations.dbl == 0 && quotations.simple == 0)
        {
            ft_write_syntax_error(raw_cmd, i);
            nbr_cmd++;
        }
    }
    return(nbr_cmd);
}