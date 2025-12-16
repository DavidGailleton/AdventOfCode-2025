/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:03:38 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 16:50:23 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc06.h"
#include "libft.h"
#include "get_next_char.h"
#include <stdlib.h>
#include <stdio.h>

static t_lst	*new_lst(void)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->sign = '\0';
	lst->next = NULL;
	return (lst);
}

static void	lst_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

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

void	lst_clear(t_lst *lst)
{
	t_lst	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

static void	add_nbr(t_lst *lst, char **nbrs, int i)
{
	int	j = 0;

	while (nbrs[j])
	{
		lst->nbrs[i] = atoll(nbrs[j]);
		j++;
		lst = lst->next;
	}
}

static void	add_sign(t_lst *lst, char **signs)
{
	int	j = 0;

	while (lst)
	{
		printf("%s\n", signs[j]);
		lst->sign = signs[j][0];
		j++;
		lst = lst->next;
	}
}

static void	clear_split(char **tabs)
{
	int	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free(tabs);
}

t_lst	*parsing(int fd)
{
	char	*temp;
	char	**int_lst;
	int		i = 0;
	t_lst	*lst = NULL;

	temp = get_next_char(fd, '\n');
	int_lst = ft_split(temp, ' ');
	while (int_lst[i++])
		lst_add_back(&lst, new_lst());
	i = 0;
	while (int_lst && ft_isdigit(int_lst[0][0]))
	{
		add_nbr(lst, int_lst, i);
		i++;
		free(temp);
		clear_split(int_lst);
		temp = get_next_char(fd, '\n');
		int_lst = ft_split(temp, ' ');
	}
	printf("%s\n", temp);
	printf("%s\n", int_lst[0]);
	add_sign(lst, int_lst);
	free(temp);
	clear_split(int_lst);
	return (lst);
}
