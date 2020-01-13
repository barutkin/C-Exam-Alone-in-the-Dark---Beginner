/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:30:44 by exam              #+#    #+#             */
/*   Updated: 2020/01/13 22:16:14 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int			check_B(int board_size, int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT], int piecescount[PIECES_COUNT])
{
	int		i;
	int		j;
	int		p;

	if (pieces[B][0][0] == -1)
		return (0);
	p = 0;
	while (p <= piecescount[B])
	{
		i = pieces[B][p][0];
		j = pieces[B][p][1];
		while (--i >= 0 && --j >= 0)
		{
			if (is_free(pieces, i, j))
			{
				if (i == pieces[K][0][0] && j == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		i = pieces[B][p][0];
		j = pieces[B][p][1];
		while (++i < board_size && ++j < board_size)
		{
			if (is_free(pieces, i, j))
			{
				if (i == pieces[K][0][0] && j == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		i = pieces[B][p][0];
		j = pieces[B][p][1];
		while (--i < board_size && ++j < board_size)
		{
			if (is_free(pieces, i, j))
			{
				if (i == pieces[K][0][0] && j == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		i = pieces[B][p][0];
		j = pieces[B][p][1];
		while (++i < board_size && --j < board_size)
		{
			if (is_free(pieces, i, j))
			{
				if (i == pieces[K][0][0] && j == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		p++;
	}
	return (0);
}
