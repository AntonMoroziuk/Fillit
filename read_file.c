/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:56 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/10 10:59:04 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_chars(char c, char *str, int len)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (++i < len)
		if (str[i] == c)
			count++;
	return (count);
}

int		incorrect_char(char *str, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
	return (0);
}

int		check_lines(char *file_name)
{
	int		fd;
	char	buf[100];
	int		count_nl;
	int		count_sharps;
	int		rs;

	count_nl = 0;
	count_sharps = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	while ((rs = read(fd, buf, 100)))
	{
		if (incorrect_char(buf, rs))
			return (1);
		count_sharps += count_chars('#', buf, rs);
		count_nl += count_chars('\n', buf, rs);
	}
	close(fd);
	if ((count_sharps != ((count_nl + 1) / 5) * 4) || count_nl > 129)
		return (1);
	return (count_nl);
}

char	***create_arr(int lines)
{
	char	***arr;
	int		i;

	arr = (char***)malloc(sizeof(char**) * (lines + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < lines)
	{
		arr[i] = (char**)malloc(sizeof(char*) * 5);
		if (!arr[i])
			return (NULL);
		arr[i][4] = NULL;
	}
	arr[lines] = NULL;
	return (arr);
}

int		read_file(char *file_name, char ****tetr)
{
	int		fd;
	int		i;
	int		j;
	int		lines;
	char	*line;

	lines = check_lines(file_name);
	if (lines == -1 || (fd = open(file_name, O_RDONLY)) < 0 || lines % 5 != 4)
		return (-1);
	MALLOCCHECK(((*tetr = create_arr((lines + 1) / 5))));
	i = -1;
	while (++i < (lines + 1) / 5)
	{
		j = -1;
		while (++j < 4 && get_next_line(fd, &line))
			if (ft_strlen(line) != 4)
				return (-1);
			else
				(*tetr)[i][j] = ft_strdup(line);
		if (get_next_line(fd, &line) && line[0] != '\0')
			return (-1);
	}
	ft_strdel(&line);
	return (0);
}
