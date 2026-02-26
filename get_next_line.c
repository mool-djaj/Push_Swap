/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:15:20 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 02:11:24 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*join_and_free(char **s1, char *s2)
{
	char	*tmp;

	if (!s1 || !*s1 || !s2)
		return (NULL);
	tmp = gnl_strjoin(*s1, s2);
	if (!tmp)
		return (free(*s1), free(s2), *s1 = NULL, (NULL));
	free(*s1);
	*s1 = NULL;
	return (tmp);
}

char	*read_store(int fd, char **sta)
{
	ssize_t	byt_read;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(buff), free(*sta), *sta = NULL, NULL);
	if (!*sta)
		*sta = gnl_strdup("");
	if (!*sta)
		return (free(buff), free(*sta), (NULL));
	byt_read = 1;
	while (!gnl_strchr(*sta, '\n') && byt_read > 0)
	{
		byt_read = read(fd, buff, BUFFER_SIZE);
		if (byt_read < 0)
			return (free(buff), free(*sta), *sta = NULL, (NULL));
		if (byt_read == 0)
			break ;
		buff[byt_read] = '\0';
		*sta = join_and_free(sta, buff);
		if (!*sta)
			return (NULL);
	}
	free(buff);
	return (*sta);
}

char	*extract_line(char *stash)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	tmp = gnl_substr(stash, 0, i);
	return (tmp);
}

char	*sav_rest(char **sta)
{
	int		i ;
	char	*tmp;

	i = 0;
	while ((*sta)[i] && (*sta)[i] != '\n')
		i++;
	if ((*sta)[i] == '\0')
		return (free(*sta), *sta = NULL, (NULL));
	if ((*sta)[i] == '\n' && (*sta)[i + 1] == '\0')
		return (free(*sta), *sta = NULL, (NULL));
	tmp = gnl_strdup(*sta + i + 1);
	free(*sta);
	*sta = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!read_store(fd, &sta))
		return (NULL);
	line = extract_line(sta);
	if (!line)
		return (free(sta), sta = NULL, (NULL));
	sta = sav_rest(&sta);
	return (line);
}
