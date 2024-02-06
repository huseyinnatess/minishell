/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:15:38 by huates            #+#    #+#             */
/*   Updated: 2024/02/06 14:12:50 by huates           ###   ########.fr       */
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
# include "split_quotes.h"
# include "variable.h"
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

typedef struct s_redir
{
	int		redir_left;
	int		redir_right;
}t_redir;

// environment
int		init_envp(t_minishell *data, char *env[]);
char	**ft_split_envp(char *line);
t_envp *ft_find_id(t_envp *envp, char *id);

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
void ft_init_data_one_cmd(t_minishell *data);

// redirections
void	ft_get_redit_value(char *raw_cmd, t_minishell *data);
void ft_get_value_infile(t_minishell *data, char *raw_cmd);

// syntax_error
void ft_write_syntax_error(char *raw_cmd, int i);
int ft_write_syntax_errors(t_minishell *data);
int		ft_has_valid_quotes(char *str);
int ft_check_pipe_sytax(t_minishell *data);
int ft_check_redir_sytax(char *str);

// Variables
char *ft_strchr_variable(char *raw_cmd);
char *ft_parse_variables(t_minishell *data);
int ft_isvariable(t_envp *envp, char *variable);

// replace_string
char	*ft_replace_string(char *str, char *variable, char *status);


#endif