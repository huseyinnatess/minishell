/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:57:58 by huates            #+#    #+#             */
/*   Updated: 2024/01/26 12:08:15 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char **ft_split_envp(char *line)
{
    int find;
    char **split;

    find = 0;
    if (!ft_strchr(line, '='))
    {
        split = malloc(sizeof(char *) * 3);
        split[0] = ft_strdup(line);
        split[1] = ft_strdup("");
        split[2] = NULL;
        return (split);
    }
    else
    {
        find = ft_strchr(line, '=') - line;
        split = malloc(sizeof(char *) * 3);
        split[0] = ft_substr(line, 0, find);
        split[1] = ft_substr(line, find + 1, ft_strlen(line));
        split[2] = NULL;
    }
    return (split);
}