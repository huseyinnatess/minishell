/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:54:49 by huates            #+#    #+#             */
/*   Updated: 2023/10/19 12:28:09 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	f_nbrlen(int n)
{
	int	i;
	int	nbr;

	nbr = n;
	i = 1;
	while (nbr && i++)
		nbr /= 10;
	i += (n < 0) + (n == 0);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	if (n == -2147483648)
	{
		result = ft_strdup("-2147483648");
		return (result);
	}
	len = f_nbrlen(n);
	result = (char *)malloc(sizeof(char) * (len));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	result[--len] = '\0';
	while (n >= 10)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	result[--len] = n + '0';
	return (result);
}
