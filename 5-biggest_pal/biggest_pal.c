/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:03:49 by exam              #+#    #+#             */
/*   Updated: 2020/01/19 12:10:43 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define PAL_LEN		30000
#define STR_LEN_MAX	30000

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		ft_strscan(char *str, int strlen, int *isnext)
{
	int		i;
	int		j;

	i = 0;
	while (i < strlen - 1)
	{
		isnext[i] = 0;
		j = strlen;
		while (j > i)
		{
			if (str[i] == str[j] && (isnext[i] = j))
				break;
			j--;
		}
		i++;
	}
}

void		ft_palinit(char *pal)
{
	int		i;

	i = 0;
	while (i < PAL_LEN)
		pal[i++] = '\0';
}

int			main(int argc, char **argv)
{
	int		strlen;
	int		ileft;
	int		i;
	int		iright;
	int		j;
	int		isnext[STR_LEN_MAX];
	char	pal[PAL_LEN];
	int		pallen;
	int		k;

	if (argc == 2)
	{
		strlen = ft_strlen(argv[1]);
		ft_strscan(argv[1], strlen, isnext);
		ft_palinit(pal);
		pallen = 0;
		ileft = 0;
		while (ileft < strlen && pallen < strlen - ileft + 1)
		{
			i = ileft;
			iright = isnext[ileft];
			j = 0;
			while (iright > i && isnext[i])
			{
				if (argv[1][i] == argv[1][iright])
				{
					i++;
					iright--;
				}
				else
				{
					i = ileft;
					iright = isnext[ileft] - ++j;
				}
			}
			if (i >= iright && pallen <= isnext[ileft] - j + 1 - ileft)
			{
				pallen = isnext[ileft] - j + 1 - ileft;
				k = -1;
				while (++k < pallen)
					pal[k] = argv[1][ileft + k];
			}
			ileft++;
		}
		ft_putstr(pal);
	}
	ft_putstr("\n");
	return (0);
}
