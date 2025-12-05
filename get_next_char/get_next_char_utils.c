/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_char_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:21:38 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 16:18:14 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_char.h"
#include <stdint.h>

int	index_of_char(char *str, int limit, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (i < limit && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_new(char const *s1, char const *s2, size_t limit)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (j <= limit && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((void *) s1);
	return (str);
}
