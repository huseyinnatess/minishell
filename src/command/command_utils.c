/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:57:39 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 17:33:20 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_count_commands(char *raw_cmd)
{
    int i;
    int nbr_cmd;
    int len_command;
   //t_quote quotations;

    i = -1;
    //quotations.simple = 0;
    //quotations.dbl = 0;
    nbr_cmd = 1;
    len_command = ft_strlen(raw_cmd);
    return(0);
}