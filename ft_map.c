/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:22:16 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/28 17:41:36 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_init_map(char **ttristab)
{
	char	*map;
	int		size;
	int		i;
	int		pos;

	pos = 0;
	map = (char*)malloc(122 * sizeof(char));
	ft_memset(map, '.', 121);
	size = ft_uppersqrt(4 * ft_nb_tminos(ttristab));
	map[size * size] = '\0';
	i = 0;
	while (size < 12 && !ft_algo(map, size, pos, ttristab))
	{
		size++;
		ft_memset(map, '.', size * size);
		map[size * size] = '\0';
	}
	return (map);
}

int			ft_is_free(char *map, int size, int pos, char *tmino)
{
	int		i;
	int		offset;

	offset = 0;
	i = 0;
	while (tmino[i])
	{
		offset = (i / 5) * size + i % 5;
		if (tmino[i] == '#' && (ft_isupper(map[pos + offset])
					|| (pos % size + offset % size >= size)
					|| (pos + offset >= size * size)))
			return (0);
		i++;
	}
	return (1);
}

void		ft_fill_map(char *map, int pos, char *tmino, int letter)
{
	int		offset;
	int		i;
	int		size;

	size = ft_map_size(map);
	i = 0;
	offset = 0;
	while (tmino[i])
	{
		offset = (i / 5) * size + i % 5;
		if (tmino[i] == '#')
			map[pos + offset] = 'A' + letter;
		i++;
	}
}

void		ft_erase_letter(char *map, int size, int pos, char *tmino)
{
	int		offset;
	int		i;

	i = 0;
	offset = 0;
	while (tmino[i])
	{
		offset = (i / 5) * size + i % 5;
		if (tmino[i] == '#')
			map[pos + offset] = '.';
		i++;
	}
}

int			ft_algo(char *map, int size, int pos, char **ttristab)
{
	static int	i = 0;

	if (ttristab[i] != NULL)
	{
		while (pos <= size * size - 3)
		{
			while (!ft_is_free(map, size, pos, ttristab[i]))
			{
				pos++;
				if (pos > size * size - 3)
					return (0);
			}
			ft_fill_map(map, pos, ttristab[i], i);
			i++;
			if (ft_algo(map, size, 0, ttristab))
				return (1);
			else
				ft_erase_letter(map, size, pos, ttristab[--i]);
			pos++;
		}
		return (0);
	}
	return (1);
}
