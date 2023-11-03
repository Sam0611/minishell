/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:32:46 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	check_flags(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] && str[j][0] == '-')
	{
		i = 0;
		while (str[j][i + 1] == 'n')
			i++;
		if (str[j][i] != 'n' || str[j][i + 1])
			break ;
		j++;
	}
	return (j);
}

int	echo(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	i = check_flags(args + 1);
	while (args[i + j])
	{
		printf("%s", args[i + j]);
		j++;
		if (args[i + j])
			printf(" ");
	}
	if (!i)
		printf("\n");
	return (0);
}
