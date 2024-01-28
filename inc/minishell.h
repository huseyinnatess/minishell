/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:15:38 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 16:09:58 by huates           ###   ########.fr       */
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

// environment
int		init_envp(t_minishell *data, char *env[]);
char	**ft_split_envp(char *line);

// terminal
int init_term(t_minishell *data);
int init_term_fd(t_minishell *data);

// signal
void ft_signal_handler(int sig);

// display_prompt
char *display_prompt_msg(void);

// commands
int ft_commands(t_minishell *data);
int ft_count_commands(char *raw_cmd);

#endif