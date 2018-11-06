/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:27:59 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/06 11:05:59 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***create_array(void)
{
	char	***tetriminos;
	int		i;

	MALLCHECK((tetriminos = (char***)malloc(sizeof(char**) * 23)));
	i = -1;
	while (i < 23)
		tetriminos[++i] = NULL;
	return (tetriminos);
}

char	***input(const int fd)
{
	char	***tetriminos;

	MALLCHECK((tetriminos = create_array(void)));
	return (tetriminos);
}
