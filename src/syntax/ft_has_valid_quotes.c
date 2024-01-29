/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:37:18 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 14:42:24 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Tırnak işaretlerinin sayısını kontrol ediyor.
int	ft_has_valid_quotes(char *str)
{
	int i;
	t_quote quotes;

	i = -1;
	quotes.simple = 0;
	quotes.dbl = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[++i])
	{
		if ((quotes.dbl % 2 == 0 || (quotes.dbl == 0 && quotes.simple != 0))
			&& str[i] == '\'')
			quotes.simple++;
		else if ((quotes.simple % 2 == 0 || (quotes.simple == 0
						&& quotes.dbl != 0)) && str[i] == '\"')
			quotes.dbl++;
	}
	if ((quotes.dbl % 2 == 0 && quotes.simple == 0) 
        || (quotes.simple % 2 == 0 && quotes.dbl == 0) 
        || (quotes.dbl % 2 == 0 && quotes.simple % 2 == 0))
		return (1);
	else
		return (0);
}