/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/28 17:07:14 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "ft_list.h"

typedef struct s_params
{
	t_list	*cmd_beginning;
	char	**env;
	int		file_fd[2];
	int		pipe_fd[2];
}	t_params;

char	**exec(t_list *uncasted_command, char **env);
int		ft_error(char *message, int exit_code);
int		print_error(char *message, int exit_code);

#endif
