/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:05:05 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/17 18:43:37 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <unistd.h>
#include <fcntl.h>

// If 'mode' = SAVE: Saves the standard input and output.
// If 'mode' = RESTORE: Restores the previously saved standard input and output.
void	save_restore_stdio(int std_in, int std_out, int mode)
{
	static int	saved_stdin;
	static int	saved_stdout;

	if (mode == SAVE)
	{
		saved_stdin = dup(std_in);
		saved_stdout = dup(std_out);
	}
	if (mode == RESTORE)
	{
		dup2(saved_stdin, std_in);
		close(saved_stdin);
		dup2(saved_stdout, std_out);
		close(saved_stdout);
	}
}

// Redirects and executes the given command 'cmd' on the current shell
// environment, returning the exit status.
static int	process_builtin_here(t_list **cmd, int exit_status, char ***env)
{
	int	exit_stat;

	save_restore_stdio(STDIN_FILENO, STDOUT_FILENO, SAVE);
	exit_stat = read_heredocs(*cmd, 0, *env);
	if (exit_stat)
		return (exit_stat);
	exit_stat = redirect(cmd, 0);
	if (exit_stat != 0)
	{
		save_restore_stdio(STDIN_FILENO, STDOUT_FILENO, RESTORE);
		return (exit_stat);
	}
	if (lst_size(*cmd) > 0)
		exit_stat = execute_builtin(*cmd, exit_status, env, FALSE);
	save_restore_stdio(STDIN_FILENO, STDOUT_FILENO, RESTORE);
	return (exit_stat);
}

// Reads all the here documents from the array of commands 'cmds', from left
// to right, into the appropriate temp files to be read afterwards.
// Returns 0 on success. Otherwise, returns a non-zero value.
int	read_all_heredocs(t_list **cmds, int cmds_amount, char **env)
{
	int		i;
	int		ret;

	stop_signals();
	i = -1;
	while (++i < cmds_amount)
	{
		ret = read_heredocs(cmds[i], i, env);
		if (ret)
			return (ret);
	}
	return (0);
}

// Updates the pipe's file descriptor updates from the parent process for the 
// i-th command, closing previous file descriptors and preparing for next.
static void	parent_pipe_update(t_pipe *p, int i)
{
	if (i > 0)
	{
		close(p->prev_fds[READ_END]);
		close(p->prev_fds[WRITE_END]);
	}
	if (i < p->cmds_amount - 1)
	{
		p->prev_fds[READ_END] = p->next_fds[READ_END];
		p->prev_fds[WRITE_END] = p->next_fds[WRITE_END];
	}
}

// Redirects and executes the commands defined by the array of commands 'cmds',
// assuming p->cmds_amount is already initialized. All commands are executed in
// subprocesses. Returns the exit status of the last command.
static int	process_commands(t_list **cmds, t_pipe *p, int e_stat, char **env)
{
	int		exit_stat;
	int		i;
	pid_t	pid;
	pid_t	last_child;

	exit_stat = read_all_heredocs(cmds, p->cmds_amount, env);
	if (exit_stat)
		return (exit_stat);
	stop_signals();
	i = -1;
	while (++i < p->cmds_amount)
	{
		p->i = i;
		if (i < p->cmds_amount - 1)
			pipe_or_die(p->next_fds);
		pid = fork_or_die();
		if (pid == 0)
			return (process_command(p, cmds[i], e_stat, env));
		parent_pipe_update(p, i);
		last_child = pid;
	}
	exit_stat = wait_children(last_child, p->cmds_amount);
	clear_heredocs(p->cmds_amount);
	return (exit_stat);
}

// Performs all redirections and command/builtin executions defined by the array
// of lists 'commands', updating the 'exit_status' and environment 'env'
// accordingly.
void	redirect_and_execute(t_list **commands, int *exit_status, char ***env)
{
	t_pipe	p;

	p.cmds_amount = arr_size((void *)commands);
	if (p.cmds_amount == 0)
		*exit_status = 0;
	else if (p.cmds_amount == 1 && is_builtin_cmd(commands[0]))
		*exit_status = process_builtin_here(commands, *exit_status, env);
	else
		*exit_status = process_commands(commands, &p, *exit_status, *env);
}