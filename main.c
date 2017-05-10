/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:10:51 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 19:04:38 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			main(int ac, char **av)
{
	char	*ttris;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (0);
	}
	ttris = ft_read_file(av[1]);
	ft_putnbr(ft_istetrimino(ft_convert_to_nb(ttris)));
//	if (!ft_isvalid(ttris))
//	{
//		ft_putendl("error");
//		return (0);
//	}
//	else
///	{
//		ft_putendl("valid file");
//		return (0);
//	}
//	ft_analysis(ttris);
//	ft_solve(ttris);
	return (0);
}
