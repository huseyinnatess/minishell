/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_quotes_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:18:15 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 14:34:13 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/split_quotes.h"

// Tırnak işaretlerini sayıyor.
void ft_get_qauotes_values(char c, t_quote *quotations)
{
    if (c == '\"' && !quotations -> simple)
        quotations -> dbl++;
    if (c == '\'' && !quotations -> dbl)
        quotations -> simple++;
    if (c ==  '\"' && quotations -> dbl == 2)
        quotations -> dbl = 0;
    if (c == '\'' && quotations -> simple == 2)
        quotations -> simple = 0;
}