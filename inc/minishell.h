/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:15:38 by huates            #+#    #+#             */
/*   Updated: 2024/01/25 16:18:26 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h> 
# include <sys/errno.h>
# include <fcntl.h>

# include "environment.h"
# include "../libft/libft.h"


typedef struct s_minishell
{
	pid_t			pid;
	int				fd[2];

	int				std_in;
	int				std_out;

	char			**env;
	t_envp			*lstenv;

	char			**cmd;
	char			**mul_cmds;

	char			*raw_cmd;
	char			*cleaned_cmd;

	int				nbr_of_cmds;
	int				status;

	char			*infile;
	char			*outfile;

	int				is_append;
	int				is_heredoc;
	int				is_out_heredoc;
	t_list			*in_files;
	t_list			*out_files;
	t_list			*out_append;
	t_list			*heredocs;

	struct termios	old_settings;
	struct termios	new_settings;

}t_minishell;

int		init_envp(t_minishell *data, char *env[]);
char	**ft_split_envp(char *line);

#endif