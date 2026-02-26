/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:15:29 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 02:11:17 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*gnl_strdup(char *s)
{
	char			*d;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[len] = '\0';
	return (d);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	d = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = gnl_strlen(s);
	if (start >= len_s)
		return (gnl_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*gnl_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
