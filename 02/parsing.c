/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:52:40 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 16:42:18 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc02.h"
#include "get_next_char.h"

static t_comb	*create_comb(void)
{
	t_comb	*comb;

	comb = malloc(sizeof(t_comb));
	if (!comb)
		return (NULL);
	comb->first = 0;
	comb->second = 0;
	comb->invalids = NULL;
	comb->nb_invalid = 0;
	comb->next = NULL;
	return (comb);
}

static t_comb	*comb_add_back(t_comb **lst, t_comb *comb)
{
	t_comb	*temp;

	if (!lst)
		return (NULL);
	temp = *lst;
	if (!*lst)
		*lst = comb;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = comb;
	}
	return (*lst);
}

static t_comb	*get_next_comb(int fd)
{
	char	*str;
	t_comb	*comb;
	int		i = 0;

	str = get_next_char(fd, ',');
	if (!str)
		return (NULL);
	comb = create_comb();
	if (!comb)
		return (NULL);
	comb->first = atoll(str);
	while (str[i] && str[i] != '-')
		i++;
	if (str[i])
		comb->second = atoll(&str[i + 1]);
	else
		return (free(comb), NULL);
	return (comb);
}

t_comb	*ft_parsing(int fd)
{
	t_comb	*lst = NULL;
	t_comb	*temp;

	temp = get_next_comb(fd);
	while (temp)
	{
		temp = comb_add_back(&lst, temp);
		if (!temp)
			return (NULL);
		temp = get_next_comb(fd);
	}
	return (lst);
}
