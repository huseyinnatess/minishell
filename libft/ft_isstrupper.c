/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:09 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 14:29:12 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
