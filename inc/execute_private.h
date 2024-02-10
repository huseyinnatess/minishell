/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/21 20:18:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_PRIVATE_H
# define EXECUTE_PRIVATE_H

# include "list.h"

char	**get_args_from_cmd(t_list *cmd);
void	exec_cmd(char **cmd, char **env);
char	*get_executable(const char *file, char **env);
int		can_execute(const char *path);
int		is_directory(const char *path);
int		path_exists(const char *path);

#endif
