/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:41:24 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/11 12:08:28 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define MAX_SIZE 26
# define COR_TET0 "#...\n#...\n#...\n#...\n"
# define COR_TET1 "####\n....\n....\n....\n"
# define COR_TET2 "##..\n##..\n....\n....\n"
# define COR_TET3 "##..\n.##.\n....\n....\n"
# define COR_TET4 ".##.\n##..\n....\n....\n"
# define COR_TET5 "#...\n##..\n.#..\n....\n"
# define COR_TET6 ".#..\n##..\n#...\n....\n"
# define COR_TET7 "#...\n###.\n....\n....\n"
# define COR_TET8 "##..\n#...\n#...\n....\n"
# define COR_TET9 "##..\n.#..\n.#..\n....\n"
# define COR_TET10 "..#.\n###.\n....\n....\n"
# define COR_TET11 "###.\n#...\n....\n....\n"
# define COR_TET12 "###.\n..#.\n....\n....\n"
# define COR_TET13 "#...\n#...\n##..\n....\n"
# define COR_TET14 ".#..\n.#..\n##..\n....\n"
# define COR_TET15 ".#..\n##..\n.#..\n....\n"
# define COR_TET16 "#...\n##..\n#...\n....\n"
# define COR_TET17 "###.\n.#..\n....\n....\n"
# define COR_TET18 ".#..\n###.\n....\n....\n"

# include <fcntl.h>
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

int				sqrt_ceil(int nbr);
int				arrlen(char **arr);
char			**arrdup(char **arr);
void			arrdel(char ***arr);
void			arrprint(char **arr);
int				read_file(char *file_name, char ****tetr);
int				return_number(char **ttr, char ***examples);
int				expend(char ***map, int new_size);
int				is_free(char **map, char **ttr, t_point p, int size);
char			**fill(char **map, char **ttr, int index, t_point p);
char			**algorithm(int count, int *inp, char ***cor_tetr);

#endif
