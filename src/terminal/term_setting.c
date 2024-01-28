/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:31:01 by huates            #+#    #+#             */
/*   Updated: 2024/01/26 16:36:03 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int init_term(t_minishell *data)
{
    if (tcgetattr(STDIN_FILENO, &data -> new_settings) != 0)
    {
        perror("tcgetattr");
        return (1);
    }
    data -> old_settings = data -> new_settings;
    data -> new_settings.c_lflag &= ~ECHOCTL;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &data -> new_settings) != 0)
    {
        perror("tcsetattr");
        return (1);
    }
    return (0);
}