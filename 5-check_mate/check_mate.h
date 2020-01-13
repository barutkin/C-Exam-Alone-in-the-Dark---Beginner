/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:08:11 by exam              #+#    #+#             */
/*   Updated: 2020/01/13 22:23:16 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <unistd.h>
# include <stdlib.h>

# define PIECES_COUNT		5
# define PIECE_MAX_COUNT	8
# define AXIS_COUNT			2
# define P					0
# define B					1
# define R					2
# define Q					3
# define K					4

int			is_free(int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int row, int col);
int			check_P(int board_size,
					int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int piecescount[PIECES_COUNT]);
int			check_B(int board_size,
					int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int piecescount[PIECES_COUNT]);
int			check_R(int board_size,
					int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int piecescount[PIECES_COUNT]);
int			check_Q(int board_size,
					int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int piecescount[PIECES_COUNT]);

#endif
