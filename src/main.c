/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/10 11:13:33 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "print_error.h"
#include "arrstr.h"

int	main(int ac, char **av, char **e)
{
	char	**env;

	if (ac != 1)
		return (print_err_argc());
	av += 0;
	env = arrstr_dup(e);
	print_welcome_msg();
	minish_loop(env);
	return (EXIT_FAILURE);
}
