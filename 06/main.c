/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:07:02 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 16:50:46 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc06.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// 55755415012 ; to low

unsigned long long	calculate_res(t_lst *lst)
{
	unsigned long long	res;

	if (!lst)
		return (0);
	if (lst->sign == '+')
		res = lst->nbrs[0] + lst->nbrs[1] + lst->nbrs[2] + lst->nbrs[3];
	if (lst->sign == '*')
		res = lst->nbrs[0] * lst->nbrs[1] * lst->nbrs[2] * lst->nbrs[3];
	printf("%llu %c %llu %c %llu %c %llu = ", lst->nbrs[0], lst->sign, lst->nbrs[1], lst->sign, lst->nbrs[2], lst->sign, lst->nbrs[3]);
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
