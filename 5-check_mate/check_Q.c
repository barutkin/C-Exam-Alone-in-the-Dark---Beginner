/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_Q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:31:36 by exam              #+#    #+#             */
/*   Updated: 2020/01/13 22:22:48 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int			check_Q(int board_size, int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT], int piecescount[PIECES_COUNT])
{
	int		i;
	int		j;
	int		p;

	if (pieces[Q][0][0] == -1)
		return (0);
	p = 0;
	while (p <= piecescount[B])
	{
		i = pieces[Q][p][1];
		while (--i >= 0)
		{
			if (is_free(pieces, pieces[Q][p][0], i))
			{
				if (pieces[Q][p][0] == pieces[K][0][0] && i == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		i = pieces[Q][p][1];
		while (++i < board_size)
		{
			if (is_free(pieces, pieces[Q][p][0], i))
			{
				if (pieces[Q][p][0] == pieces[K][0][0] && i == pieces[K][0][1])
					return (1);
			}
			else
				break;
		}
		i = pieces[Q][p][0];
		while (--i >= 0)
		{
			if (is_free(pieces, i, pieces[Q][p][1]))
			{
				if (pieces[Q][p][1] == pieces[K][0][1] && i == pieces[K][0][0])
					return (1);
			}
			else
				break;
		}
		i = pieces[Q][p][0];
		while (++i < board_size)
		{
			if (is_free(pieces, i, pieces[Q][p][1]))
			{
				if (pieces[Q][p][1] == pieces[K][0][1] && i == pieces[K][0][0])
					return (1);
			}
			else
				break;
		}
		i = pieces[Q][p][0];
		j = pieces[Q][p][1];
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
		i = pieces[Q][p][0];
		j = pieces[Q][p][1];
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
		i = pieces[Q][p][0];
		j = pieces[Q][p][1];
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
		i = pieces[Q][p][0];
		j = pieces[Q][p][1];
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
