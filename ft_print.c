/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:56:20 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/19 15:24:57 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_ttris(char **ttristab)
{
	int		i;

	i = 0;
	while (ttristab[i])
	{
		ft_putstr("Tmino #");
		ft_putnbr(i + 1);
		ft_putchar('\n');
		ft_putendl(ttristab[i]);
		ft_putstr("----\n");
		i++;
	}
}

void		ft_print_result(char *map)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	printf("mapsize:%d\n", ft_sqrt(len -1));
	while (map[i])
	{
		if (i % ft_sqrt(len - 1) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(map[i]);
		i++;
	}
	ft_putchar('\n');
}
