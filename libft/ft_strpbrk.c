/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:30:52 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 14:30:56 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
The strpbrk() function locates in the null-terminated string s
the first occurrence of any character in the string charset
and returns a pointer to this character.
If no characters from charset occur anywhere in s strpbrk() returns NULL.
*/
char	*ft_strpbrk(const char *s, const char *charset)
{
	while (s)
	{
		if (ft_strchr(charset, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
