/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:32:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/10 16:08:43 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

typedef struct s_list
{
	int				nb;
	char			rank;
	char			*tminos;
	struct s_list	next;
}			t_tris;
int			ft_convert_to_nb(char *tab);
char		*ft_read_file(char *av);
int			ft_analysis(char *ttris);
int			ft_tetriminos_nb(char *ttris);
int			ft_isvalid(char *ttris);

#endif
