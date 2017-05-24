/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:56:20 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/24 16:40:07 by pmorrain         ###   ########.fr       */
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
	int		sqrtlen;

	i = 0;
	len = 0;
	while (map[len])
		len++;
//	printf("Strlen:\t%d\n", len);
	sqrtlen = ft_sqrt(len);
	printf("Mapsize:\t%d\n", sqrtlen);
	while (map[i])
	{
		if (i % sqrtlen == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(map[i]);
		i++;
	}
	ft_putchar('\n');
}
