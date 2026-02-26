/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:08:50 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 02:43:36 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strdup(char *s);
int		gnl_strlen(char *r);
char	*extract_line(char *stash);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *str, int c);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*read_store(int fd, char **sta);
char	*sav_rest(char **sta);
char	*join_and_free(char **s1, char *s2);

#endif