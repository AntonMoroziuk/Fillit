/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:01:08 by pzakala           #+#    #+#             */
/*   Updated: 2018/11/08 17:07:51 by pzakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**arrdup(char **arr)
{
	int		len;
	int		i;
	char	**new_arr;

	len = arrlen(arr);
	if (!(new_arr = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[len] = NULL;
	return (new_arr);
}
