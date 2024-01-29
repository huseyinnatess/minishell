/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:01:52 by huates            #+#    #+#             */
/*   Updated: 2024/01/29 12:27:33 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_QUOTES_H
# define SPLIT_QUOTES_H

# include "../libft/libft.h"

typedef struct s_quote
{
    int dbl;
    int simple;
} t_quote;

void ft_get_qauotes_values(char c, t_quote *quotations);





#endif