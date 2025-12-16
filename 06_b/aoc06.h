/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc06.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:27:06 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 20:06:30 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC06_H
# define AOC06_H

typedef struct s_lst
{
	char	nbrs[5][5];
	char	sign;
	void	*next;
	void	*pre;
}	t_lst;

t_lst	*parsing(int fd);
void	lst_clear(t_lst *lst);

#endif
