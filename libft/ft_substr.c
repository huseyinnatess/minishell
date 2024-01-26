/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:52:44 by huates            #+#    #+#             */
/*   Updated: 2023/10/19 12:29:09 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s)
	{
		if (start >= ft_strlen(s) || len == 0)
			return (ft_strdup(""));
		while (i < len && s[i + start] != '\0')
			i++;
		new_str = (char *)malloc(sizeof(char) * (i + 1));
		if (!new_str)
			return (NULL);
		while (j < i)
		{
			new_str[j] = s[start + j];
			j++;
		}
		new_str[j] = '\0';
		return (new_str);
	}
	return (NULL);
}
