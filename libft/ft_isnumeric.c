/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:28:12 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 14:28:15 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumeric(char *str)
{
	int		i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[0] == ' ')
		str++;
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
