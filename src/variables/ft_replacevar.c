/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablevar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:48 by huates            #+#    #+#             */
/*   Updated: 2024/02/05 14:00:57 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
   İlk if bloğu status'ın uzunluğunu kontrol eder 
   ve eğer status'ın uzunluğu 0'dan büyükse ilk önce
   before_rp ve status'ı birleştirir ve sonra after_rp ile birleştirir.
*/
static char *ft_alloc_status(char *status, char *before_rp, char *after_rp)
{
    char	*new_str;

	if (ft_strlen(status))
	{
		new_str = ft_strjoin(before_rp, status);
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
	before_len değişkeni variable'dan önceki kısmın uzunluğunu tutar.
	after_len değişkeni variable'dan sonraki kısmın uzunluğunu tutar.
	before_rp değişkeni variable'dan önceki kısmı string olarak tutar.
	after_rp değişkeni variable'dan sonraki kısmı string olarak tutar.
*/
char *ft_replace_string(char *str, char *variable, char *status)
{
    char *before_rp;
    char *after_rp;
    char *new_str;
    size_t before_len;
    size_t after_len;

    new_str = NULL;
    before_len = ft_strchr_variable(str) - str;
    after_len = ft_strlen(ft_strchr_variable(str) + ft_strlen(variable));
	before_rp = ft_substr(str, 0, before_len);
	after_rp = ft_substr(str, before_len + ft_strlen(variable) + 1, after_len);
	new_str = ft_alloc_status(status, before_rp, after_rp);
	return (new_str);
}