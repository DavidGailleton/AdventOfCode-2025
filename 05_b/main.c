/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:44:11 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 15:25:14 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc05.h"
#include "get_next_char.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	update_range(t_range *lst)
{
	t_range	*node = lst;

	while (lst->pre)
		lst = lst->pre;
	while (lst != node)
	{
		if (node->start >= lst->start && node->start <= lst->end)
			node->start = lst->end + 1;
		if (node->end >= lst->start && node->end <= lst->end)
			node->end = lst->start - 1;
		if ((lst->start >= node->start && lst->start <= node->end)
			&& (lst->end >= node->start && lst->end <= node->end))
		{
			lst->start = 0;
			lst->end = -1;
		}
		lst = lst->next;
	}
	if (node->start > node->end)
	{
		node->start = 0;
		node->end = -1;
	}
}

int	main(void)
{
	int					fd = open("input", O_RDONLY);
	t_range				*lst = parsing(fd);
	unsigned long long	nb_fresh = 0;

	while (lst->next)
	{
		update_range(lst);
		lst = lst->next;
	}
	update_range(lst);
	while (lst->pre)
		lst = lst->pre;
	while (lst->next)
	{
		nb_fresh += 1 + lst->end - lst->start;
		lst = lst->next;
	}
	nb_fresh += 1 + lst->end - lst->start;
	while (lst->pre)
		lst = lst->pre;
	close(fd);
	lst_clear(lst);
	printf("\n%lld\n", nb_fresh);
}
