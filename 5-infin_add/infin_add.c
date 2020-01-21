/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:45:50 by rjeraldi          #+#    #+#             */
/*   Updated: 2020/01/21 14:12:28 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char		*ft_strrev(char *str)
{
	int		i;
	int		strlen;
	char	*strrev;

	strlen = ft_strlen(str);
	if ((strrev = (char *)malloc(strlen + 1)))
	{
		i = strlen;
		while (i > 0)
		{
			*(strrev + strlen - i) = *(str + i - 1);
			i--;
		}
		*(strrev + strlen + 1) = '\0';
	}
	return (strrev);
}

int			ft_abs(int num)
{
	return (num >= 0 ? num : -num);
}

int			ft_iszerostr(char *str, int strlen)
{
	int		i;
	int		iszero;

	iszero = 1;
	i = 0;
	while (i < strlen)
		if (str[i++] != '0')
			return (0);
	return (1);
}

char		*infin_add(char *num1, char *num2, int num1len, int num2len, const int sign1in, const int sign2in)
{
	int		i;
	char	*resrev;
	int		sum;
	int		sumsign;
	int		sumincr;
	int		sign1 = (int)sign1in;
	int		sign2 = (int)sign2in;
	int		digit1;

	sumsign = 1;
	if (sign1 == -1)
	{
		sign1 = 1;
		sumsign = -1;
		if (sign2 == 1)
			sign2 = -1;
		else if (sign2 == -1)
			sign2 = 1;
	}
	if ((resrev = (char *)malloc(sizeof(char) * (num1len + 3))))
	{
		sumincr = 0;
		i = 0;
		while (i < num2len)
		{
			digit1 = sumincr + num1[i] - '0';
			sum = digit1 + sign2 * (num2[i] - '0');
			if (digit1 < 0 && (sum += 10))
				sumincr = -1;
			else
				sumincr = sum / 10;
			if (sign2 == -1 && digit1 < num2[i] - '0' && (sum += 10))
				sumincr = -1;
			resrev[i++] = sum % 10 + '0';
		}
		/* (123 - 124) -> (124 - 123)*/
		if (num1len == num2len && sumincr < 0)
			return (infin_add(num2, num1, num2len, num1len, sign2in, sign1in));
		while (i < num1len)
		{
			digit1 = sumincr + num1[i] - '0';
			if (digit1 < 0 && (digit1 += 10))
				sumincr = -1;
			else
				sumincr = digit1 / 10;
			resrev[i++] = digit1 % 10 + '0';
		}
		if (sumincr)
			resrev[i++] = sumincr + '0';
		/* cut last zeros */
		while (i > 1 && resrev[i - 1] == '0')
			i--;
		/* fix -0 as return value */
		if (ft_iszerostr(resrev, i) && (sumsign = 1))
			i = 1;
		if (sumsign < 0)
			resrev[i++] = '-';
		resrev[i] = '\0';
	}
	return (resrev);
}

int			main(int argc, char **argv)
{
	int		num1len;
	int		num2len;
	int		sign1;
	int		sign2;
	char	*num1str;
	char	*num2str;

	if (argc == 3)
	{
		sign1 = 1;
		if (argv[1][0] == '-' && (sign1 = -1))
			num1len = ft_strlen((num1str = *(argv + 1) + 1));
		else
			num1len = ft_strlen((num1str = *(argv + 1)));
		sign2 = 1;
		if (argv[2][0] == '-' && (sign2 = -1))
			num2len = ft_strlen((num2str = *(argv + 2) + 1));
		else
			num2len = ft_strlen((num2str = *(argv + 2)));
		if (num1len >= num2len)
			ft_putstr(ft_strrev(infin_add(ft_strrev(num1str), ft_strrev(num2str), num1len, num2len, sign1, sign2)));
		else
			ft_putstr(ft_strrev(infin_add(ft_strrev(num2str), ft_strrev(num1str), num2len, num1len, sign2, sign1)));
		ft_putchar('\n');
	}
	return (0);
}
