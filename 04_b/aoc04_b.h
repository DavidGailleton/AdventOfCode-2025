/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc04_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:15:37 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/15 16:33:20 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC04_B_H
# define AOC04_B_H

typedef struct s_co
{
	int		i;
	int		j;
	void	*next;
}	t_co;

t_co	*new_co(int i, int j);
void	co_add_back(t_co **lst, t_co *new);
void	clear_lst(t_co *lst);

#endif
