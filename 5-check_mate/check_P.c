/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_P.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:29:51 by exam              #+#    #+#             */
/*   Updated: 2020/01/13 22:23:13 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int			check_P(int board_size, int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT], int piecescount[PIECES_COUNT])
{
	int		p;

	if (pieces[P][0][0] == -1)
		return (0);
	p = 0;
	while (p <= piecescount[P])
	{
		if ((pieces[P][p][0] > 0 && pieces[P][p][1] > 0) &&
			(pieces[P][p][0] - 1 == pieces[K][0][0] &&
			 pieces[P][p][1] - 1 == pieces[K][0][1]))
			return (1);
		else if ((pieces[P][p][0] > 0 && pieces[P][p][1] < board_size - 1) &&
				(pieces[P][p][0] - 1 == pieces[K][0][0] &&
				 pieces[P][p][1] + 1 == pieces[K][0][1]))
			return (1);
		p++;
	}
	return (0);
}
