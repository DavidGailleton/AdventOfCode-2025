/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:17:12 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/15 16:26:55 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc04_b.h"
#include <stdlib.h>

t_co	*new_co(int i, int j)
{
	t_co	*co;

	co = malloc(sizeof(t_co));
	if (!co)
		return (NULL);
	co->i = i;
	co->j = j;
	co->next = NULL;
	return (co);
}

void	co_add_back(t_co **lst, t_co *new)
{
	t_co	*temp;

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
	}
}

void	clear_lst(t_co *lst)
{
	t_co	*temp = lst;

	while (temp)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
