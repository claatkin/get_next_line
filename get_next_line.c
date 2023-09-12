/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:36:42 by claatkin          #+#    #+#             */
/*   Updated: 2023/09/12 19:11:58 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char **line, char *buffer)
{
	int		i;
	int		line_length;
	char	*aux;

	i = 0;
	line_length = 0;
	if (*line)
		line_length = ft_strlen(*line);
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (*(buffer + i) == '\n')
		i++;
	if (i == 0)
		return (NULL);
	aux = *line;
	*line = ft_strjoin(*line, buffer);
	*line = aux;
	return (*line);
}

char	*clear_buffer(char *buffer)
{
	int	i;

	if (buffer)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		free (buffer);
	}
	return (NULL);
}

char	*move_buffer_to_next_line(int fd, char *buffer, char *buffer_start)
{
	int	buffer_length;

	if (*buffer == '\0')
	{
		buffer = buffer_start;
		buffer_length = read(fd, buffer, BUFFER_SIZE);
		if (buffer_length < 1)
		{
			clear_buffer(buffer_start);
			return (NULL);
		}
		buffer[buffer_length] = '\0';
	}
	return (buffer);
}

char	*buffer_init(int fd, char *buffer, char **buffer_start)
{
	if (fd < 0 || fd > 511 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= 511)
		{
			buffer = clear_buffer(*buffer_start);
			*buffer_start = NULL;
		}
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!buffer)
			return (NULL);
		*buffer = '\0';
		*buffer_start = buffer;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*buffer_start;

	line = NULL;
	buffer_start = NULL;
	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}
	while (!line || !(ft_strchr(line, '\n')))
	{
		if (*buffer == '\0')
			fill_buffer(fd, buffer);
		buffer_init(fd, buffer, &buffer_start);
		move_buffer_to_next_line(fd, buffer, buffer_start);
		append_buffer(&line, buffer);
	}
	return (line);
}

/*int main(void)
{
	int n;
	char *buff;
	char path[] = "claudia.txt";

	n = open(path, O_RDONLY);
	buff = get_next_line(n);
	printf("\n\n%s\n\n,buff");
}*/
