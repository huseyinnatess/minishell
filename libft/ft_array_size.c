/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:27:20 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 16:02:19 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_size(char	**array)
{
	int		count;
	char	**ptr;

	count = 0;
	ptr = array;
	while (*ptr != NULL)
	{
		count++;
		ptr++;
	}
	return (count);
}
