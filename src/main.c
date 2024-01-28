/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:13:48 by huates            #+#    #+#             */
/*   Updated: 2024/01/28 18:32:33 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// envp init edilip, terminal ayarlanıyor (gereksiz)
int	init_minishell(t_minishell *data, char *envp[])
{
	if (init_envp(data, envp))
		return (write(2, "Error: init_envp\n", 17));
	if (init_term(data))
		return (write(2, "Error: init_term\n", 17));
	if (init_term_fd(data))
		return (write(2, "Error: init_term_fd\n", 19));
	data->infile = NULL;
	data->outfile = NULL;
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->status = 0;
	return (0);
}

static int	ft_ctrl_d(t_minishell *data)
{
	if (isatty(STDIN_FILENO))
	// Terminalden mi geliyor kontrolü? Terminalden geliyorsa 0'dan farklı bir değer döndürür.
		write(2, "exit\n", 5);
	ft_free_envp(data->lstenv);
	ft_array_free(data->env, ft_array_size(data->env));
	exit(data->status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell data;
	if (argc != 1 && argv[1] != NULL)
		return (0);
	init_minishell(&data, envp);
	while (1)
	{
		signal(SIGINT, ft_signal_handler);
		signal(SIGQUIT, SIG_IGN);
		data.raw_cmd = display_prompt_msg();
		if (data.raw_cmd == NULL)
			ft_ctrl_d(&data);                  
		if (ft_strlen(data.raw_cmd) > 0 && !ft_isstrprint(data.raw_cmd) // Girilen dizinin işlenebilirliğini kontrol ediyor.
			&& ft_isallspace(data.raw_cmd))
			free(data.raw_cmd);
       	ft_commands(&data);
	}
}