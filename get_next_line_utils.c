/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:50:01 by claatkin          #+#    #+#             */
/*   Updated: 2023/10/31 13:25:14 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* lee datos desde el descriptor de archivo al buffer */
char	*fill_buffer(int fd, char *buffer)
{
	int	intiewinkie;

	intiewinkie = read(fd, buffer, BUFFER_SIZE);
	if (intiewinkie < 1)
		buffer = clear_buffer(buffer);
	return (buffer);
}

/* busca un carácter en una cadena */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (&((char *)s)[i]);
}

/* calcula la longitud de una cadena */
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* extrae una subcadena de una cadena */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = malloc(1);
		*sub = '\0';
		return (sub);
		free(malloc);
	}
	if (len > ((slen - start) + 1))
		len = slen - start + 1;
	sub = malloc ((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

/* concatena dos cadenas */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstring;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstring[i] = s2[j];
		i++;
		j++;
	}
	newstring[i] = '\0';
	return (newstring);
}
