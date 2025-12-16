/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:44:11 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 10:55:36 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc05.h"
#include "get_next_char.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_fresh(t_range *lst, long long ingredient)
{
	while (lst)
	{
		if (lst->start <= ingredient && lst->end >= ingredient)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	main(void)
{
	int		fd = open("input", O_RDONLY);
	t_range	*lst = parsing(fd);
	int		nb_fresh = 0;
	char	*temp;

	temp = get_next_char(fd, '\n');
	while (temp)
	{
		nb_fresh += is_fresh(lst, atoll(temp));
		free(temp);
		temp = get_next_char(fd, '\n');
	}
	close(fd);
	lst_clear(lst);
	printf("%d\n", nb_fresh);
}
