/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:08:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/11 18:52:16 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "shapes.h"
#include "fillit.h"
/*
int			ft_check_ttris(char *ttris)
{
	int		i;
	int		n;
	int		test;

	i = 0;
	n = 0;
	test = 4 * ft_tetriminos_nb(ttris) + (ft_tetriminos_nb(ttris) - 1);
	while (ttris[i])
	{
		if (ttris[i] != '.' && ttris[i] != '#' && ttris[i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (ttris[i] && i < ft_strlen(ttris))
	{
		if (ttris[i + 4] == '\n')
		{
			n++;
			i += 5;
		}
		else if (ttris[i] == '\n')
		{
			n++;
			i++;
		}
		else
			return (0);
	}
	if (n == test)
		return (1);
	return (0);
}*/

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
	printf("strlen:%d\n", ft_strlen(tmino));
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
// CA FOIRE A CAUSE DE LA BOUSE DE PMORRAIN LES TRUCS SONT PAS AU BON FORMAT

int			ft_isvalid(char **ttristab)
{
	int		i;

	i = 0;
	while (ttristab[i] && ft_is_tetrimino(ft_convert_to_nb(ttristab[i])))
		i++;
	printf("piece correspond:%d\n tminos format:%d\n", i, ft_check_tab(ttristab));
	if ((i == ft_tetriminos_nb(ttris)) && ft_check_tab(ttristab))
		return (1);
	return (0);
}

int			ft_simplify_tmino(int nb)
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
