/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:08:23 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/08 17:08:39 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sqrt_ceil(int nbr)
{
	int i;

	i = 0;
	while (i * i < nbr)
		i++;
	return (i);
}
