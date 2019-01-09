/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:06:23 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/10 10:46:16 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char **ttr, char **ex, int i_ttr, int j_ttr)
{
	int		count;
	int		i;
	int		j;
	int		old_j;

	count = 0;
	i = 0;
	old_j = j_ttr;
	while (i_ttr < 4)
	{
		j = 0;
		j_ttr = old_j;
		while (j_ttr < 4)
		{
			if (ttr[i_ttr][j_ttr] != ex[i][j])
				return (0);
			if (ex[i][j] == '#')
				count++;
			j_ttr++;
			j++;
		}
		i++;
		i_ttr++;
	}
	return (count == 4);
}

int		equal(char **ttr, char **ex)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (check(ttr, ex, i, j))
				return (1);
	}
	return (0);
}

int		return_number(char **ttr, char ***examples)
{
	int		i;

	i = -1;
	while (++i < 19)
	{
		if (equal(ttr, examples[i]))
			return (i);
	}
	return (-1);
}
