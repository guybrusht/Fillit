/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:57:44 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/15 16:48:17 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_split_tmino(char *ttris, int tablen)
{
	char	**ttristab;
	int		i;
	char	*last;
	char	*address;

	last = ft_strlen(ttris) + ttris;
	i = 0;
	ttristab = (char**)malloc(sizeof(char*) * (tablen + 1));
	while (i < tablen && ttris < last)
	{
		address = ft_strstr(ttris, "\n\n");
		if (address == ttris)
			return (NULL);
		if (address != NULL)
			ttristab[i] = ft_strsub(ttris, 0, (address - ttris));
		else
			ttristab[i] = ft_strsub(ttris, 0, last - ttris - 1);
		ttris = address + 2;
		i++;
	}
	ttristab[tablen] = NULL;
	return (ttristab);
}

int			ft_tetriminos_nb(char *ttris)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (ttris[i] != '\0')
	{
		if ((ttris[i] == '\n' && (ttris[i + 1] == '\n' || ttris[i + 1] == '\0')))
		{	
			if ((i - 19) % 21 != 0)
				return (0);
			nb++;
		}
		i++;
	}
	return (nb);
}
