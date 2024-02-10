/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_welcome_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:28:03 by glajara-          #+#    #+#             */
/*   Updated: 2024/02/10 11:21:35 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "minish_consts.h"
#include <unistd.h>

// Prints the minish welcome message to the standard output.
void	print_welcome_msg(void)
{
	ft_putstr_fd(TRIFORCE_1, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
