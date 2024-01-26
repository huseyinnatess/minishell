/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:13:48 by huates            #+#    #+#             */
/*   Updated: 2024/01/26 11:55:13 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int init_minishell(t_minishell *data, char *envp[])
{
    if (init_envp(data, envp))
        return (write(2, "Error: init_envp\n", 17));
    return (0);
}

int main(int argc, char *argv[], char *envp[])
{
    t_minishell data;
    if (argc != 1 && argv[1] != NULL)
        return (0);
    init_minishell(&data, envp);

    int i;

    i = 0;
    while (data.env[i])
    {
        printf("%s\n", data.env[i]);
        i++;
    }
}