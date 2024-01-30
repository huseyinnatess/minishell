/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsevar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:18:11 by huates            #+#    #+#             */
/*   Updated: 2024/01/30 15:05:42 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
    Variable'ın ilk karakteri '$' ise '$' karakterini atlar.
    Variable'ın ilk karakteri '?' ise '?' karakterini döndürür.
    Variable'ın alfanumerik olmayan kısımları haricindeki kısmını döndürür.
    Örnek: variable = "$USER" ise "USER" döndürür.
*/
static char *ft_get_export_id(char *variable)
{
    char *result;
    char *non_alphanum;
    char *size;

    if (variable[0] == '$')
        variable++;
    if (variable[0] == '?')
        return("?");
    non_alphanum = ft_strdup(" \'\"!#$%%&\\()*+,-./:;<=>@[]^`{|}~");
    size = ft_strpbrk(variable, non_alphanum);
    free(non_alphanum);
    if (size == NULL)
        result = ft_strdup(variable);
    else
        result = ft_substr(variable, 0, size - variable);
    return(result);
}

// Ortam değişkenlerinin olup olmadığını kontrol ediyor.
char *ft_strchr_variable(char *raw_cmd)
{
    int i;
    int s_quote;
    char *variable;

    i = 0;
    s_quote = 0;
    while (raw_cmd[i++])
    {
        if (raw_cmd[i] == '\'')
            s_quote++;
        if (raw_cmd[i] == '$' && (ft_isalnum(raw_cmd[i + 1]) || raw_cmd[i + 1] \
            == '\'' || raw_cmd[i + 1] == '\"' || raw_cmd[i + 1] == '_') && s_quote == 0)
        {
            variable = ft_get_export_id(&raw_cmd[i + 1]);
            ft_check_var_rules(variable);
            free(variable);
            return(&raw_cmd[i]);
        }
        else if ((raw_cmd[i] == '$' && raw_cmd[i + 1] == '?') && s_quote == 0)
			return (&raw_cmd[i]);
        if (s_quote == 2)
			s_quote = 0;
    }
    return (NULL);
}

char *ft_status_variable(t_minishell *data, char *variable)
{
    char *result;
    char *status;

    status = ft_itoa(data -> status);
    result = ft_replace_string(data -> raw_cmd, variable, status);
    free(status);
    free(data -> raw_cmd);
    return (result);
}

char *ft_parse_variables(t_minishell *data)
{
    char *result;
    char *variable;
    t_envp *tmp;

    (void) tmp;
    variable = ft_strchr_variable(data -> raw_cmd);
    if (variable && ft_strlen(variable) > 1)
    {
        variable = ft_get_export_id(variable);
        if (ft_strcmp(variable, "?") == 0)
            return(ft_status_variable(data, variable));
    }
}