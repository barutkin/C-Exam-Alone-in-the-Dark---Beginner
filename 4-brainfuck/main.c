/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:38:12 by exam              #+#    #+#             */
/*   Updated: 2020/01/12 14:15:45 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BYTE_MAX_LEN	2048
#define CYCLE_MAX_NUM	10

void	arraysinit(int bytes[BYTE_MAX_LEN], int cycles[CYCLE_MAX_NUM][2])
{
	int	ibyte;
	int	icycle;

	ibyte = 0;
	while (ibyte < BYTE_MAX_LEN)
		bytes[ibyte++] = 0;
	icycle = 0;
	while (icycle < CYCLE_MAX_NUM)
	{
		cycles[icycle][0] = 0;
		cycles[icycle][1] = 0;
		icycle++;
	}
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	codescan(char *srccode, int cycles[CYCLE_MAX_NUM][2])
{
	int	i;
	int	icycle;
	int	srccodelen;

	srccodelen = ft_strlen(srccode);
	i = 0;
	icycle = -1;
	while (i < srccodelen)
	{
		if (srccode[i] == '[')
			cycles[++icycle][0] = i;
		else if (srccode[i] == ']')
			cycles[icycle--][1] = i;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	bytes[BYTE_MAX_LEN];
	int cycles[CYCLE_MAX_NUM][2];
	int	ibyte;
	int icycle;
	int	i;
	int	srccodelen;

	if (argc == 2)
	{
		arraysinit(bytes, cycles);
		codescan(argv[1], cycles);
		ibyte = 0;
		icycle = -1;
		i = 0;
		srccodelen = ft_strlen(argv[1]);
		while (i < srccodelen)
		{
			if (argv[1][i] == '>')
				ibyte++;
			else if (argv[1][i] == '<')
				ibyte--;
			else if (argv[1][i] == '+')
				bytes[ibyte]++;
			else if (argv[1][i] == '-')
				bytes[ibyte]--;
			else if (argv[1][i] == '.')
				write(1, &bytes[ibyte], 1);
			else if (argv[1][i] == '[' && bytes[ibyte] == 0)
				i = cycles[icycle + 1][1];
			else if (argv[1][i] == '[' && bytes[ibyte] != 0)
				icycle++;
			else if (argv[1][i] == ']' && bytes[ibyte] != 0)
				i = cycles[icycle][0];
			else if (argv[1][i] == ']' && bytes[ibyte] == 0)
				icycle--;
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
