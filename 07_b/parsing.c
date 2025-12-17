/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:02:13 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/17 15:29:54 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_char.h"

size_t	tab_len(char **tab)
{
	size_t	i = 0;

	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**tab_extend(char **tab, char *str)
{
	char	**new_tab;
	size_t	i = 0;
	size_t	len = tab_len(tab);

	new_tab = malloc(sizeof(char *) * (len + 2));
	if (!new_tab)
		return (NULL);
	while (i < len)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[len] = str;
	new_tab[len + 1] = NULL;
	if (len > 0)
		free(tab);
	return (new_tab);
}

char	**parsing(int fd)
{
	char	**tab = NULL;
	char	*temp;
	
	temp = get_next_char(fd, '\n');
	while (temp)
	{
		tab = tab_extend(tab, temp);
		temp = get_next_char(fd, '\n');
	}
	return (tab);
}
