/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc05.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:28:12 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/16 10:55:28 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC05_H
# define AOC05_H

typedef struct s_range
{
	long long	start;
	long long	end;
	void		*next;
}	t_range;

t_range	*parsing(int fd);
void	lst_clear(t_range *lst);

#endif
