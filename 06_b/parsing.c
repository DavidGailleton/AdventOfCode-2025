/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:03:38 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/17 14:57:13 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc06.h"
#include "libft.h"
#include <string.h>
#include "get_next_char.h"
#include <stdlib.h>
#include <stdio.h>

// 5391396 ; to low

static t_lst	*new_lst(void)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	ft_bzero(lst->nbrs[0], 5);
	ft_bzero(lst->nbrs[1], 5);
	ft_bzero(lst->nbrs[2], 5);
	ft_bzero(lst->nbrs[3], 5);
	ft_bzero(lst->nbrs[4], 5);
	lst->sign = '\0';
	lst->next = NULL;
	lst->pre = NULL;
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
		new->pre = temp;
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

static void	add_nbr(char *strs[5], t_lst *lst, int i)
{
	int	j;
	int	k;

	if (!lst)
		return ;
	k = 0;
	while (i >= 0 && !(strs[0][i] == ' ' && strs[1][i] == ' ' && strs[2][i] == ' '
		&& strs[3][i] == ' ' && strs[4][i] == ' '))
	{
		j = 0;
		while (j < 4)
		{
			lst->nbrs[j][k] = strs[j][i];
			j++;
		}
		k++;
		i--;
	}
	add_nbr(strs, lst->pre, i - 1);
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
	char	*temp[5];
	char	**int_lst = NULL;
	int		i = -1;
	t_lst	*lst = NULL;

	temp[++i] = get_next_char(fd, '\n');
	while (temp[i])
		temp[++i] = get_next_char(fd, '\n');
	int_lst = ft_split(temp[4], ' ');
	i = 0;
	while (int_lst[++i])
		lst_add_back(&lst, new_lst());
	clear_split(int_lst);
	int_lst = ft_split(temp[4], ' ');
	add_sign(lst, int_lst);
	while (lst->next)
		lst = lst->next;
	add_nbr(temp, lst, strlen(temp[0]) - 2);
	i = -1;
	while (++i < 6)
		free(temp[i]);
	clear_split(int_lst);
	return (lst);
}
