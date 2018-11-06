/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:40:15 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/06 11:04:02 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***tetriminos;

	if (argc != 2)
		ft_putendl("usage: ./fillit task_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		tetriminos = input(fd);
	}
	return (0);
}
