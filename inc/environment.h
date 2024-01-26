/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:40:43 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 16:20:55 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_envp
{
	char			*id;
	char			*value;
	struct s_envp	*next;
}t_envp;

t_envp *ft_envpnew(char *id, char *value);
void ft_envpadd_back(t_envp **lst, t_envp *new);
t_envp *ft_envplast(t_envp *lst);

#endif