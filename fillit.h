/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:32:50 by alalaoui          #+#    #+#             */
/*   Updated: 2017/05/16 14:17:02 by alalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "shapes.h"
# include <stdio.h>

int				ft_convert_to_nb(char *tab);
char			*ft_read_file(char *av);
int				ft_tetriminos_nb(char *ttris);
int				ft_is_valid(char **ttristab, int tablen);
int				ft_simplify_tmino(int nb);
int				ft_is_noncontiguous(int nb);
int				ft_is_tetrimino(int nb);
char			**ft_split_tmino(char *ttris, int tablen);
int				ft_check_ttris(char *ttris);
void			ft_print_ttris(char **ttristab);
int				ft_tmino_to_upperleft(char *tmino);
char			*ft_init_map(char **ttristab);
int				ft_is_free(char *map, int size, int pos, char *tmino);
int				ft_algo(char *map, int size, int pos, char **ttristab, int i);
void			ft_fill_map(char *map, int size, int pos, char *tmino,
		int letter);
void			ft_erase_letter(char *map, int size, int pos, char *tmino);

#endif
