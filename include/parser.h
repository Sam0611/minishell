/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:45:15 by kjimenez          #+#    #+#             */
/*   Updated: 2023/09/11 18:39:36 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_list.h"

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_IN_HEREDOC,
	REDIR_OUT,
	REDIR_OUT_APPEND,
	REDIR_UNKNOWN
}			t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
}	t_redir;

typedef struct s_command
{
	char	**args;
	t_list	*redirs;
}	t_command;

t_list	*get_commands(t_list *lexer);
void	commands_destroy(t_list *commands);

#endif
