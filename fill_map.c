/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:52:06 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/10 11:00:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_free(char **map, char **ttr, t_point p, int size)
{
	int		i;
	int		j;
	int		old_j;
	int		count;

	i = -1;
	count = 0;
	old_j = p.y;
	while (p.x < size && ++i < 4)
	{
		p.y = old_j;
		j = -1;
		while (p.y < size && ++j < 4)
		{
			if (map[p.x][p.y] != '.' && ttr[i][j] == '#')
				return (0);
			if (ttr[i][j] == '#')
				count++;
			p.y++;
		}
		p.x++;
	}
	return (count == 4);
}

char	**fill(char **map, char **ttr, int index, t_point p)
{
	int		i;
	int		j;
	int		size;
	int		old_j;

	i = 0;
	j = 0;
	old_j = p.y;
	size = ft_strlen(map[0]);
	while (p.x < size && i < 4)
	{
		p.y = old_j;
		j = 0;
		while (p.y < size && j < 4)
		{
			if (ttr[i][j] == '#')
				map[p.x][p.y] = 'A' + index;
			p.y++;
			j++;
		}
		i++;
		p.x++;
	}
	return (map);
}
