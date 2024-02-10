/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_or_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:52:16 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 17:28:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "print_error.h"

// Creates a pipe and allocates a pair of file descriptors at 'fd_pipe'.
// On failure, prints an error message and exits.
void	pipe_or_die(int fd_pipe[2])
{
	if (pipe(fd_pipe) == -1)
	{
		print_err_pipe();
		exit (EXIT_PIPE_ERR);
	}
}
