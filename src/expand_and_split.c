/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:49:50 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/17 18:43:37 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
// Given that the xchar list 'node' points to the '$' character of an 
// environment variable name, expands its value updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded variable value.
static void	expand_var(t_list **lst, t_list **node, char **env)
{
	char	*name;
	char	*value;
	int		len;
	t_list	*expanded_lst;

	*node = (*node)->nxt;
	name = xclst_to_str(*node);
	value = env_get_var(name, env);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	lst_add_many(lst, (*node)->pre, expanded_lst);
	len = env_name_len(name);
	free(name);
	*node = lst_move(*node, len);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -(len)), len + 1, free);
	else
		lst_rm_many(lst, lst_move(*node, -(len + 1)), len + 1, free);
}

// Given that 'node' points to the $ character of "$?", expands the value 
// of 'exit_status' updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded value.
static void	expand_exit_stat(t_list **lst, t_list **node, int exit_status)
{
	char	*value;
	t_list	*expanded_lst;

	value = ft_itoa(exit_status);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	free(value);
	lst_add_many(lst, *node, expanded_lst);
	*node = lst_move(*node, 2);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -1), 2, free);
	else
		lst_rm_many(lst, lst_move(*node, -2), 2, free);
}

// Returns TRUE if the list of xchars pointed by 'node' represents a string that
// should trigger an expansion.
// That is, a '$' followed by a '?' or a valid environment variable name.
static int	try_to_expand(t_list *node)
{
	t_xchar	xc;
	t_xchar	xc_next;

	if (!node->nxt)
		return (FALSE);
	xc = xc_get(node);
	xc_next = xc_get(node->nxt);
	if (xc.q != QUOTED && xc.c == '$'
		&& (ft_isalpha(xc_next.c) || xc_next.c == '?' || xc_next.c == '_'))
		return (TRUE);
	return (FALSE);
}

// Expands the env variables (or exit status) of the given xtoken (if is word),
// updating the expanded xchar flags if needed.
static void	expand_xtok(t_xtoken *xtok, int exit_status, char **env)
{
	t_list	*node;

	if (xtok->type != WORD)
		return ;
	node = xtok->val;
	while (node && node->val)
	{
		if (try_to_expand(node))
		{
			if (((t_xchar *)((node->nxt)->val))->c == '?')
				expand_exit_stat(&(xtok->val), &node, exit_status);
			else
				expand_var(&(xtok->val), &node, env);
		}
		else
			node = node->nxt;
	}
}

// Given a list of tokens, allocates and returns a list of xtokens with its
// environment variables (or exit status) expanded, preserving the original
// token type and setting each character's flags for expanded and quoted status.
t_list	*expand(t_list *toks, int exit_status, char **env)
{
	t_list		*xtoks;
	t_xtoken	xtok;
	t_list		*node;
	int			skip_next;

	skip_next = FALSE;
	xtoks = NULL;
	node = toks;
	while (node)
	{
		xtok = tok_to_xtok((t_token *)node->val);
		if (xtok.type == WORD)
		{
			if (skip_next)
				skip_next = FALSE;
			else
				expand_xtok(&xtok, exit_status, env);
		}
		else if (!xtok_strncmp(&xtok, "<<", 3))
			skip_next = TRUE;
		lst_add(&xtoks, lst_new(&xtok, sizeof(xtok)));
		node = node->nxt;
	}
	return (xtoks);
}

// Expands the variables of the command 'cmd' (as a list of tokens) and splits
// words if needed. Finally, performs quote removal and returns the result.
static t_list	*expand_and_split_cmd(t_list *cmd, int exit_status, char **env)
{
	t_list	*new_cmd;
	t_list	*xtoks;

	xtoks = expand(cmd, exit_status, env);
	lst_clear(&cmd, tok_del);
	split_words(&xtoks);
	remove_quotes(xtoks);
	new_cmd = normalize(xtoks);
	xtoklst_clear(&xtoks);
	return (new_cmd);
}

// Expands the env variables and $? of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
t_list	**expand_and_split(t_list **commands, int exit_status, char **env)
{
	int		i;
	t_token	tok;

	i = -1;
	while (commands[++i])
	{
		commands[i] = expand_and_split_cmd(commands[i], exit_status, env);
		if (commands[i] == NULL)
		{
			tok = tok_create_null();
			commands[i] = lst_new(&tok, sizeof(t_token));
		}
	}
	return (commands);
}

// Adds the 'to_add' list nodes right before the 'pos' position.
void	lst_add_many(t_list **lst, t_list *pos, t_list *to_add)
{
	t_list	*prev;
	t_list	*next;

	if (!to_add)
		return ;
	if (!*lst)
	{
		*lst = to_add;
		return ;
	}
	if (!pos)
	{
		prev = lst_last(*lst);
		next = NULL;
	}
	else
	{
		prev = pos->pre;
		next = pos;
	}
	lst_link(prev, to_add);
	lst_link(lst_last(to_add), next);
	if (!prev)
		*lst = to_add;
}

// Recives the expanded, splited, quote-removed xtokens and converts them into a
// token list(cmd).
t_list	*normalize(t_list *xtokens)
{
	t_list	*cmd;
	t_list	*xtok;
	t_token	tok;
	t_list	*new_tok;

	cmd = NULL;
	xtok = xtokens;
	while (xtok)
	{
		tok = xtok_to_tok(xtok->val);
		new_tok = lst_new(&tok, sizeof(tok));
		lst_add(&cmd, new_tok);
		xtok = xtok->nxt;
	}
	return (cmd);
}