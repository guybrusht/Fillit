/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:22:16 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/16 15:25:22 by alalaoui         ###   ########.fr       */
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
	ft_memset(map, '.', 122);
	size = 12;
	i = 0;
	ft_algo(map, size, pos, ttristab, i);
//	while (size < 12 && !ft_algo(map, size, pos, ttristab))
//	{
	
//	//	ft_memset(map, '.', 122);
//		size++;
//	}
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
		if (tmino[i] == '#' && (ft_isupper(map[pos + offset]) ||
					(pos % size + offset % size > size) || (pos + offset >= size * size)))
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

int			ft_algo(char *map, int size, int pos, char **ttristab, int i)
{
	if (ttristab[i] != NULL)
	{
		while (!ft_is_free(map, size, pos, ttristab[i]))
		{
			pos++;
			if (pos > size * size - 3)
				return (0);
		}
		ft_fill_map(map, size, pos, ttristab[i], i);
		if (!ft_algo(map, size, pos, &ttristab[i + 1], i + 1))
		{
			ft_erase_letter(map, size, pos, ttristab[i]);
			pos++;
			return (ft_algo(map, size, pos, &ttristab[i], i));
		}
	}
	return (1);
}

/*
   int			ft_fill(char *map, int size, char **ttristab)
   {
   int		i;
   int		j;
   int		pos;
   int		offset;
   int		count;


   i = 0;
   while (ttristab[i])
   {
   pos = 0;
   while (pos < size * size - 3)
   {
   printf("Pos = %d, Size = %d\n", pos, size);
   if (ft_is_free(map, size, pos, ttristab[i]))
   {
   count = 0;
   j = 0;
   while (ttristab[i][j])
   {
   offset = (j / 5) * size + j % 5;
   if (ttristab[i][j] == '#')
   {
   printf("i = %d; j = %d\n", i, j);
   map[pos + offset] = ttristab[i][j];
   count++;
   }
   j++;
   if (count == 4)
   return (1);
   }
//return (1);			
//ft_fill(map, size, ttristab);
}
pos++;
}
i++;
}
return (0);
}*/
