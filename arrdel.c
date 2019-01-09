/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:10:01 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/08 17:10:26 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	arrdel(char ***arr)
{
	char	**a;

	if (!arr || !(*arr))
		return ;
	a = *arr;
	while (*a)
	{
		free(*a);
		a++;
	}
	free(*arr);
	*arr = NULL;
}