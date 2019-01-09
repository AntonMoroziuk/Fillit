/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:17:53 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/10 11:07:40 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_map;

int		recursion(char ***map, int ind, int *inp, char ***cor_tetr)
{
	char	**c_map;
	int		size;
	t_point	p;

	if (inp[ind] == -1)
		return (1);
	p.x = -1;
	size = ft_strlen(**map);
	while (++p.x < size)
	{
		p.y = -1;
		while (++p.y < size)
			if (is_free(*map, cor_tetr[inp[ind]], p, size))
			{
				c_map = fill(arrdup(*map), cor_tetr[inp[ind]], ind, p);
				if (recursion(&c_map, ind + 1, inp, cor_tetr))
				{
					arrdel(map);
					*map = c_map;
					return (1);
				}
				arrdel(&c_map);
			}
	}
	return (0);
}

char	**algorithm(int count, int *inp, char ***cor_tetr)
{
	char	**map;
	int		size;

	map = NULL;
	size = sqrt_ceil(count * 4);
	if (expend(&map, size))
		return (NULL);
	while (1)
	{
		if (recursion(&map, 0, inp, cor_tetr))
			return (map);
		size++;
		if (expend(&map, size))
			return (NULL);
	}
}
