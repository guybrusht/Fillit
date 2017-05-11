/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:32:21 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/11 14:11:19 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			ft_tetriminos_nb(char *ttris)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (ttris[i] != '\0')
	{
		if (ttris[i] == '\n' && (ttris[i + 1] == '\n' || ttris[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

char		**ft_split_tmino(char *ttris)
{
	char	**ttristab;
	int		tablen;
	int		i;
	char	*last;
	char	*address;

	last = ft_strlen(ttris) + ttris;
	i = 0;
	tablen = ft_tetriminos_nb(ttris);
	ttristab = (char**)malloc(sizeof(char*) * (tablen + 1));
	while (i < tablen)
	{
		if ((address = ft_strstr(ttris, "\n\n")))
			ttristab[i] = ft_strsub(ttris, 0, (address - ttris));
		else
			ttristab[i] = ft_strsub(ttris, 0, last - ttris);
		ttris = address + 2;
		i++;
	}
	ttristab[tablen] = NULL;
	return (ttristab);
}
