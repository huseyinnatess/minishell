/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:33:14 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 16:06:36 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *display_prompt_msg(void)
{
    char *input;

    input = readline("Fates_shell$ ");
    if (ft_strlen(input) > 0)
        add_history(input);
    return (input);
}