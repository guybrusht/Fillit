/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:08:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 19:12:54 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "shapes.h"
#include "fillit.h"

int		ft_isvalid(char *ttris)
{
	int	len;
	int	i;
	int line;

	line = 1;
	i = 0;
	len = ft_strlen(ttris);
	while (i < len)
	{
		if (ttris[i + 4] == '\n')
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

int		ft_simplify_tmino(int nb)
{
	while (!(nb & 15))
	{
		nb /= 2;
	}
	while (ft_is_noncontiguous(nb))
	{
		nb /= 2;
	}
	while (!(nb & 4369))
	{
		nb /= 2;
	}
	return (nb);
}

int		ft_is_noncontiguous(int nb)
{
	int	non_contiguous;
	int	tmp;

	non_contiguous = 0;
	tmp = nb >> 3;
	while (tmp)
	{
	if ((tmp & 3) == 3)
		non_contiguous = 1;
	tmp = tmp >> 4;
	}
	return (non_contiguous);
}

int		ft_istetrimino(int nb)
{
	int		s;
	
	s = ft_simplify_tmino(nb);
	if (s == SQUARE || s == HORI_LINE || s == VERT_LINE || s == T0 || s == T90
			|| s == T180 || s == T270 || s == L0 || s == L90 || s == L180
			|| s == L270 || s == SYM_L0 || s == SYM_L90 || s == SYM_L180
			|| s == SYM_L270 || s ==  S0 || s == S90 || s == Z0 || s == Z90)
		return (1);
	else
		return (0);
}
