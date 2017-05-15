/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:22:16 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/15 13:18:03 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_map(char **ttristab, int tablen)
{
	char	*map;
	int		size;
	int		i;
	int		j;

	size = 4;
	i = 0;
	j = 0;
	if (!(map = (char*)malloc(sizeof(char) * ((size * size) + 1))))
		return (NULL);
	while (ttristab[i][j])
	{
		
	}
}

int			ft_is_free(char *map, char *tmino)
{
	
}
