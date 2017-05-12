/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:56:20 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/12 14:14:30 by pmorrain         ###   ########.fr       */
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
