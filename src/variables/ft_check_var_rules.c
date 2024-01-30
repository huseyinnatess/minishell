/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var_rules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:04:53 by huates            #+#    #+#             */
/*   Updated: 2024/01/30 14:35:15 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/* 
    Gelen variable'ın ilk karakteri sayı ise veya
    variable'ın içinde alphanumerik olmayan bir karakter varsa
    ('-' hariç), 0 döndürür.
*/
int ft_check_var_rules(char *variable)
{
    int i;

    i = 0;
    if (ft_isdigit(variable[0]))
        return (0);
    while (variable[i])
    {
        if (!ft_isalnum(variable[i]) && variable[i] != '_')
            return (0);
        i++;
    }
    return (1);
}