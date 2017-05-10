/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:32:21 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/09 17:35:10 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			ft_tetriminos_nb(char *desc)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (desc[i] != '\0')
	{
		if (desc[i] == '\n' && (desc[i + 1] == '\n' || desc[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}
