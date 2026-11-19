/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:38:59 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/18 20:23:29 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	i;

	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
