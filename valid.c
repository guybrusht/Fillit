/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:08:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/09 17:34:27 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_isvalid(char *desc)
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
