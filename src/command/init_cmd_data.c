/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:54:21 by huates            #+#    #+#             */
/*   Updated: 2024/02/06 13:57:35 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void ft_init_data_one_cmd(t_minishell *data)
{
    data -> in_files = NULL;
    data -> out_files = NULL;
    data -> out_append = NULL;
    data -> heredocs = NULL;
    data->infile = NULL;
	data->outfile = NULL;
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->is_append = 0;
	data->is_heredoc = 0;
    ft_get_redit_value(data -> raw_cmd, data);
}