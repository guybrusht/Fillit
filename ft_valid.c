/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:57:01 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/12 14:55:02 by pmorrain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_tmino(char *tmino)
{
	int		i;
	int		hash;
	int		dot;
	int		n;

	i = 0;
	n = 0;
	hash = 0;
	dot = 0;
	if (ft_strlen(tmino) != 19)
		return (0);
	while (tmino[i])
	{
		if (tmino[i] == '.')
			dot++;
		else if (tmino[i] == '#')
			hash++;
		else if (tmino[i] == '\n')
			n++;
		i++;
	}
	if (hash != 4 || dot != 12 || n != 3)
		return (0);
	return (1);
}

int			ft_check_tab(char **ttristab)
{
	int		i;

	i = 0;
	while (ttristab[i])
	{
		if (!ft_check_tmino(ttristab[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_valid(char **ttristab, int tablen)
{
	int		i;

	i = 0;
	while (ttristab[i] && ft_is_tetrimino(ft_convert_to_nb(ttristab[i])))
	{
		i++;
	}
	if ((i == tablen) && ft_check_tab(ttristab))
		return (1);
	return (0);
}

int		ft_is_tetrimino(int nb)
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
