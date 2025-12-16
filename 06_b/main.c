/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:07:02 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 19:30:20 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc06.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

unsigned long long	calculate_res(t_lst *lst)
{
	unsigned long long	res = 0;
	int					temp[4];
	int					i;
	int					j;

	if (!lst)
		return (0);
	j = 0;
	while (j < 4)
	{
		temp[j] = 0;
		i = 0;
		while (lst->nbrs[i][j])
		{
			if (ft_isdigit(lst->nbrs[i][j]))
				temp[j] = (10 * temp[j]) + (lst->nbrs[i][j] - '0');
			i++;
		}
		j++;
	}
	j = 0;
	while (j < 4)
	{
		if (temp[j])
		{
			if (lst->sign == '+')
				res += temp[j];
			if (lst->sign == '*')
				res *= temp[j];
		}
		j++;
	}
	printf("%llu\n", res);
	return (res + calculate_res(lst->next));
}

int	main(void)
{
	int					fd = open("input", O_RDONLY);
	t_lst				*lst = parsing(fd);
	unsigned long long	res = 0;

	res = calculate_res(lst);
	lst_clear(lst);
	close (fd);
	printf("%llu\n", res);
}
