/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/28 17:05:36 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		pwd(void);
int		echo(char **args);
void	display_env(char **args, char **env);
void	display_env_export(char **env);
char	**cd(char **args, char **env);
int		ft_exit(char **args);
char	**export(char **args, char **env);
char	**unset(char **args, char **env);
char	**unset_var(char *var, char **env);

#endif
