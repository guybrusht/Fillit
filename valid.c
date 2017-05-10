/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:08:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 14:48:08 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_isvalid(char *ttris)
{
	int	len;
	int	i;
	int line;

	line = 1;
	i = 0;
	len = ft_strlen(desc);
	while (i < len)
	{
		if (desc[i + 4] == '\n')
		{
			line++;
			i += 5;
		}
		if (line == 4)
		{
			line = 1;
			i++;
		}
	}
	if (i == len)
		return (1);
	return (0);
}

int		ft_istetrimino(int nb)
{
	int		tmp;

	while (!(nb & 15))
		nb /= 2;
	while (ft_noncontiguous(nb))
		nb /= 2;
	while (!(nb & 4369))
		nb /= 2;
	return (nb);
}

int		ft_noncontiguous(int nb)
{
	int	noncontiguous;

	noncontiguous = 0;
	tmp = nb >> 3;
	while (tmp)
	{
	if (tmp & 3)
		noncontiguous = 1;
	tmp = tmp >> 4;
	}
	return (noncontiguous);
}
