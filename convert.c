/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:13:56 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 18:26:11 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_convert_to_nb(char *ttris)
{
	int		nb;
	int		i;
	int		j;

	i = 0;
	nb = 0;
	j = 0;
	while (ttris[i] && j < 16)
	{
		if (ttris[i] != '\n')
		{
			nb *= 2;
			j++;
		}
		if (ttris[i] == '#')
			nb++;
		i++;
	
	return (nb);
}

char		*ft_convert_to_str(int itminos)
{
	char	*tmino;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmino = (char*)malloc(sizeof(*tminos) * 21)))
		return (NULL);
	while ()
}
