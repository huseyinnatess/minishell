/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:30:59 by ydunay            #+#    #+#             */
/*   Updated: 2024/03/09 11:16:36 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Returns TRUE if 'str' is a valid word, FALSE otherwise.
int	is_word(const char *str)
{
	int	q_stat;

	q_stat = UNQUOTED;
	while (*str)
	{
		if (q_stat == UNQUOTED && is_metachr(*str))
			return (FALSE);
		quote_stat(&q_stat, *str);
		++str;
	}
	if (q_stat != UNQUOTED)
		return (FALSE);
	return (TRUE);
}

// Given that 'str' points to a quote character, returns the distance to the
// next quote character of the same kind.
// If no next quote is found, returns the distance until the char before '\0'.
static int	distance_next_quote(const char *str)
{
	int		dist;
	char	c;

	c = *str;
	dist = 1;
	while (str[dist] && str[dist] != c)
		++dist;
	if (!str[dist])
		--dist;
	return (dist);
}

// Given that 'str' points to the beginning of a token, retuns its lenght.
static int	toklen(const char *str)
{
	int	len;

	len = 0;
	if (is_redirectionchr(*str) && *str == *(str + 1))
		return (2);
	if (is_operatorchr(*str))
		return (1);
	while (*(str + len) && !is_metachr(*(str + len)))
	{
		if (is_quotechr(*(str + len)))
			len += distance_next_quote(str + len);
		++len;
	}
	return (len);
}

// Given that the i-th character of 'str' represents the beginning of a token,
// allocates and returns a string representing the token.
// At the end, 'i' points to character after the token.
static char	*pop_token(const char *str, int *i)
{
	char	*str_tok;
	int		len;

	while (is_blankchr(str[*i]))
		++(*i);
	len = toklen(str + *i);
	str_tok = (char *)p_malloc(sizeof(char) * len + 1);
	ft_strlcpy(str_tok, str + *i, len + 1);
	*i += len;
	return (str_tok);
}

// Splits the recived 'input' into a list of tokens.
t_list	*tokenize(const char *input)
{
	t_list	*tokens;
	int		i;
	char	*str;
	t_token	tok;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		str = pop_token(input, &i);
		if (!*str)
			break ;
		tok = tok_create(str);
		free(str);
		lst_add(&tokens, lst_new(&tok, sizeof(tok)));
	}
	return (tokens);
}
