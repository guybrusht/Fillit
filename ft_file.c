/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorrain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:55:49 by pmorrain          #+#    #+#             */
/*   Updated: 2017/05/29 14:49:07 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

/*
** On prend un bufffer de 545 car il correspond au plus grand nb de
** tetriminos recu
** declaration en static du buf car est free sinon (warning stack adress)
*/

char		*ft_read_file(char *desc)
{
	int			ret;
	int			fd;
	static char	buf[545];

	if ((fd = open(desc, O_RDONLY)) == -1)
	{
		ft_putendl("error : File couldn't open");
		exit (0);
	}
	ret = read(fd, buf, 545);
	buf[ret] = '\0';
	close(fd);
	return (buf);
}
