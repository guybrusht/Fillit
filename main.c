/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:10:51 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/15 18:29:05 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	char	**ttristab;
	char	*ttris;
	int		tablen;

	ttristab = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (0);
	}
	ttris = ft_read_file(av[1]);
	tablen = ft_tetriminos_nb(ttris);
	if (tablen)
		ttristab = ft_split_tmino(ttris, tablen);
	if (ttristab == NULL || (!ft_is_valid(ttristab, tablen)))
	{
		ft_putendl("error");
		return (0);
	}
	ft_print_ttris(ttristab);
	ft_putendl("Map:");
	printf("%s\n", ft_map(ttristab));
	return (0);
}
