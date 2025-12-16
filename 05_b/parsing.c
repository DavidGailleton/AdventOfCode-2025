/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:30:27 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 11:51:22 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc05.h"
#include "get_next_char.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_range	*new_range(char *str)
{
	t_range	*range;

	range = malloc(sizeof(t_range));
	if (!range)
		return (NULL);
	range->start = atoll(str);
	range->end = atoll(strchr(str, '-') + 1);
	range->next = NULL;
	range->pre = NULL;
	return (range);
}

static void	range_add_back(t_range **lst, t_range *new)
{
	t_range	*temp;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->pre = temp;
	}
}

void	lst_clear(t_range *lst)
{
	t_range	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

t_range	*parsing(int fd)
{
	t_range	*lst = NULL;
	char	*temp;

	temp = get_next_char(fd, '\n');
	while (temp && strlen(temp) > 1)
	{
		range_add_back(&lst, new_range(temp));
		free(temp);
		temp = get_next_char(fd, '\n');
	}
	if (temp)
		free(temp);
	return (lst);
}
