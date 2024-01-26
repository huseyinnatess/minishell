/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:27:37 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 14:27:40 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_bigger_maxll(char *str)
{
	int	negative;

	negative = 0;
	if (str[0] == '-')
		negative = 1;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		return (0);
	else if (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

long long int	ft_atoll(const char *str)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	if (ft_is_bigger_maxll((char *)str) == 1)
		return (0);
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ' )
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}
