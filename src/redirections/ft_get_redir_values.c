/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:58:41 by huates            #+#    #+#             */
/*   Updated: 2024/02/06 14:12:25 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void get_values_loop(char *raw_cmd, int i, t_minishell *data, t_quote quotations)
{
    while (raw_cmd[++i])
    {
        ft_get_qauotes_values(raw_cmd[i], &quotations);
        if (raw_cmd[i] == '<' && raw_cmd[i + 1] != '<' && !quotations.dbl && !quotations.simple)
            ft_get_value_infile(data, &raw_cmd[i]);
    }
}

void	ft_get_redit_value(char *raw_cmd, t_minishell *data)
{
    int i;
    t_quote quotations;

    i = -1;
    quotations.simple = 0;
    quotations.dbl = 0;
    get_values_loop(raw_cmd, i, data, quotations);
}