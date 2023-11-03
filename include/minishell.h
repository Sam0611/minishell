/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/28 17:07:43 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_list.h"
# include <stdio.h>
# include <stdlib.h>

extern int	g_exit_code;

typedef enum e_err
{
	ERR_FILE = 1,
	ERR_ARG = 1,
	ERR_SYNTAX = 2,
	ERR_FCT = 2,
	ERR_DIR = 126,
	ERR_PERM = 126,
	ERR_CMD = 127,
	ERR_SIGINT = 130,
	ERR_SIGQUIT = 131,
}			t_err;

#endif