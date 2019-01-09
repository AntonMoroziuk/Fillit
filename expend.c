/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:37:48 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/08 15:48:17 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		expend(char ***map, int new_size)
{
	int		i;
	char	**arr;

	arrdel(map);
	MALLOCCHECK((arr = (char **)malloc(sizeof(char *) * (new_size + 1))));
	arr[new_size] = NULL;
	i = 0;
	while (i < new_size)
	{
		if (!(arr[i] = (char *)malloc(sizeof(char) * (new_size + 1))))
			return (-1);
		ft_memset((arr)[i], '.', new_size);
		arr[i++][new_size] = '\0';
	}
	*map = arr;
	return (0);
}
