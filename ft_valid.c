/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:57:01 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/15 13:08:16 by pmorrain         ###   ########.fr       */
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
		ft_tmino_to_upperleft(ttristab[i]);
		i++;
	}
	return (1);
}

int			ft_is_valid(char **ttristab, int tablen)
{
	int		i;

	i = 0;
	while (ttristab[i] && ft_is_tetrimino(ft_convert_to_nb(ttristab[i])))
		i++;
	if ((i == tablen) && ft_check_tab(ttristab))
		return (1);
	return (0);
}

int		ft_is_tetrimino(int nb)
{
	int		s;

	s = ft_simplify_tmino(nb);
	if (s == N_SQUARE || s == N_HORI_LINE || s == N_VERT_LINE || s == N_T0
			|| s == N_T90 || s == N_T180 || s == N_T270 || s == N_L0
			|| s == N_L90 || s == N_L180 || s == N_L270 || s == N_SYM_L0
			|| s == N_SYM_L90 || s == N_SYM_L180 || s == N_SYM_L270
			|| s ==  N_S0 || s == N_S90 || s == N_Z0 || s == N_Z90)
		return (s);
	else
		return (0);
}

int ft_tmino_to_upperleft(char *tmino)
{
	int		s;

	s = ft_simplify_tmino(ft_convert_to_nb(tmino));
	(s == N_SQUARE) ? ft_strcpy(tmino, S_SQUARE) : 0;
	(s == N_HORI_LINE) ? ft_strcpy(tmino, S_HORI_LINE) : 0;
	(s == N_VERT_LINE) ? ft_strcpy(tmino, S_VERT_LINE) : 0;
	(s == N_T0) ? ft_strcpy(tmino, S_T0) : 0;
	(s == N_T90) ? ft_strcpy(tmino, S_T90) : 0;
	(s == N_T180) ? ft_strcpy(tmino, S_T180) : 0;
	(s == N_T270) ? ft_strcpy(tmino, S_T270) : 0;
	(s == N_L0) ? ft_strcpy(tmino, S_L0) : 0;
	(s == N_L90) ? ft_strcpy(tmino, S_L90) : 0;
	(s == N_L180) ? ft_strcpy(tmino, S_L180) : 0;
	(s == N_L270) ? ft_strcpy(tmino, S_L270) : 0;
	(s == N_SYM_L0) ? ft_strcpy(tmino, S_SYM_L0) : 0;
	(s == N_SYM_L90) ? ft_strcpy(tmino, S_SYM_L90) : 0;
	(s == N_SYM_L180) ? ft_strcpy(tmino, S_SYM_L180) : 0;
	(s == N_SYM_L270) ? ft_strcpy(tmino, S_SYM_L270) : 0;
	(s == N_S0) ? ft_strcpy(tmino, S_S0) : 0;
	(s == N_S90) ? ft_strcpy(tmino, S_S90) : 0;
	(s == N_Z0) ? ft_strcpy(tmino, S_Z0) : 0;
	(s == N_Z90) ? ft_strcpy(tmino, S_Z90) : 0;
	return (s);
}
