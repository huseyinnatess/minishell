/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacevar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:48 by huates            #+#    #+#             */
/*   Updated: 2024/01/30 16:41:23 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char *ft_alloc_replacer(char *replacer, char *before_rp, char *after_rp)
{
    char	*new_str;

	if (ft_strlen(replacer))
	{
		new_str = ft_strjoin(before_rp, replacer);
		new_str = ft_strjoinfree(new_str, after_rp);
	}
	else
	{
		if (ft_strlen(after_rp))
			new_str = ft_strjoin(before_rp, after_rp);
		else
		{
			free(after_rp);
			return (before_rp);
		}
	}
	free(after_rp);
	free(before_rp);
	return (new_str);
}

/*
	'?' barındıran bir variable için kullanılır.
	before_len değişkeni '?''den önceki kısmın uzunluğunu tutar.
	after_len değişkeni '?''den sonraki kısmın uzunluğunu tutar.
	before_rp değişkeni '?''den önceki kısmı string olarak tutar.
	after_rp değişkeni ilk soru '?''den sonraki kısmı string olarak tutar.
*/
char *ft_replace_string(char *str, char *replace, char *replacer)
{
    char *before_rp;
    char *after_rp;
    char *new_str;
    size_t before_len;
    size_t after_len;

    new_str = NULL;
    before_len = ft_strchr_variable(str) - str;
    after_len = ft_strlen(ft_strchr_variable(str) + ft_strlen(replace));
	before_rp = ft_substr(str, 0, before_len);
	after_rp = ft_substr(str, before_len + ft_strlen(replace) + 1, after_len);
	new_str = ft_alloc_replacer(replacer, before_rp, after_rp);
	return (new_str);
}