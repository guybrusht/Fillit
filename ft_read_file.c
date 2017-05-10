/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:54:49 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 12:23:59 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

/*
** On prend un bufffer de 545 car il correspond au plus grand nb de
** tetriminos recu
** declaration en static du buf car est free sinon (warning stack adress)
*/

char		*ft_read_file(char *desc)
{
	int		ret;
	int		fd;
	static char	buf[545];

	if ((fd = open(desc, O_RDONLY)) == -1)
	{
		ft_putendl("error : File didn't open");
		return (0);
	}
	ret = read(fd, buf, 545);
	buf[ret] = '\0';
	return (buf);
}
