/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:22:16 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/24 19:41:59 by pmorrain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_init_map(char **ttristab)
{
	//char			map[122];
	char			*map;
	int				size;
	int				i;
	int				pos;

	pos = 0;
	map = (char*)malloc(122 * sizeof(char));
	ft_memset(map, '.', 121);
//	printf("Strlen pre0: %d\n" , strlen(map));
//	printf("Strlen post0: %d\n" , strlen(map));
	size = ft_uppersqrt(4 * ft_nb_tminos(ttristab));
	map[size * size] = '\0';
	i = 0;
//	ft_algo(map, size, pos, ttristab, i);
	while (size < 12 && !ft_algo(map, size, pos, ttristab, 0))
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
				//	|| (pos % size + i > size)))
/*		if (tmino[i] == '#' && (ft_isupper(map[pos + offset]) ||
					(pos % size + offset > size) || (pos + offset < size * size)))*/
			return (0);
		i++;
	}
	return (1);
}

void		ft_fill_map(char *map, int size, int pos, char *tmino, int letter)
{
	int		offset;
	int		i;

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
/*
int			ft_algo(char *map, int size, int pos, char **ttristab, int i)
{
	int		total;

	total = 0;
	while (ttristab[total])
		total++;
	printf("TOTAL%d\n", total);
	if (total == 1)
		return (1);
	while (ttristab[i])
	{
		ft_print_result(map);
		if (ft_is_free(map, size, pos, ttristab[i]))
		{
			ft_fill_map(map, size, pos, ttristab[i], i);
			if (ft_algo(map, size, pos++, &ttristab[i], i))
				return (1);
			ft_erase_letter(map, size, pos, ttristab[i]);
		}
		i++;
	}
	return (0);
}
*/

/* OLD version. les pieces changent de forme.*/
/*int			ft_algo(char *map, int size, int pos, char **ttristab, int i)
{
	ft_print_result(map);
	if (ttristab[i] != NULL)
	{
		while (!ft_is_free(map, size, pos, ttristab[i]))
		{
			pos++;
			if (pos > size * size - 3)
				return (0);
		}
		ft_fill_map(map, size, pos, ttristab[i], i);
		//if (!ft_algo(map, size, pos, ttristab, i + 1))
		if (!ft_algo(map, size, 0, ttristab, i + 1))
		{
			ft_erase_letter(map, size, pos, ttristab[i]);
			pos++;
			return (ft_algo(map, size, pos, &ttristab[i], i));
		}
	}
	return (1);
}*/


int			ft_algo(char *map, int size, int pos, char **ttristab, int i)
{
	//ft_print_result(map);
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
			ft_fill_map(map, size, pos, ttristab[i], i);
			if (ft_algo(map, size, 0, ttristab, i + 1))
				return (1);
			else
				ft_erase_letter(map, size, pos, ttristab[i]);
			pos++;
		}
		return (0);
	}
	return (1);
}
