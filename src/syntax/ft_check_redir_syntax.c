/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:19 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 16:54:34 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Yönlendirme işaretlerinin sonda olup olmadığını kontrol ediyor.
static int	ft_check_redir_ends(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == ' ')
	{
		while (str[len] == ' ')
			len--;
		if (str[len] == '>' || str[len] == '<')
		{
			write(2,
					"minishell: syntax error near unexpected token `newline'\n",
					56);
			return (1);
		}
	}
	if (str[ft_strlen(str) - 1] == '<' || str[ft_strlen(str) - 1] == '>')
	{
		write(2,
				"minishell: syntax error near unexpected token `newline'\n",
				57);
		return (1);
	}
	return (0);
}

// Yönlendirme işaretlerinin sayısını kontrol ediyor.
static int	ft_get_redir_syntax_values(char c, t_redir *rd, t_quote quotations)
{
	if (c == '<' && quotations.dbl == 0 && quotations.simple == 0)
		rd->redir_left++;
	else if (c == '>' && quotations.dbl == 0 && quotations.simple == 0)
		rd->redir_right++;
	if (ft_isspace(c) && quotations.dbl == 0 && quotations.simple == 0)
	{
		rd->redir_left = 0;
		rd->redir_right = 0;
	}
	if (((rd->redir_left > 2 && !rd->redir_right) ||
			(rd->redir_right > 2 && !rd->redir_left)) ||
		(rd->redir_left && rd->redir_right))
	{
		return (write(2,
						"minishell: syntax error near unexpected token `>'\n",
						51));
	}
	return (0);
}

/* Yönlendirme '>', '<' işaretlerinin sayısını, doğru
   kullanımını ve sonda olup olmadığını kontrol ediyor */
int	ft_check_redir_sytax(char *str)
{
	int i;
	t_redir rd;
	t_quote quotations;

	i = -1;
	quotations.simple = 0;
	quotations.dbl = 0;
	rd.redir_left = 0;
	rd.redir_right = 0;
	while (str[++i])
	{
		ft_get_qauotes_values(str[i], &quotations);
		if (ft_get_redir_syntax_values(str[i], &rd, quotations))
			return (1);
	}
	if (ft_check_redir_ends(str))
		return (1);
	return (0);
}