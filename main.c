/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:37:37 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/11 12:08:09 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**to_arr(char *s)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char**)malloc(sizeof(char*) * 5);
	arr[4] = NULL;
	i = -1;
	while (++i < 5)
		arr[i] = (char*)malloc(sizeof(char) * 5);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			arr[i][j] = s[i * 5 + j];
		arr[i][j] = '\0';
	}
	return (arr);
}

void	get_examples(char ****cor_tet)
{
	*cor_tet = (char***)malloc(sizeof(char**) * 20);
	(*cor_tet)[0] = to_arr(COR_TET0);
	(*cor_tet)[1] = to_arr(COR_TET1);
	(*cor_tet)[2] = to_arr(COR_TET2);
	(*cor_tet)[3] = to_arr(COR_TET3);
	(*cor_tet)[4] = to_arr(COR_TET4);
	(*cor_tet)[5] = to_arr(COR_TET5);
	(*cor_tet)[6] = to_arr(COR_TET6);
	(*cor_tet)[7] = to_arr(COR_TET7);
	(*cor_tet)[8] = to_arr(COR_TET8);
	(*cor_tet)[9] = to_arr(COR_TET9);
	(*cor_tet)[10] = to_arr(COR_TET10);
	(*cor_tet)[11] = to_arr(COR_TET11);
	(*cor_tet)[12] = to_arr(COR_TET12);
	(*cor_tet)[13] = to_arr(COR_TET13);
	(*cor_tet)[14] = to_arr(COR_TET14);
	(*cor_tet)[15] = to_arr(COR_TET15);
	(*cor_tet)[16] = to_arr(COR_TET16);
	(*cor_tet)[17] = to_arr(COR_TET17);
	(*cor_tet)[18] = to_arr(COR_TET18);
}

int		check_input(int ac, char **ar, char ****tetriminos)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit task_file");
		return (1);
	}
	if (read_file(ar[1], tetriminos))
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **ar)
{
	char	***tetriminos;
	char	***cor_tet;
	int		arr[MAX_SIZE];
	char	**map;
	int		i;

	if (check_input(ac, ar, &tetriminos))
		return (0);
	get_examples(&cor_tet);
	i = 0;
	while (i < MAX_SIZE)
		arr[i++] = -1;
	i = -1;
	while (tetriminos[++i])
	{
		arr[i] = return_number(tetriminos[i], cor_tet);
		if (arr[i] == -1)
		{
			ft_putendl("error");
			return (0);
		}
	}
	map = algorithm(i, arr, cor_tet);
	arrprint(map);
	return (0);
}
