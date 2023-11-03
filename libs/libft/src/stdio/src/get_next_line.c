/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:49 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 16:32:31 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdio.h"
#include <stdlib.h>

static int	search_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	read_fd(int fd, char **str)
{
	char	*last_str;
	char	*buf;
	int		chars_read;

	chars_read = BUFFER_SIZE;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	buf[0] = '\0';
	while (chars_read == BUFFER_SIZE && !search_newline(*str))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[chars_read] = '\0';
		last_str = *str;
		*str = ft_strjoin(*str, buf);
		free(last_str);
	}
	free(buf);
	return (1);
}

static void	process_str(char **str, int i)
{
	char	*last_str;

	if (!(*str))
		return ;
	last_str = *str;
	*str = ft_substr(*str, i + 1, ft_strlen(*str) - 1);
	free(last_str);
}

static void	clean_str(char **str)
{
	if (*str && ft_strlen(*str) == 0)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	size_t		i;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (str[fd] && read_fd(fd, &str[fd]))
	{
		i = 0;
		while (str[fd][i])
		{
			if (str[fd][i] == '\n' || i == ft_strlen(str[fd]) - 1)
			{
				line = ft_substr(str[fd], 0, i + 1);
				process_str(&str[fd], i);
				break ;
			}
			i++;
		}
	}
	clean_str(&str[fd]);
	return (line);
}
