/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:32:21 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 14:46:57 by alalaoui         ###   ########.fr       */
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

int			ft_analysis(char *ttris)
{
	printf("%d\n", ft_tetriminos_nb(ttris));
	return (0);
}
