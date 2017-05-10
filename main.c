/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:10:51 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 14:48:12 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//creer fonction ft_error?

int			main(int ac, char **av)
{
	char	*ttris;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (0);
	}
	ttris = ft_read_file(av[1]);
//	if (!ft_isvalid(ttris))
//	{
//		ft_putendl("error");
//		return (0);
//	}
	ft_analysis(ttris);
//	ft_solve(ttris);
	return (0);
}
