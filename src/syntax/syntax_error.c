/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:28:28 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 16:46:32 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Syntax hatalarını yazdırıyor. 
   1-) Gelen tırnakların sayısını kontrol ediyor.
   2-) Pipe'ların başta veya sonda olup olmadığını kontrol ediyor.
*/
int ft_write_syntax_errors(t_minishell *data)
{
    if (ft_has_valid_quotes(data -> raw_cmd) == 0)
    {
        free (data -> raw_cmd);
        return (write(2, "quote>\n", 8));
    }
    if (data -> nbr_of_cmds > 1 && ft_check_pipe_sytax(data))
    {
        free (data -> raw_cmd);
        return (1);
    }
    if ((ft_strchr(data -> raw_cmd, '>') || ft_strchr(data -> raw_cmd, '<')) 
        && ft_check_redir_sytax(data -> raw_cmd))
    {
        free (data -> raw_cmd);
        return (1);
    }
    return (0);
}