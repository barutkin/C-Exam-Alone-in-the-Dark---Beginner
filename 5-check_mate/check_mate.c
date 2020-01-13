/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:07:58 by exam              #+#    #+#             */
/*   Updated: 2020/01/13 22:24:06 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len) != '\0')
		len++;
	return (len);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		init_pieces(int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
							int piecescount[PIECES_COUNT])
{
	int		p;
	int		i;
	int		j;

	p = 0;
	while (p < PIECES_COUNT)
	{
		i = 0;
		while (i < PIECE_MAX_COUNT)
		{
				j = 0;
				while (j < AXIS_COUNT)
					pieces[p][i][j++] = -1;
			i++;
		}
		piecescount[p] = -1;
		p++;
	}
}

void		get_pieces(int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
				int piecescount[PIECES_COUNT], char **board, int board_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			if (board[i + 1][j] == 'P')
			{
				piecescount[P]++;
				pieces[P][piecescount[P]][0] = i;
				pieces[P][piecescount[P]][1] = j;
			}
			else if (board[i + 1][j] == 'B')
			{
				piecescount[B]++;
				pieces[B][piecescount[B]][0] = i;
				pieces[B][piecescount[B]][1] = j;
			}
			else if (board[i + 1][j] == 'R')
			{
				piecescount[R]++;
				pieces[R][piecescount[R]][0] = i;
				pieces[R][piecescount[R]][1] = j;
			}
			else if (board[i + 1][j] == 'Q')
			{
				piecescount[Q]++;
				pieces[Q][piecescount[Q]][0] = i;
				pieces[Q][piecescount[Q]][1] = j;
			}
			else if (board[i + 1][j] == 'K')
			{
				piecescount[K]++;
				pieces[K][piecescount[K]][0] = i;
				pieces[K][piecescount[K]][1] = j;
			}
			j++;
		}
		i++;
	}
}

void		printboard(int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
							int board_size)
{
	int		p;
	int		pp;
	int		i;
	int		j;
	int		isfree;

	i = 0;
	isfree = 1;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			p = 0;
			while (p < PIECES_COUNT)
			{
				pp = 0;
				while (pp < PIECE_MAX_COUNT)
				{
					if (pieces[p][pp][0] == i && pieces[p][pp][1] == j)
					{
						if (p == P && !(isfree = 0))
							ft_putchar('P');
						else if (p == B && !(isfree = 0))
							ft_putchar('B');
						else if (p == R && !(isfree = 0))
							ft_putchar('R');
						else if (p == Q && !(isfree = 0))
							ft_putchar('Q');
						else if (p == K && !(isfree = 0))
							ft_putchar('K');
					}
					pp++;
				}
				p++;
			}
			if (isfree)
				ft_putchar('-');
			else
				isfree = 1;
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	p++;
}

int			is_free(int pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT],
					int row, int col)
{
	int		p;

	p = 0;
	while (p < PIECE_MAX_COUNT)
	{
		if ((pieces[P][p][0] == row && pieces[P][p][1] == col) ||
				(pieces[B][p][0] == row && pieces[B][p][1] == col) ||
				(pieces[R][p][0] == row && pieces[R][p][1] == col) ||
				(pieces[Q][p][0] == row && pieces[Q][p][1] == col))
			return (0);
		p++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		board_size;
	int		pieces[PIECES_COUNT][PIECE_MAX_COUNT][AXIS_COUNT];
	int		piecescount[PIECES_COUNT];

	if (argc == 1)
		ft_putchar('\n');
	else
	{
		board_size = ft_strlen(argv[1]);
		init_pieces(pieces, piecescount);
		get_pieces(pieces, piecescount, argv, board_size);
		/* printboard(pieces, board_size); */
		if (pieces[PIECES_COUNT - 1][0][0] != -1)
		{
			if (check_P(board_size, pieces, piecescount) ||
				check_B(board_size, pieces, piecescount) ||
				check_R(board_size, pieces, piecescount) ||
				check_Q(board_size, pieces, piecescount))
			{
				ft_putstr("Success\n");
				return (0);
			}

		}
		ft_putstr("Fail\n");
	}
	return (0);
}
