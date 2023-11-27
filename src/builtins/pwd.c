/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:37:26 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	pwd(void)
{
	char	*buffer;
	int		size;

	size = PATH_MAX;
	buffer = malloc(sizeof(char) * size);
	if (!buffer)
		return (1);
	if (getcwd(buffer, size) == NULL)
	{
		free(buffer);
		return (1);
	}
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
